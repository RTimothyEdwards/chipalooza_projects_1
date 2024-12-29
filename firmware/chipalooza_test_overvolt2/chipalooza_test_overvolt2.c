#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_test_overvolt2.c:
 *-----------------------------------------------------------
 * Written by Tim Edwards, Efabless Corporation
 * November 28, 2024
 *-----------------------------------------------------------
 *
 * Board-level preparation:
 * 1) connect vccd1 to 1.8V
 * 2) connect vccd2 to 1.8V
 * 3) connect vdda1 to 3.3V
 * 4) connect vdda2 to 3.3V
 * 5) connect GPIO 35 to 3.3V (for biasgen trim)
 *
 * Digilent setup:
 * V+ to vdda1
 * W1 set at constant 1.2V to GPIO 9
 * 1+ to GPIO 13
 * digital channels 0->3 to GPIO 0 and 6->8
 *
 * NOTE:  The digital input bits are not all together
 * because GPIO 5 is used for the UART by default and
 * is strongly pulled high.
 *
 * Firmware preparation:
 * 1) set all GPIOs to analog mode (config_io, above)
 *    except for GPIO 13, which is a user digital output
 * 2) disable all power supplies
 *
 *-----------------------------------------------------------
 * 1st test:  Check overvoltage
 *-----------------------------------------------------------
 *
 * 1) enable power supply for overvoltage detector
 * 2) enable the overvoltage detector
 * 3) enable the overvoltage detector bias (400nA)
 * 4) enable the overvoltage detector bandgap input (1.2V)
 *	(Note:  This needs to be externally supplied)
 * 5) power supply monitor is GPIO 18 (no ESD protection)
 * 6) view digital output from GPIO 13
 *
 * Basic functional test:  Output should go high whenever
 * the vdda1 supply exceeds the default threshold
 *
 * Note that this circuit is powered off of vdda1, which
 * also powers the current bias generator, so it is not
 * possible to decouple the two.
 *
 *-----------------------------------------------------------
 * 2nd test:  Check trim
 *-----------------------------------------------------------
 *
 * Measure at different values of voltage trim.
 *
 * Basic functional test:  Output should go high whenever
 * the vdda1 supply exceeds the threshold set by the trip
 * point.  Use GPIO 8->6, 0 connected to Digilent channels
 * 3->0 to control the 4-bit threshold setting (see code
 * below).
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

    /* For digital input setting trippoint level (low bit) */
    reg_mprj_io_0 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;

    /* Keep SPI functional */
    reg_mprj_io_1 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_2 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    /* For digital input setting trippoint level (upper 3 bits) */
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_7 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_8 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;

    /* For 1.2V input */
    reg_mprj_io_9 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_10 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_11 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_12 = GPIO_MODE_MGMT_STD_ANALOG;

    /* Overvoltage detector digital output is on GPIO 13 */
    reg_mprj_io_13 = GPIO_MODE_USER_STD_OUTPUT;

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
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_28 = GPIO_MODE_USER_STD_ANALOG;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_32 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_33 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_34 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_35 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_36 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_37 = GPIO_MODE_MGMT_STD_ANALOG;
}


void main()
{
    uint8_t vtrip;
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

    // Enable the power switch to the overvoltage detector.
    overvoltage2_powerup();

    // Enable the bias current to the overvoltage detector.
    overvoltage2_bias_enable();

    // Enable the overvoltage detector
    // This also enables the 1.2V bandgap for the overvoltage detector.
    overvoltage2_enable();

    // Set overvoltage trip point
    overvoltage2_set_trippoint(0);

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 13 should be the digital encoding of the state
    // V(vdda1) > V(trip).

    // Proceed with the blink test.  For most measurements,
    // this should not be enabled to keep the digital
    // environment quieter for analog measurements.

    reg_gpio_out = 1; // OFF

    reg_mprj_datal = 0x00000000;
    reg_mprj_datah = 0x00000000;

    vtrip = 0;

    while(1) {

	/* Blink LED */

	reg_gpio_out = 0x0;
	delay(1000000);
	reg_gpio_out = 0x1;
	delay(1000000);

	/* Sample trip point value, applied externally	*/
	/* on GPIO 8->6, 0				*/

	allgpio = reg_mprj_datal;
	value = (allgpio & 0x1) | ((allgpio >> 5) & 0xe);
	if ((uint8_t)value != vtrip) {
	    vtrip = (uint8_t)value;
	    overvoltage2_set_trippoint(vtrip);
	}
    }
}
