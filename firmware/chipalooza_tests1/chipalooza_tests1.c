#include <defs.h>
#include <chipalooza_stubs.h>

/*
 *-----------------------------------------------------------
 * chipalooza_tests1.c:
 *-----------------------------------------------------------
 * Written by Tim Edwards, Efabless Corporation
 * November 22, 2024
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
 * 2) disable all power supplies
 *
 *-----------------------------------------------------------
 * 1st test:  Measure bandgap output
 *-----------------------------------------------------------
 *
 * 1) enable power supply for bandgap
 * 2) power supply monitor is GPIO 19 (no ESD protection)
 * 3) select bandgap output
 * 4) bandgap output (1.2V) should appear on GPIO 34
 *
 * This is a relatively simple test as only one constant
 * value needs to be measured to establish that a number
 * of things are working:
 *
 * 1) The power FET is operating (the 1.8V supply appears at
 *    the monitor point).
 * 2) The digital control signals are operating correctly
 * 3) The analog switches are operating correctly
 * 4) The bandgap itself is working correctly
 *
 * For the first cut at this routine, GPIO 1 to 4 will be put
 * in an analog state.  After making sure that the analog
 * signals on these pins will not interfere with SPI operation
 * (they shouldn't, except for a handful of tests), the SPI
 * should be re-established so that the chip does not need to
 * be power-cycled with the reset held down to reprogram it.
 *
 *-----------------------------------------------------------
 * 2nd test: Enable the 5uA test sink current
 *-----------------------------------------------------------
 *
 * 1) Enable power to the bias generator and test bias
 * 2) Enable test bias output
 * 3) Read 5uA test sink current at GPIO 9 (between pin and 3.3V)
 *
 *-----------------------------------------------------------
 * 3rd test: Enable the 3.7uA test sink current
 *-----------------------------------------------------------
 *
 * 1) Enable power to the bias generator and test bias
 * 2) Enable test bias output
 * 3) Read 3.7uA test sink current at GPIO 12 (between pin and 3.3V)
 *
 *-----------------------------------------------------------
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
    reg_mprj_io_2 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_3 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_4 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_5 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_6 = GPIO_MODE_MGMT_STD_ANALOG;
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
    reg_mprj_io_25 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_26 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_27 = GPIO_MODE_MGMT_STD_ANALOG;
    reg_mprj_io_28 = GPIO_MODE_MGMT_STD_ANALOG;
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

    // Enable the power switch to the bandgap
    bandgap_powerup();

    // Enable the output multiplexer for the bandgap
    bandgap_select_output();

    // Set bandgap trim
    bandgap_set_trim(0);

    // That's all!  Now if the LED on the board is blinking,
    // GPIO 19 should read 1.8V and GPIO 34 should read 1.2V.

    // Test bias generator 5uA output.
    biasgen_sink_test_5000_enable();
    biasgen_sink_test_5000_enable_output();

    // A 5uA current sink should now be active on GPIO 8

    // Test bias generator 3.7uA output.
    biasgen_sink_test_3700_enable();
    biasgen_sink_test_3700_enable_output();

    // A 3.7uA current sink should now be active on GPIO 12

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
