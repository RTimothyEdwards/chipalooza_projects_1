/* Utility functions for the chipalooza_testchip1 */

#include "chipalooza_defs.h"

/* Project enables.  Select a project.  Projects are individually
 * enabled or disabled.
 */

/*----------------------------------------------------------------------*/
/* Bandgap								*/
/*									*/
/* Note that there is no separate enable for the bandgap.  Enable and	*/
/* disable it by powering up and powering down.				*/
/*----------------------------------------------------------------------*/

void bandgap_powerup()
{
    reg_la1_data &= ~NENA_BANDGAP_PWR;
}

void bandgap_powerdown()
    reg_la1_data |= NENA_BANDGAP_PWR;
    }
}

void bandgap_select_output()
{
    /* Multiplex bandgap output to GPIO 34 */
    reg_la0_data |= SEL_BANDGAP_OUT;
}

void set_bandgap_trim(uint16_t value)
{
    uint32_t maskval;

    /* Note:  bandgap trim bits are in scrambled order
     * 9 8 10 7 11 6 12 5 13 4 14 3 15 2 16 1
     */

    /* hysteresis bits are backwards with low bit first */

    maskval  = (((uint32_t)value & 0x0001) >>  0) << 1;
    maskval |= (((uint32_t)value & 0x0002) >>  1) << 16;
    maskval |= (((uint32_t)value & 0x0004) >>  2) << 2;
    maskval |= (((uint32_t)value & 0x0008) >>  3) << 15;
    maskval |= (((uint32_t)value & 0x0010) >>  4) << 3;
    maskval |= (((uint32_t)value & 0x0020) >>  5) << 14;
    maskval |= (((uint32_t)value & 0x0040) >>  6) << 4;
    maskval |= (((uint32_t)value & 0x0080) >>  7) << 13;
    maskval |= (((uint32_t)value & 0x0100) >>  8) << 5;
    maskval |= (((uint32_t)value & 0x0200) >>  9) << 12;
    maskval |= (((uint32_t)value & 0x0400) >> 10) << 6;
    maskval |= (((uint32_t)value & 0x0800) >> 11) << 11;
    maskval |= (((uint32_t)value & 0x1000) >> 12) << 7;
    maskval |= (((uint32_t)value & 0x2000) >> 13) << 10;
    maskval |= (((uint32_t)value & 0x4000) >> 14) << 8;
    maskval |= (((uint32_t)value & 0x8000) >> 15) << 9;

    reg_la0_data &= ~BANDGAP_TRIM_MASK;
    reg_la0_data |= maskval;
}

/*----------------------------------------------------------------------*/
/* HSXO									*/
/*									*/
/* Note that the HSXO requires a continuous bias current.		*/
/*----------------------------------------------------------------------*/

void hsxo_powerup()
{
    reg_la1_data &= ~NENA_HSXO_PWR;
}

void hsxo_powerdown()
{
    reg_la1_data |= NENA_HSXO_PWR;
}
	
void hsxo_enable()
{
    reg_la0_data |= HSXO_ENABLE;
}

void hsxo_disable()
{
    reg_la0_data &= ~HSXO_ENABLE;
}

void hsxo_run()
{
    reg_la0_data &= ~HSXO_STANDY;
}

void hsxo_standby()
{
    reg_la0_data |= HSXO_STANDY;
}

void hsxo_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_HSXO_BIAS;
}

void hsxo_bias_disable()
{
    reg_la1_data |= NENA_HSXO_BIAS;
}

/*----------------------------------------------------------------------*/
/* LSXO									*/
/*----------------------------------------------------------------------*/

void lsxo_powerup()
{
    reg_la2_data &= ~NENA_LSXO_PWR;
}

void lsxo_powerdown()
{
    reg_la2_data |= NENA_LSXO_PWR;
}
	
void lsxo_enable()
{
    reg_la0_data |= LSXO_ENABLE;
}

void lsxo_disable()
{
    reg_la0_data &= ~LSXO_ENABLE;
}

void lsxo_run()
{
    reg_la0_data &= ~LSXO_STANDY;
}

void lsxo_standby()
{
    reg_la0_data |= LSXO_STANDY;
}

void lsxo_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_LSXO_BIAS;
}

void lsxo_bias_disable()
{
    reg_la1_data |= NENA_LSXO_BIAS;
}

/*----------------------------------------------------------------------*/
/* LP OPAMP								*/
/*									*/
/* NOTE:  The low-power op-amp's inputs are multiplexed			*/
/*----------------------------------------------------------------------*/

void lp_opamp_powerup()
{
    reg_la1_data &= ~NENA_LPAMP_PWR;
}

void lp_opamp_powerdown()
{
    reg_la1_data |= NENA_LPAMP_PWR;
}
	
void lp_opamp_enable()
{
    reg_la0_data |= LPAMP_ENABLE;
}

void lp_opamp_disable()
{
    reg_la0_data &= ~LPAMP_ENABLE;
}

void lp_opamp_enable_inputs()
{
    reg_la0_data &= ~NSEL_LPAMP_INP;
    reg_la0_data &= ~NSEL_LPAMP_INN;
}

void lp_opamp_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_LPAMP_BIAS;
}

void lp_opamp_bias_disable()
{
    reg_la1_data |= NENA_LPAMP_BIAS;
}

/*----------------------------------------------------------------------*/
/* COMPARATOR								*/
/*									*/
/* NOTE:  The comparator's inputs are multiplexed			*/
/*----------------------------------------------------------------------*/

void comparator_powerup()
{
    reg_la1_data &= ~NENA_COMP_PWR;
}

void comparator_powerdown()
{
    reg_la1_data |= NENA_COMP_PWR;
}
	
void comparator_enable()
{
    reg_la0_data |= COMP_ENABLE;
}

void comparator_disable()
{
    reg_la0_data &= ~COMP_ENABLE;
}

void comparator_enable_inputs()
{
    reg_la0_data &= ~NSEL_COMP_INP;
    reg_la0_data &= ~NSEL_COMP_INN;
}

void comparator_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_COMP_BIAS;
}

void comparator_bias_disable()
{
    reg_la1_data |= NENA_COMP_BIAS;
}

void comparator_set_hyst(uint8_t value)
{
    uint32_t maskval;

    /* hysteresis bits are backwards with low bit first */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 30;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 29;

    reg_la0_data &= ~COMP_HYST_MASK;
    reg_la0_data |= maskval;
}

void comparator_set_trim(uint8_t value)
{
    uint32_t maskval;
 
    /* trim values are scrambled and are in order la_data_in
     * 25, 26, 27, 33, 32, 31
     * which is reg_la0_data 25, 26, 27; reg_la1_data 1, 0; reg_la0_data 31.
     * masks COMP_TRIM_MASK_L, COMP_TRIM_MASK_H, and COMP_TRIM_MASK_M.
     */

    maskval  = (((uint32_t)value & 0x20) >> 5) << 25;
    maskval |= (((uint32_t)value & 0x10) >> 4) << 26;
    maskval |= (((uint32_t)value & 0x8)  >> 3) << 27;
    reg_la0_data &= ~COMP_TRIM_MASK_L;
    reg_la0_data |= maskval;

    maskval = ((uint32_t)value & 0x6) >> 1;
    reg_la1_data &= ~COMP_TRIM_MASK_H;
    reg_la1_data |= maskval;

    maskval = ((uint32_t)value & 0x1) << 31;
    reg_la0_data &= ~COMP_TRIM_MASK_M;
    reg_la0_data |= maskval;
}

/*----------------------------------------------------------------------*/
/* TEMPERATURE SENSOR							*/
/*									*/
/* Note that the temperature sensor outputs are multiplexed.		*/
/* Also note that the temp sensor is biased by 1.2V which needs to be	*/
/* applied at GPIO 9.							*/
/*----------------------------------------------------------------------*/

void tempsense_powerup()
{
    reg_la1_data &= ~NENA_TEMP_PWR;
}

void tempsense_powerdown()
{
    reg_la1_data |= NENA_TEMP_PWR;
}
	
void tempsense_enable()
{
    reg_la1_data |= TEMP_ENABLE;
    reg_la3_data |= SEL_1P2_BIAS;
}

void tempsense_disable()
{
    reg_la1_data &= ~TEMP_ENABLE;
}

void tempsense_enable_outputs()
{
    reg_la1_data &= ~NSEL_TEMP_VBE1;
    reg_la1_data &= ~NSEL_TEMP_VBE2;
}

/*----------------------------------------------------------------------*/
/* HGBW OPAMP								*/
/*----------------------------------------------------------------------*/

void hgbw_opamp_powerup()
{
    reg_la1_data &= ~NENA_HGBWAMP_PWR;
}

void hgbw_opamp_powerdown()
{
    reg_la1_data |= NENA_HGBWAMP_PWR;
}
	
void hgbw_opamp_enable()
{
    reg_la1_data |= HGBWAMP_ENABLE;
}

void hgbw_opamp_disable()
{
    reg_la1_data &= ~HGBWAMP_ENABLE;
}

void hgbw_opamp_enable_inputs()
{
    reg_la1_data |= SEL_HGBWAMP_INP;
    reg_la1_data |= SEL_HGBWAMP_INN;
}

void hgbw_opamp_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_HGBWAMP_BIAS;
}

void hgbw_opamp_bias_disable()
{
    reg_la1_data |= NENA_HGBWAMP_BIAS;
}

/*----------------------------------------------------------------------*/
/* OVERVOLTAGE DETECTOR 2						*/
/*----------------------------------------------------------------------*/

void overvoltage2_powerup()
{
    reg_la2_data &= ~NENA_OV2_PWR;
}

void overvoltage2_powerdown()
{
    reg_la2_data |= NENA_OV2_PWR;
}
	
void overvoltage2_enable()
{
    reg_la1_data |= OV2_ENABLE;
    reg_la3_data |= SEL_1P2_BIAS;
}

void overvoltage2_disable()
{
    reg_la1_data &= ~OV2_ENABLE;
}

void overvoltage2_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_OV2_BIAS;
}

void overvoltage2_bias_disable()
{
    reg_la1_data |= NENA_OV2_BIAS;
}

void overvoltage2_set_trippoint(uint8_t value)
{
    uint32_t maskval;

    /* Overvoltage trip point mask bits are in backwards order */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 26;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 25;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 24;
    maskval |= (((uint32_t)value & 0x8) >>  3) << 23;

    reg_la2_data &= ~OV2_TRIP_MASK;
    reg_la2_data |= maskval;
}

/*----------------------------------------------------------------------*/
/* POWER ON RESET							*/
/*									*/
/* Note that the power-on-reset does not have an enable and is enabled	*/
/* by powering it up or down, or removing the bias.			*/
/*----------------------------------------------------------------------*/

void por_powerup()
{
    reg_la2_data &= ~NENA_POR_PWR;
}

void por_powerdown()
{
    reg_la2_data |= NENA_POR_PWR;
}

void por_vbg_enable()
{
    reg_la3_data &= ~SEL_1P2_BIAS;
}

void por_vbg_disable()
{
    reg_la3_data |= SEL_1P2_BIAS;
}

void por_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_POR_BIAS;
}

void por_bias_disable()
{
    reg_la1_data |= NENA_POR_BIAS;
}

void por_osc_default()
{
    reg_la2_data &= ~POR_RC_DISABLE;
    reg_la2_data &= ~POR_RC_ENABLE;
}

void por_force_osc_on()
{
    reg_la2_data |= POR_RC_ENABLE;
}

void por_force_osc_off()
{
    reg_la2_data |= POR_RC_DISABLE;
}

void por_pdn_default()
{
    reg_la2_data &= ~POR_FORCE_PDN;
}

void por_force_pdn()
{
    reg_la2_data |= POR_FORCE_PDN;
}

void por_select_external_bias()
{
    reg_la2_data |= POR_ISRC_SEL;
}

void por_select_internal_bias()
{
    reg_la2_data &= ~POR_ISRC_SEL;
}

void por_oneshot_mode()
{
    reg_la3_data |= POR_ONESHOT;
}
	
void por_continuous_mode()
{
    reg_la3_data &= ~POR_ONESHOT;
}

void por_set_trippoint(uint8_t value)
{
    uint32_t maskval;

    /* POR trip point mask bits are in backwards order */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 2;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 1;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 0;

    reg_la3_data &= ~POR_TRIP_MASK;
    reg_la3_data |= maskval;
}

uint8_t por_get_timeout()
{
    return ((reg_la3_data & POR_TIMEOUT) == 0) ? 0 : 1;
}
	
uint8_t por_get_startup_timeout()
{
    return ((reg_la3_data & POR_START_TIMEOUT) == 0) ? 0 : 1;
}
	
/*----------------------------------------------------------------------*/
/* OVERVOLTAGE DETECTOR 1						*/
/*----------------------------------------------------------------------*/

void overvoltage1_powerup()
{
    reg_la2_data &= ~NENA_OV1_PWR;
}

void overvoltage1_powerdown()
{
    reg_la2_data |= NENA_OV1_PWR;
}
	
void overvoltage1_enable()
{
    reg_la3_data |= OV1_ENABLE;
    reg_la3_data &= ~SEL_1P2_BIAS;
}

void overvoltage1_disable()
{
    reg_la3_data &= ~OV1_ENABLE;
}

void overvoltage1_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_OV1_BIAS;
}

void overvoltage1_bias_disable()
{
    reg_la1_data |= NENA_OV1_BIAS;
}

void overvoltage1_select_external_bias()
{
    reg_la3_data |= OV1_ISRC_SEL;
}

void overvoltage1_select_internal_bias()
{
    reg_la3_data &= ~OV1_ISRC_SEL;
}

void overvoltage1_set_trippoint(uint8_t value)
{
    uint32_t maskval = ((uint32_t)value & 0xf) << 6;

    reg_la3_data &= ~OV1_TRIP_MASK;
    reg_la3_data |= maskval;
}

/*----------------------------------------------------------------------*/
/* BROWNOUT DETECTOR							*/
/*----------------------------------------------------------------------*/

void brownout_powerup()
{
    reg_la2_data &= ~NENA_BRNOUT_PWR;
}

void brownout_powerdown()
{
    reg_la2_data |= NENA_BRNOUT_PWR;
}
	
void brownout_vbg_enable()
{
    reg_la3_data &= ~SEL_1P2_BIAS;
}

void brownout_vbg_disable()
{
    reg_la3_data |= SEL_1P2_BIAS;
}

void brownout_bias_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_BRNOUT_BIAS;
}

void brownout_bias_disable()
{
    reg_la1_data |= NENA_BRNOUT_BIAS;
}

void brownout_select_external_bias()
{
    reg_la3_data |= BRNOUT_ISRC_SEL;
}

void brownout_select_internal_bias()
{
    reg_la3_data &= ~BRNOUT_ISRC_SEL;
}

void brownout_set_vtrippoint(uint8_t value)
{
    uint32_t maskval;

    /* The brownout trip point mask is scrambled
     * and is in order 107, 106, 108, or reg_la3_data
     * bits 11, 10, 12
     */
    maskval  = (((uint32_t)value & 0x1) >>  0) << 12;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 10;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 11;

    reg_la3_data &= ~BRNOUT_VTRIP_MASK;
    reg_la3_data |= maskval;
}

void brownout_set_otrippoint(uint8_t value)
{
    uint32_t maskval;

    /* The brownout trip point mask is scrambled
     * and is in order 112, 113, 111, or reg_la3_data
     * bits 16, 17, 15
     */
    maskval  = (((uint32_t)value & 0x1) >>  0) << 15;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 17;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 16;

    reg_la3_data &= ~BRNOUT_OTRIP_MASK;
    reg_la3_data |= maskval;
}

void brownout_osc_default()
{
    reg_la3_data &= ~BRNOUT_RC_DISABLE;
    reg_la3_data &= ~BRNOUT_RC_ENABLE;
}

void brownout_force_osc_on()
{
    reg_la3_data |= BRNOUT_RC_ENABLE;
}

void brownout_force_osc_off()
{
    reg_la3_data |= BRNOUT_RC_DISABLE;
}

void brownout_oneshot_mode()
{
    reg_la3_data |= BRNOUT_ONESHOT;
}
	
void brownout_continuous_mode()
{
    reg_la3_data &= ~BRNOUT_ONESHOT;
}

uint8_t brownout_get_timeout()
{
    return ((reg_la3_data & BRNOUT_TIMEOUT) == 0) ? 0 : 1;
}
	
/*----------------------------------------------------------------------*/
/* Bias generator							*/
/*----------------------------------------------------------------------*/

void biasgen_enable()
{
    reg_la2_data |= ENA_BIASGEN;
}

void biasgen_disable()
{
    reg_la2_data &= ~ENA_BIASGEN;
}

void biasgen_sources_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
}

void biasgen_sources_disable()
{
    reg_la1_data |= NENA_SOURCE_BIAS;
}

/*----------------------------------------------------------------------*/
/* Bias generator current source test 0 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_source_test0_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_SRC_TEST0;
}

void biasgen_source_test0_disable()
{
    reg_la1_data |= NENA_SRC_TEST0;
}

void biasgen_source_test0_enable_output()
{
    reg_la1_data &= ~NSEL_SRC_TEST0;
}

void biasgen_source_test0_disable_output()
{
    reg_la1_data |= NSEL_SRC_TEST0;
}

/*----------------------------------------------------------------------*/
/* Bias generator current source test 1 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_source_test1_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la1_data &= ~NENA_SOURCE_BIAS;
    reg_la1_data &= ~NENA_SRC_TEST1;
}

void biasgen_source_test1_disable()
{
    reg_la1_data |= NENA_SRC_TEST1;
}

void biasgen_source_test1_enable_output()
{
    reg_la1_data |= SEL_SRC_TEST1;
}

void biasgen_source_test1_disable_output()
{
    reg_la1_data &= ~SEL_SRC_TEST;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 0 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test0_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la2_data |= ENA_SINK_TEST0;
}

void biasgen_sink_test0_disable()
{
    reg_la2_data &= ~ENA_SINK_TEST0;
}

void biasgen_sink_test0_enable_output()
{
    reg_la3_data |= SEL_SINK_TEST0;
}

void biasgen_sink_test0_disable_output()
{
    reg_la3_data &= ~SEL_SINK_TEST0;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 1 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test1_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la2_data |= ENA_SINK_TEST1;
}

void biasgen_sink_test1_disable()
{
    reg_la2_data &= ~ENA_SINK_TEST1;
}

void biasgen_sink_test1_enable_output()
{
    reg_la3_data |= SEL_SINK_TEST1;
}

void biasgen_sink_test1_disable_output()
{
    reg_la3_data &= ~SEL_SINK_TEST1;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 3.7uA				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test_3700_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la2_data |= ENA_SINK_3700;
}

void biasgen_sink_test1_disable()
{
    reg_la2_data &= ~ENA_SINK_3700;
}

void biasgen_sink_test1_enable_output()
{
    reg_la3_data |= SEL_SINK_3700;
}

void biasgen_sink_test1_disable_output()
{
    reg_la3_data &= ~SEL_SINK_3700;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 5.0uA				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test_3700_enable()
{
    reg_la2_data |= ENA_BIASGEN;
    reg_la2_data |= ENA_SINK_5000;
}

void biasgen_sink_test1_disable()
{
    reg_la2_data &= ~ENA_SINK_5000;
}

void biasgen_sink_test1_enable_output()
{
    reg_la3_data |= SEL_SINK_5000;
}

void biasgen_sink_test1_disable_output()
{
    reg_la3_data &= ~SEL_SINK_5000;
}

/*----------------------------------------------------------------------*/
/* UNUSED POWER SUPPLIES (never enabled)				*/
/*----------------------------------------------------------------------*/

void powerdown_unused()
{
    reg_la1_data |= NENA_UNUSED1_PWR;
    reg_la2_data |= NENA_UNUSED2_PWR | NENA_UNUSED3_PWR;
}

/*----------------------------------------------------------------------*/
/* ALL POWER SUPPLIES (initialization)					*/
/*----------------------------------------------------------------------*/

void powerdown_all()
{
    reg_la1_data |= (NENA_BANDGAP_PWR | NENA_HSXO_PWR | NENA_LPAMP_PWR |
			NENA_COMP_PWR | NENA_TEMP_PWR | NEAN_HGBWAMP_PWR |
			NEAN_UNUSED1_PWR);
			
    reg_la2_data |= (NENA_OV2_PWR | NENA_UNUSED2_PWR | NENA_LXSO_PWR |
			NENA_UNUSED3_PWR | NENA_POR_PWR | NEAN_OV1_PWR |
			NENA_BRNOUT_PWR);
}


