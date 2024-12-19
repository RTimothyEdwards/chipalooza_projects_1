#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_test_overvolt1.c:
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
 *    except for GPIO 6, which is a user digital output,
 *    and GPIO 8 and GPIO 10 to 13, which are management
 *    digital inputs.
 * 2) disable all power supplies
 * 3) Take 1.2V reference from GPIO 9.
 *
 * Map the following digital inputs to project inputs:
 * GPIO 8	isrc select
 * (GPIO 9	1.2V reference)
 * GPIO 10	trip 0 
 * GPIO 11	trip 1
 * GPIO 12	trip 2
 * GPIO 13	trip 3
 *
 * For debugging, the following GPIOs are set to duplicate
 * the trip point setting back to GPIO 25-28
 * 
 * GPIO 25	trip 0 
 * GPIO 26	trip 1
 * GPIO 27	trip 2
 * GPIO 28	trip 3
 *
 *-----------------------------------------------------------
 * 1st test:  Check overvoltage detector
 *-----------------------------------------------------------
 *
 * 1) enable power supply for overvoltage detector
 * 2) enable the overvoltage detector
 * 3) enable the overvoltage detector bias (200nA)
 * 4) power supply monitor is GPIO 15 (no ESD protection)
 * 5) view digital output from GPIO 6
 *
 * Basic functional test:  Output should go high whenever
 * the vdda1 power supply exceeds the specified trip point.
 *
 *-----------------------------------------------------------
 * 1st test:  Check overvoltage detector
 *-----------------------------------------------------------
 *
 * Measure at different values of trip points, and check
 * operation with internal and external bias.
 *
 * Program:  Use digital input pins to set trip point and
 * select current bias.
 * Current bias select: (1 bit) on GPIO 11.  Set GPIO to be a
 * pull-down input, then control value from the Digilent.
 * The program periodically samples the value and applies it
 * to the logic analyzer.
 *
 * Trim: (4 bits) on GPIO 7 to GPIO 10.  Same as above
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

    /* Keep SPI functional */
    reg_mprj_io_1 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_2 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_6 = GPIO_MODE_USER_STD_OUTPUT;
    reg_mprj_io_7 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_8 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_9 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_10 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_11 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_12 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
    reg_mprj_io_13 = GPIO_MODE_MGMT_STD_INPUT_PULLDOWN;
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
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_OUTPUT;
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
    uint8_t isel, trip;
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

    // Enable the power switch to the overvoltage detector
    overvoltage1_powerup();

    // Enable the bias current to the overvoltage detector
    overvoltage1_bias_enable();

    // Enable the overvoltage detector
    overvoltage1_enable();

    // Set overvoltage detector trip point
    overvoltage1_set_trippoint(0);

    // Set overvoltage detector current source select
    overvoltage1_select_internal_bias();

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 6 should be the digital encoding of the state
    // vdda1 > (trip point).

    // Proceed with the blink test.  For most measurements,
    // this should not be enabled to keep the digital
    // environment quieter for analog measurements.

    reg_gpio_out = 1; // OFF

    reg_mprj_datal = 0x00000000;
    reg_mprj_datah = 0x00000000;

    isel = 0;
    trip = 0;

    while(1) {

	/* Blink LED */

	reg_gpio_out = 0x0;
	delay(1000000);
	reg_gpio_out = 0x1;
	delay(1000000);

	/* Sample current source select value, applied externally */
	/* on GPIO 8						  */

	allgpio = reg_mprj_datal;
        value = ((allgpio >> 8) & 0x1);
	if (value != isel) {
	    isel = value;
	    if (isel == 1)
		overvoltage1_select_external_bias();
	    else
		overvoltage1_select_internal_bias();
	}

	/* Sample trip point value, applied externally on GPIO 13->10 */

	value = ((allgpio >> 10) & 0xf);
	if (value != trip) {
	    trip = value;
	    overvoltage1_set_trippoint(trip);

	    /* sanity check */
	    reg_mprj_datal = trip << 25;
	}
    }
}
