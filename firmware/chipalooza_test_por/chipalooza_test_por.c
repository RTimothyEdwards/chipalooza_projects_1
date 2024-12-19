#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_test_por.c:
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
 *    except for GPIO 2, 3, 4, 7, and 8, which are user
 *    digital outputs, and GPIO 25 to 32, which
 *    are management digital inputs.
 * 2) additionally, GPIO 33 and 34 are set as management
 *    digital outputs.
 * 3) disable all power supplies
 * 4) Take 1.2V reference from GPIO 9.
 *
 * These GPIOs are direct project outputs:
 * GPIO 2	dcomp
 * GPIO 3	osc clock
 * GPIO 4	powerup filt
 * GPIO 7	POR out
 * GPIO 8	POR !out
 *
 * Map the following digital inputs to project inputs:
 * GPIO 25	isrc select
 * GPIO 26	trip 0 
 * GPIO 27	trip 1
 * GPIO 28	trip 2
 * GPIO 29	force power-down
 * GPIO 30	force enable RC osc
 * GPIO 31	force disable RC osc
 * GPIO 32	force short one-shot
 *
 * Map the following project outputs to digital outputs:
 * 
 * GPIO 33	startup timed out
 * GPIO 34	POR timed out
 *
 *-----------------------------------------------------------
 * 1st test:  Check POR
 *-----------------------------------------------------------
 *
 * 1) enable the POR bias (200nA)
 * 2) power supply monitor is GPIO 16 (no ESD protection)
 * 3) view digital output from GPIOs 7 and 8
 * 4) enable power supply for POR
 *
 * Basic functional test:  Output should generate a pulse
 * when the power supply comes up and the vdda1 power supply
 * reaches the specified trip point.
 *
 * Note that there is no POR enable signal.  The POR is
 * enabled by enabling its bias current and power supply.
 *
 *-----------------------------------------------------------
 * 1st test:  Check POR
 *-----------------------------------------------------------
 *
 * Measure at different values of trip points, and check
 * operation with internal and external bias.
 *
 * Measure at different ramp rates of the power supply.
 *
 * There are multiple scenarios with either the digital or
 * the analog supply being raised first.  The POR is designed
 * to respond to the analog (vdda1) supply.
 *
 * Program:  Use digital input pins to set trip point,
 * select current bias, and set circuit options..
 *
 * Current bias select: (1 bit) on GPIO 25.  Set GPIO to be a
 * pull-down input, then control value from the Digilent.
 * The program periodically samples the value and applies it
 * to the logic analyzer.
 *
 * Trim: (3 bits) on GPIO 26 to GPIO 28.  Same as above
 * Force power-down (1 bit) on GPIO 29.
 * Force enable RC oscillator (1 bit) on GPIO 30
 * Force disable RC oscillator (1 bit) on GPIO 31
 * Force short one-shot (1 bit) on GPIO 32
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

    reg_mprj_io_0 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_1 = GPIO_MODE_MGMT_STD_ANALOG;

    /* NOTE:  SPI is not functional due to use of
     * SPI GPIO pins being used by the user project.
     * Reprogramming the flash requires reset + power
     * cycle.
     */
    reg_mprj_io_2 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_3 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_4 = GPIO_MODE_USER_STD_OUTPUT;

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_ANALOG;

    reg_mprj_io_7 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_8 = GPIO_MODE_USER_STD_OUTPUT;

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

    reg_mprj_io_33 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_34 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_35 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_36 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_37 = GPIO_MODE_MGMT_STD_ANALOG;
}


void main()
{
    uint8_t isel, trip, osc, pdn_on, oneshot;
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

    // Enable the power switch to the POR
    por_powerup();

    // Enable the reference voltage to the POR
    por_vbg_enable();

    // Enable the bias current to the POR
    por_bias_enable();

    // Set the default oscillator mode
    por_osc_default();

    // Set the default powerdown mode
    por_pdn_default();

    // Set POR trip point
    por_set_trippoint(0);

    // Set POR current source select
    por_select_internal_bias();

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 7 and 8 should be the digital encoding of the
    // POR pulse when vdda1 is raised.

    // Proceed with the blink test.  For most measurements,
    // this should not be enabled to keep the digital
    // environment quieter for analog measurements.

    reg_gpio_out = 1; // OFF

    reg_mprj_datal = 0x00000000;
    reg_mprj_datah = 0x00000000;

    isel = 0;
    trip = 0;
    osc = 0;
    pdn_on = 0;
    oneshot = 0;

    while(1) {

	/* Blink LED */

	reg_gpio_out = 0x0;
	delay(1000000);
	reg_gpio_out = 0x1;
	delay(1000000);

	/* Sample current source select value, applied externally */
	/* on GPIO 25						  */

	allgpio = reg_mprj_datal;
        value = ((allgpio >> 25) & 0x1);
	if (value != isel) {
	    isel = value;
	    if (isel == 1)
		por_select_external_bias();
	    else
		por_select_internal_bias();
	}

	/* Sample trip point value, applied externally on GPIO 28->26 */

	value = ((allgpio >> 24) & 0x7);
	if (value != trip) {
	    trip = value;
	    por_set_trippoint(trip);
	}

	/* Sample options on GPIO 29 to 32 */

	value = ((allgpio >> 29) & 0x1);
	if (value != pdn_on) {
	    pdn_on = value;
	    if (pdn_on == 1)
		por_force_pdn();
	    else
		por_pdn_default();
	}

	/* Note: both R-C osc force off and force on disallowed. */
	value = ((allgpio >> 30) & 0x3);
	if (value != osc) {
	    osc = value;
	    if (osc == 1)
		por_force_osc_on();
	    else if (osc == 2)
		por_force_osc_off();
	    else
		por_osc_default();
	}

	/* Read back timeout values and apply to GPIO 33 and 34 */
	/* NOTE:  Faster response time requires sampling more than
	 * once per blink cycle.
	 */
	value = por_get_timeout() << 1;
	value |= por_get_startup_timeout();
	reg_mprj_datah = value << 1;
    }
}
