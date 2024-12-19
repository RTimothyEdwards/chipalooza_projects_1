#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_test_hsxo.c:
 *-----------------------------------------------------------
 * Written by Tim Edwards, Efabless Corporation
 * November 27, 2024
 *-----------------------------------------------------------
 *
 * Board-level preparation:
 * 1) connect vccd1 to 1.8V
 * 2) connect vccd2 to 1.8V
 * 3) connect vdda1 to 3.3V
 * 4) connect vdda2 to 3.3V
 * 5) connect GPIO 35 to 0.3V (for biasgen trim)*
 * (0.3V is just a guess.  Bias current is 100x too high and
 *  needs to be brought down;  at 0.85V, the current is at
 *  1/10 the nominal value, but the current drops off sharply
 *  below this voltage.
 *
 * Firmware preparation:
 * 1) set all GPIOs to analog mode (config_io, above)
 *    except for GPIO 34, which is a user digital output
 * 2) disable all power supplies
 *
 *-----------------------------------------------------------
 * 1st test:  Check HSXO
 *-----------------------------------------------------------
 *
 * 1) enable power supply for the HSXO
 * 2) enable the HSXO
 * 3) enable the HSXO bias (10uA) ***
 * 4) enable the op amp inputs
 * 5) power supply monitor is GPIO 21 (no ESD protection)
 * 6) drive inputs to the op amp on GPIO 29 (negative)
 *    and GPIO 30 (positive)
 * 7) view analog output on GPIO 31
 *
 * Basic functional test:  Output should follow the
 * differential input with measurable gain.
 *
 * NOTE:  This is an error.  The HSXO does not take 10uA bias
 * but rather 100nA, so needs to be a factor of 100 lower.
 * This maybe (?) can be achieved by lowering the voltage
 * at the bias generator trim (GPIO 35).
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

    /* Keep the SPI functional */
    reg_mprj_io_1 = GPIO_MODE_MGMT_STD_OUTPUT;
    reg_mprj_io_2 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_INPUT_NOPULL;

    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_7 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_8 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_9 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_10 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_11 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_12 = GPIO_MODE_USER_STD_OUTPUT;
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
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_29 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_30 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_31 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_32 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_33 = GPIO_MODE_MGMT_STD_ANALOG;

    /* HSXO digital output on GPIO 34 */
    reg_mprj_io_34 = GPIO_MODE_USER_STD_OUTPUT;

    reg_mprj_io_35 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_36 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_37 = GPIO_MODE_MGMT_STD_ANALOG;
}


void main()
{
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

    // Enable the power switch to the HSXO
    hsxo_powerup();

    // Enable the bias current to the HSXO
    // WARNING:  The bias to the HSXO is much too large and
    // needs to be taken down a huge amount by applying a
    // very low voltage at pin GPIO 35.
    hsxo_bias_enable();

    // Enable the hsxo in standby mode
    hsxo_standby();
    hsxo_enable();

    // Start the HSXO running
    hsxo_run();

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 23 should be the (digital) output

    // Xin/Xout are GPIO 32 and 33.  For a quick test, it should
    // be possible to drive these pins with a low-amplitude sine
    // wave at 4 to 16 MHz.

    // To do:  Allow external control of enable and standby

    // Proceed with the blink test.  For most measurements,
    // this should not be enabled to keep the digital
    // environment quieter for analog measurements.

    reg_gpio_out = 1; // OFF

    while(1) {

	reg_mprj_datal = 0x00000000;
	reg_mprj_datah = 0x00000000;

	reg_gpio_out = 0x0;

	delay(1000000);

	reg_mprj_datal = 0xffffffff;
	reg_mprj_datah = 0xffffffff;

	reg_gpio_out = 0x1;

	delay(1000000);
    }
}
