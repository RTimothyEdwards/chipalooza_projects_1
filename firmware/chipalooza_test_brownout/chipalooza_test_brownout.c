#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_test_brownout.c:
 *-----------------------------------------------------------
 * Written by Tim Edwards, Efabless Corporation
 * December 11, 2024
 *-----------------------------------------------------------
 *
 * Board-level preparation:
 * 1) connect vccd1 to 1.8V
 * 2) connect vccd2 to 1.8V
 * 3) connect vdda1 to 3.3V
 * 4) connect vdda2 to 3.3V
 * 5) connect GPIO 35 to 3.3V (for biasgen trim)
 *
 * Firmware preparation:
 * 1) set all GPIOs to analog mode (config_io, above)
 *    except for GPIO 0, 1, and 5,  which is are user
 *    digital outputs, and GPIO 25 to 33, which are
 *    management digital inputs.  Note that use of
 *    GPIO 1 as an output prevents use of the SPI, so
 *    reset w/power cycling is required to re-program
 *    the flash.
 * 2) disable all power supplies
 * 3) Take 1.2V reference from GPIO 9.
 *
 * Map the following digital inputs to project inputs:
 * GPIO 25	otrip 0
 * GPIO 26	otrip 1 
 * GPIO 27	otrip 2
 * GPIO 28	vtrip 0
 * GPIO 29	vtrip 1
 * GPIO 30	vtrip 2
 * GPIO 31	isel
 * GPIO 32	force rc on
 * GPIO 33	force rc off
 * GPIO 34	one-shot mode
 * GPIO 36	timeout (digital output)
 *
 *-----------------------------------------------------------
 * 1st test:  Check brownout detector
 *-----------------------------------------------------------
 *
 * 1) enable power supply for brownout detector
 * 2) enable the brownout detector
 * 3) enable the brownout detector bias (200nA)
 * 4) power supply monitor is GPIO 14 (no ESD protection)
 * 5) view digital outputs from GPIO 0 (main output),
 *    GPIO 1 (dcomp), and GPIO 2 (vunder)
 *
 * Basic functional test:  Output should go high (low?)
 * whenever the vdda1 power supply is less than the
 * specified trip point.  There are two trip points
 * corresponding to two different outputs.
 *
 *-----------------------------------------------------------
 * 1st test:  Check brownout detector
 *-----------------------------------------------------------
 *
 * Measure at different values of trip points, and check
 * operation with internal and external bias.
 *
 * Program:  Use digital input pins to set trip point and
 * select current bias.
 * Current bias select: (1 bit) on GPIO 31.  Set GPIO to be a
 * pull-down input, then control value from the Digilent.
 * The program periodically samples the value and applies it
 * to the logic analyzer.
 *
 * All other digital inputs are treated similarly:
 *
 * Main output trip point: (3 bits) on GPIO 25 to GPIO 27.
 * vunder output trip point: (3 bits) on GPIO 28 to 30.
 *
 * Force RC oscillator always on: (1 bit) GPIO 32
 * Force RC oscillator always off: (1 bit) GPIO 33
 *
 * Capture timed-out signal from la_data_out[117]
 * and output on GPIO 34.
 *
 * One-shot and continuous mode triggers on GPIO 36 and
 * GPIO 37, respectively.
 *
 */

// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

void delay(const int d)
{
    /* Configure timer for a single-shot countdown */
    reg_timer0_config = 0;
    reg_timer0_data = d;
    reg_timer0_config = 1;

    // Loop, waiting for value to reach zero
    reg_timer0_update = 1;  // latch current value
    while (reg_timer0_value > 0) {
	reg_timer0_update = 1;
    }
}

void config_io() {

    reg_mprj_io_0 = GPIO_MODE_USER_STD_OUTPUT;

    /* NOTE: SPI is not functional! */
    reg_mprj_io_1 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_2 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_6 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_7 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_8 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_9 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_10 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_11 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_12 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_13 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_14 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_15 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_16 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_17 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_18 = GPIO_MODE_MGMT_STD_ANALOG;

    reg_mprj_io_19 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_20 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_21 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_22 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_23 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_24 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_32 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_33 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_34 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_35 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_36 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_37 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
}


void main()
{
    uint8_t isel, otrip, vtrip, oneshot, timeout;
    uint32_t value, allgpio;

    reg_gpio_mode1 = 1;
    reg_gpio_mode0 = 0;
    reg_gpio_ien = 1;
    reg_gpio_oe = 1;

    reg_mprj_datah = 0;
    reg_mprj_datal = 0;

    config_io();

    reg_mprj_xfer = 1;
    while (reg_mprj_xfer == 1);

    // Initialize controls into the user project through the
    // logic analyzer interface.  This routine also powers down
    // all of the power switches.

    init_logic_analyzer();

    // Enable the power switch to the brownout detector
    brownout_powerup();

    // Enable the 1.2V reference voltage to the brownout detector
    brownout_vbg_enable();

    // Enable the bias current to the brownout detector
    brownout_bias_enable();

    // Set brownout detector 1st trip point
    brownout_set_otrippoint(0);

    // Set brownout detector 2nd trip point
    brownout_set_vtrippoint(0);

    // Set brownout detector current source select
    brownout_select_internal_bias();

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 0 should be the digital encoding of the state
    // vdda1 < (otrip point).

    // Proceed with the blink test.  For most measurements,
    // this should not be enabled to keep the digital
    // environment quieter for analog measurements.

    reg_gpio_out = 1; // OFF

    reg_mprj_datal = 0x00000000;
    reg_mprj_datah = 0x00000000;

    isel = 0;
    otrip = 0;
    vtrip = 0;

    while(1) {

	/* Blink LED */

	reg_gpio_out = 0x0;
	delay(1000000);
	reg_gpio_out = 0x1;
	delay(1000000);

	/* Sample current source select value, applied externally */
	/* on GPIO 31						  */

	allgpio = reg_mprj_datal;
        value = ((allgpio >> 31) & 0x1);
	if (value != isel) {
	    isel = value;
	    if (isel == 1)
		brownout_select_external_bias();
	    else
		brownout_select_internal_bias();
	}

	/* Sample 1st trip point value, applied externally on GPIO 27->25 */

	value = ((allgpio >> 25) & 0x7);
	if (value != otrip) {
	    otrip = value;
	    brownout_set_otrippoint(otrip);
	}

	/* Sample 2nd trip point value, applied externally on GPIO 30->28 */

	value = ((allgpio >> 28) & 0x7);
	if (value != vtrip) {
	    vtrip = value;
	    brownout_set_otrippoint(vtrip);
	}

	/* Sample one-shot mode, applied externally on GPIO 34 */
	allgpio = reg_mprj_datah;
	value = ((allgpio >> 2) & 0x1);
	if (value != oneshot) {
	    oneshot = value;
	    if (oneshot == 1)
		brownout_oneshot_mode();
	    else
		brownout_continuous_mode();
	}

	/* Sample timeout, and apply externally to GPIO 36 */
	value = brownout_get_timeout();
	if (value != timeout) {
	    timeout = value;
	    reg_mprj_datah = (timeout & 0x1) << 4;
	}
    }
}
