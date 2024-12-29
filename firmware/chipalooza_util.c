/*------------------------------------------------*/
/* Utility functions for the chipalooza_testchip1 */
/*------------------------------------------------*/
/* Written by Tim Edwards, Efabless		  */
/* November 22, 2024				  */
/*------------------------------------------------*/

#include "defs.h"
#include "chipalooza_defs.h"

/* Project enables.  Select a project.  Projects are individually
 * enabled or disabled.
 */

/* Implementation note:  The RISC-V compiler is unable to perform
 * logical/arithmetic operations in place on a memory mapped locations,
 * so "reg_la1_data |= VALUE" is invalid and must be written as
 * "value = reg_la1_data | VALUE; reg_la1_data = value".
 */

/*----------------------------------------------------------------------*/
/* Bandgap								*/
/*									*/
/* Note that there is no separate enable for the bandgap.  Enable and	*/
/* disable it by powering up and powering down.				*/
/*----------------------------------------------------------------------*/

void bandgap_powerup()
{
    uint32_t value;

    value = reg_la1_data & ~NENA_BANDGAP_PWR;
    reg_la1_data = value;
}

void bandgap_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_BANDGAP_PWR;
    reg_la1_data = value;
}

void bandgap_select_output()
{
    uint32_t value;

    /* Multiplex bandgap output to GPIO 34 */
    value = reg_la0_data | SEL_BANDGAP_OUT;
    reg_la0_data = value;
}

void bandgap_set_trim(uint16_t value)
{
    uint32_t ovalue;
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

    ovalue = reg_la0_data & ~BANDGAP_TRIM_MASK;
    ovalue |= maskval;
    reg_la0_data = ovalue;
}

/*----------------------------------------------------------------------*/
/* HSXO									*/
/*									*/
/* Note that the HSXO requires a continuous bias current.		*/
/*----------------------------------------------------------------------*/

void hsxo_powerup()
{
    uint32_t value;

    value = reg_la1_data & ~NENA_HSXO_PWR;
    reg_la1_data = value;
}

void hsxo_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_HSXO_PWR;
    reg_la1_data = value;
}
	
void hsxo_enable()
{
    uint32_t value;

    value = reg_la0_data | HSXO_ENABLE;
    reg_la0_data = value;
}

void hsxo_disable()
{
    uint32_t value;

    value = reg_la0_data & ~HSXO_ENABLE;
    reg_la0_data = value;
}

void hsxo_run()
{
    uint32_t value;

    value = reg_la0_data & ~HSXO_STANDBY;
    reg_la0_data = value;
}

void hsxo_standby()
{
    uint32_t value;

    value = reg_la0_data | HSXO_STANDBY;
    reg_la0_data = value;
}

void hsxo_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_HSXO_BIAS;
    reg_la1_data = value;
}

void hsxo_bias_disable()
{
    uint32_t value;

    value = reg_la1_data = NENA_HSXO_BIAS;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* LSXO									*/
/*----------------------------------------------------------------------*/

void lsxo_powerup()
{
    uint32_t value;

    value = reg_la2_data & ~NENA_LSXO_PWR;
    reg_la2_data = value;
}

void lsxo_powerdown()
{
    uint32_t value;

    value = reg_la2_data | NENA_LSXO_PWR;
    reg_la2_data = value;
}
	
void lsxo_enable()
{
    uint32_t value;

    value = reg_la0_data | LSXO_ENABLE;
    reg_la0_data = value;
}

void lsxo_disable()
{
    uint32_t value;

    value = reg_la0_data & ~LSXO_ENABLE;
    reg_la0_data = value;
}

void lsxo_run()
{
    uint32_t value;

    value = reg_la0_data & ~LSXO_STANDBY;
    reg_la0_data = value;
}

void lsxo_standby()
{
    uint32_t value;

    value = reg_la0_data | LSXO_STANDBY;
    reg_la0_data = value;
}

void lsxo_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_LSXO_BIAS;
    reg_la1_data = value;
}

void lsxo_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_LSXO_BIAS;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* LP OPAMP								*/
/*									*/
/* NOTE:  The low-power op-amp's inputs are multiplexed			*/
/*----------------------------------------------------------------------*/

void lp_opamp_powerup()
{
    uint32_t value;

    value = reg_la1_data & ~NENA_LPAMP_PWR;
    reg_la1_data = value;
}

void lp_opamp_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_LPAMP_PWR;
    reg_la1_data = value;
}
	
void lp_opamp_enable()
{
    uint32_t value;

    value = reg_la0_data | LPAMP_ENABLE;
    reg_la0_data = value;
}

void lp_opamp_disable()
{
    uint32_t value;

    value = reg_la0_data & ~LPAMP_ENABLE;
    reg_la0_data = value;
}

void lp_opamp_enable_inputs()
{
    uint32_t value;

    value = reg_la0_data & ~NSEL_LPAMP_INP;
    value &= ~NSEL_LPAMP_INM;
    reg_la0_data = value;
}

void lp_opamp_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_LPAMP_BIAS;
    reg_la1_data = value;
}

void lp_opamp_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_LPAMP_BIAS;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* COMPARATOR								*/
/*									*/
/* NOTE:  The comparator's inputs are multiplexed			*/
/*----------------------------------------------------------------------*/

void comparator_powerup()
{
    uint32_t value;

    value = reg_la1_data & ~NENA_COMP_PWR;
    reg_la1_data = value;
}

void comparator_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_COMP_PWR;
    reg_la1_data = value;
}
	
void comparator_enable()
{
    uint32_t value;

    value = reg_la0_data | COMP_ENABLE;
    reg_la0_data = value;
}

void comparator_disable()
{
    uint32_t value;

    value = reg_la0_data & ~COMP_ENABLE;
    reg_la0_data = value;
}

void comparator_enable_inputs()
{
    uint32_t value;

    value = reg_la0_data | SEL_COMP_INP;
    value |= SEL_COMP_INM;
    reg_la0_data = value;
}

void comparator_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_COMP_BIAS;
    reg_la1_data = value;
}

void comparator_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_COMP_BIAS;
    reg_la1_data = value;
}

void comparator_set_hyst(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;

    /* hysteresis bits are backwards with low bit first */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 30;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 29;

    ovalue = reg_la0_data & ~COMP_HYST_MASK;
    ovalue |= maskval;
    reg_la0_data = ovalue;
}

void comparator_set_trim(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;
 
    /* trim values are scrambled and are in order la_data_in
     * 25, 26, 27, 33, 32, 31
     * which is reg_la0_data 25, 26, 27; reg_la1_data 1, 0; reg_la0_data 31.
     * masks COMP_TRIM_MASK_L, COMP_TRIM_MASK_H, and COMP_TRIM_MASK_M.
     */

    maskval  = (((uint32_t)value & 0x20) >> 5) << 25;
    maskval |= (((uint32_t)value & 0x10) >> 4) << 26;
    maskval |= (((uint32_t)value & 0x8)  >> 3) << 27;

    ovalue = reg_la0_data & ~COMP_TRIM_MASK_L;
    ovalue |= maskval;
    reg_la0_data = ovalue;

    maskval = ((uint32_t)value & 0x6) >> 1;
    ovalue = reg_la1_data & ~COMP_TRIM_MASK_H;
    ovalue |= maskval;
    reg_la1_data = ovalue;

    maskval = ((uint32_t)value & 0x1) << 31;
    ovalue = reg_la0_data & ~COMP_TRIM_MASK_M;
    ovalue |= maskval;
    reg_la0_data = ovalue;
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
    uint32_t value;

    value = reg_la1_data & ~NENA_TEMP_PWR;
    reg_la1_data = value;
}

void tempsense_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_TEMP_PWR;
    reg_la1_data = value;
}
	
void tempsense_enable()
{
    uint32_t value;

    value = reg_la1_data | TEMP_ENABLE;
    reg_la1_data = value;
    value = reg_la3_data | SEL_1P2_BIAS;
    reg_la3_data = value;
}

void tempsense_disable()
{
    uint32_t value;

    value = reg_la1_data & ~TEMP_ENABLE;
    reg_la1_data = value;
}

void tempsense_enable_outputs()
{
    uint32_t value;

    value = reg_la1_data & ~NSEL_TEMP_VBE1;
    value &= ~NSEL_TEMP_VBE2;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* HGBW OPAMP								*/
/*----------------------------------------------------------------------*/

void hgbw_opamp_powerup()
{
    uint32_t value;

    value = reg_la1_data & ~NENA_HGBWAMP_PWR;
    reg_la1_data = value;
}

void hgbw_opamp_powerdown()
{
    uint32_t value;

    value = reg_la1_data | NENA_HGBWAMP_PWR;
    reg_la1_data = value;
}
	
void hgbw_opamp_enable()
{
    uint32_t value;

    value = reg_la1_data | HGBWAMP_ENABLE;
    reg_la1_data = value;
}

void hgbw_opamp_disable()
{
    uint32_t value;

    value = reg_la1_data & ~HGBWAMP_ENABLE;
    reg_la1_data = value;
}

void hgbw_opamp_enable_inputs()
{
    uint32_t value;

    value = reg_la1_data | SEL_HGBWAMP_INP;
    value |= SEL_HGBWAMP_INM;
    reg_la1_data = value;
}

void hgbw_opamp_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_HGBWAMP_BIAS;
    reg_la1_data = value;
}

void hgbw_opamp_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_HGBWAMP_BIAS;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* OVERVOLTAGE DETECTOR 2						*/
/*----------------------------------------------------------------------*/

void overvoltage2_powerup()
{
    uint32_t value;

    value = reg_la2_data & ~NENA_OV2_PWR;
    reg_la2_data = value;
}

void overvoltage2_powerdown()
{
    uint32_t value;

    value = reg_la2_data | NENA_OV2_PWR;
    reg_la2_data = value;
}
	
void overvoltage2_enable()
{
    uint32_t value;

    value = reg_la2_data | OV2_ENABLE;
    reg_la2_data = value;
    value = reg_la3_data | SEL_1P2_BIAS;
    reg_la3_data = value;
}

void overvoltage2_disable()
{
    uint32_t value;

    value = reg_la2_data & ~OV2_ENABLE;
    reg_la2_data = value;
}

void overvoltage2_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_OV2_BIAS;
    reg_la1_data = value;
}

void overvoltage2_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_OV2_BIAS;
    reg_la1_data = value;
}

void overvoltage2_set_trippoint(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;

    /* Overvoltage trip point mask bits are in backwards order */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 26;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 25;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 24;
    maskval |= (((uint32_t)value & 0x8) >>  3) << 23;

    ovalue = reg_la2_data & ~OV2_TRIP_MASK;
    ovalue |= maskval;
    reg_la2_data = ovalue;
}

/*----------------------------------------------------------------------*/
/* POWER ON RESET							*/
/*									*/
/* Note that the power-on-reset does not have an enable and is enabled	*/
/* by powering it up or down, or removing the bias.			*/
/*----------------------------------------------------------------------*/

void por_powerup()
{
    uint32_t value;

    value = reg_la2_data & ~NENA_POR_PWR;
    reg_la2_data = value;
}

void por_powerdown()
{
    uint32_t value;

    value = reg_la2_data | NENA_POR_PWR;
    reg_la2_data = value;
}

void por_vbg_enable()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_1P2_BIAS;
    reg_la3_data = value;
}

void por_vbg_disable()
{
    uint32_t value;

    value = reg_la3_data | SEL_1P2_BIAS;
    reg_la3_data = value;
}

void por_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_POR_BIAS;
    reg_la1_data = value;
}

void por_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_POR_BIAS;
    reg_la1_data = value;
}

void por_osc_default()
{
    uint32_t value;

    value = reg_la2_data & ~POR_RC_DISABLE;
    value &= ~POR_RC_ENABLE;
    reg_la2_data = value;
}

void por_force_osc_on()
{
    uint32_t value;

    value = reg_la2_data | POR_RC_ENABLE;
    reg_la2_data = value;
}

void por_force_osc_off()
{
    uint32_t value;

    value = reg_la2_data | POR_RC_DISABLE;
    reg_la2_data = value;
}

void por_pdn_default()
{
    uint32_t value;

    value = reg_la2_data & ~POR_FORCE_PDN;
    reg_la2_data = value;
}

void por_force_pdn()
{
    uint32_t value;

    value = reg_la2_data | POR_FORCE_PDN;
    reg_la2_data = value;
}

void por_select_external_bias()
{
    uint32_t value;

    value = reg_la2_data | POR_ISRC_SEL;
    reg_la2_data = value;
}

void por_select_internal_bias()
{
    uint32_t value;

    value = reg_la2_data & ~POR_ISRC_SEL;
    reg_la2_data = value;
}

void por_oneshot_mode()
{
    uint32_t value;

    value = reg_la3_data | POR_ONESHOT;
    reg_la3_data = value;
}
	
void por_continuous_mode()
{
    uint32_t value;

    value = reg_la3_data & ~POR_ONESHOT;
    reg_la3_data = value;
}

void por_set_trippoint(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;

    /* POR trip point mask bits are in backwards order */

    maskval  = (((uint32_t)value & 0x1) >>  0) << 2;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 1;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 0;

    ovalue = reg_la3_data & ~POR_TRIP_MASK;
    ovalue |= maskval;
    reg_la3_data = ovalue;
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
    uint32_t value;

    value = reg_la2_data & ~NENA_OV1_PWR;
    reg_la2_data = value;
}

void overvoltage1_powerdown()
{
    uint32_t value;

    value = reg_la2_data | NENA_OV1_PWR;
    reg_la2_data = value;
}
	
void overvoltage1_enable()
{
    uint32_t value;

    value = reg_la3_data | OV1_ENABLE;
    value &= ~SEL_1P2_BIAS;
    reg_la3_data = value;
}

void overvoltage1_disable()
{
    uint32_t value;

    value = reg_la3_data & ~OV1_ENABLE;
    reg_la3_data = value;
}

void overvoltage1_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_OV1_BIAS;
    reg_la1_data = value;
}

void overvoltage1_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_OV1_BIAS;
    reg_la1_data = value;
}

void overvoltage1_select_external_bias()
{
    uint32_t value;

    value = reg_la3_data | OV1_ISRC_SEL;
    reg_la3_data = value;
}

void overvoltage1_select_internal_bias()
{
    uint32_t value;

    value = reg_la3_data & ~OV1_ISRC_SEL;
    reg_la3_data = value;
}

void overvoltage1_set_trippoint(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval = ((uint32_t)value & 0xf) << 6;

    ovalue = reg_la3_data & ~OV1_TRIP_MASK;
    ovalue |= maskval;
    reg_la3_data = ovalue;
}

/*----------------------------------------------------------------------*/
/* BROWNOUT DETECTOR							*/
/*----------------------------------------------------------------------*/

void brownout_powerup()
{
    uint32_t value;

    value = reg_la2_data & ~NENA_BRNOUT_PWR;
    reg_la2_data = value;
}

void brownout_powerdown()
{
    uint32_t value;

    value = reg_la2_data | NENA_BRNOUT_PWR;
    reg_la2_data = value;
}
	
void brownout_vbg_enable()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_1P2_BIAS;
    reg_la3_data = value;
}

void brownout_vbg_disable()
{
    uint32_t value;

    value = reg_la3_data | SEL_1P2_BIAS;
    reg_la3_data = value;
}

void brownout_bias_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_BRNOUT_BIAS;
    reg_la1_data = value;
}

void brownout_bias_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_BRNOUT_BIAS;
    reg_la1_data = value;
}

void brownout_select_external_bias()
{
    uint32_t value;

    value = reg_la3_data | BRNOUT_ISRC_SEL;
    reg_la3_data = value;
}

void brownout_select_internal_bias()
{
    uint32_t value;

    value = reg_la3_data & ~BRNOUT_ISRC_SEL;
    reg_la3_data = value;
}

void brownout_set_vtrippoint(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;

    /* The brownout trip point mask is scrambled
     * and is in order 107, 106, 108, or reg_la3_data
     * bits 11, 10, 12
     */
    maskval  = (((uint32_t)value & 0x1) >>  0) << 12;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 10;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 11;

    ovalue = reg_la3_data & ~BRNOUT_VTRIP_MASK;
    ovalue |= maskval;
    reg_la3_data = ovalue;
}

void brownout_set_otrippoint(uint8_t value)
{
    uint32_t ovalue;
    uint32_t maskval;

    /* The brownout trip point mask is scrambled
     * and is in order 112, 113, 111, or reg_la3_data
     * bits 16, 17, 15
     */
    maskval  = (((uint32_t)value & 0x1) >>  0) << 15;
    maskval |= (((uint32_t)value & 0x2) >>  1) << 17;
    maskval |= (((uint32_t)value & 0x4) >>  2) << 16;

    ovalue = reg_la3_data & ~BRNOUT_OTRIP_MASK;
    ovalue |= maskval;
    reg_la3_data = ovalue;
}

void brownout_osc_default()
{
    uint32_t value;

    value = reg_la3_data & ~BRNOUT_RC_DISABLE;
    value &= ~BRNOUT_RC_ENABLE;
    reg_la3_data = value;
}

void brownout_force_osc_on()
{
    uint32_t value;

    value = reg_la3_data | BRNOUT_RC_ENABLE;
    reg_la3_data = value;
}

void brownout_force_osc_off()
{
    uint32_t value;

    value = reg_la3_data | BRNOUT_RC_DISABLE;
    reg_la3_data = value;
}

void brownout_oneshot_mode()
{
    uint32_t value;

    value = reg_la3_data | BRNOUT_ONESHOT;
    reg_la3_data = value;
}
	
void brownout_continuous_mode()
{
    uint32_t value;

    value = reg_la3_data & ~BRNOUT_ONESHOT;
    reg_la3_data = value;
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
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
}

void biasgen_disable()
{
    uint32_t value;

    value = reg_la2_data & ~ENA_BIASGEN;
    reg_la2_data = value;
}

void biasgen_sources_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    reg_la1_data = value;
}

void biasgen_sources_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_SOURCE_BIAS;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current source test 0 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_source_test0_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_SRC_TEST0;
    reg_la1_data = value;
}

void biasgen_source_test0_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_SRC_TEST0;
    reg_la1_data = value;
}

void biasgen_source_test0_enable_output()
{
    uint32_t value;

    value = reg_la1_data & ~NSEL_SRC_TEST0;
    reg_la1_data = value;
}

void biasgen_source_test0_disable_output()
{
    uint32_t value;

    value = reg_la1_data | NSEL_SRC_TEST0;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current source test 1 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_source_test1_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    reg_la2_data = value;
    value = reg_la1_data & ~NENA_SOURCE_BIAS;
    value &= ~NENA_SRC_TEST1;
    reg_la1_data = value;
}

void biasgen_source_test1_disable()
{
    uint32_t value;

    value = reg_la1_data | NENA_SRC_TEST1;
    reg_la1_data = value;
}

void biasgen_source_test1_enable_output()
{
    uint32_t value;

    value = reg_la1_data | SEL_SRC_TEST1;
    reg_la1_data = value;
}

void biasgen_source_test1_disable_output()
{
    uint32_t value;

    value = reg_la1_data & ~SEL_SRC_TEST1;
    reg_la1_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 0 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test0_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    value |= ENA_SINK_TEST0;
    reg_la2_data = value;
}

void biasgen_sink_test0_disable()
{
    uint32_t value;

    value = reg_la2_data & ~ENA_SINK_TEST0;
    reg_la2_data = value;
}

void biasgen_sink_test0_enable_output()
{
    uint32_t value;

    value = reg_la3_data | SEL_SINK_TEST0;
    reg_la3_data = value;
}

void biasgen_sink_test0_disable_output()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_SINK_TEST0;
    reg_la3_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 1 (100nA)				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test1_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    value |= ENA_SINK_TEST1;
    reg_la2_data = value;
}

void biasgen_sink_test1_disable()
{
    uint32_t value;

    value = reg_la2_data & ~ENA_SINK_TEST1;
    reg_la2_data = value;
}

void biasgen_sink_test1_enable_output()
{
    uint32_t value;

    value = reg_la3_data | SEL_SINK_TEST1;
    reg_la3_data = value;
}

void biasgen_sink_test1_disable_output()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_SINK_TEST1;
    reg_la3_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 3.7uA				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test_3700_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    value |= ENA_SINK_3700;
    reg_la2_data = value;
}

void biasgen_sink_test_3700_disable()
{
    uint32_t value;

    value = reg_la2_data & ~ENA_SINK_3700;
    reg_la2_data = value;
}

void biasgen_sink_test_3700_enable_output()
{
    uint32_t value;

    value = reg_la3_data | SEL_SINK_3700;
    reg_la3_data = value;
}

void biasgen_sink_test_3700_disable_output()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_SINK_3700;
    reg_la3_data = value;
}

/*----------------------------------------------------------------------*/
/* Bias generator current sink test 5.0uA				*/
/*----------------------------------------------------------------------*/

void biasgen_sink_test_5000_enable()
{
    uint32_t value;

    value = reg_la2_data | ENA_BIASGEN;
    value |= ENA_SINK_5000;
    reg_la2_data = value;
}

void biasgen_sink_test_5000_disable()
{
    uint32_t value;

    value = reg_la2_data & ~ENA_SINK_5000;
    reg_la2_data = value;
}

void biasgen_sink_test_5000_enable_output()
{
    uint32_t value;

    value = reg_la3_data | SEL_SINK_5000;
    reg_la3_data = value;
}

void biasgen_sink_test_5000_disable_output()
{
    uint32_t value;

    value = reg_la3_data & ~SEL_SINK_5000;
    reg_la3_data = value;
}

/*----------------------------------------------------------------------*/
/* UNUSED POWER SUPPLIES (never enabled)				*/
/*----------------------------------------------------------------------*/

void powerdown_unused()
{
    uint32_t value;

    value = reg_la1_data | NENA_UNUSED1_PWR;
    reg_la1_data = value;
    value = reg_la2_data | NENA_UNUSED2_PWR | NENA_UNUSED3_PWR;
    reg_la2_data = value;
}

/*----------------------------------------------------------------------*/
/* ALL POWER SUPPLIES (initialization)					*/
/*----------------------------------------------------------------------*/

void powerdown_all()
{
    uint32_t value;

    value = reg_la1_data | (NENA_BANDGAP_PWR | NENA_HSXO_PWR | NENA_LPAMP_PWR |
			NENA_COMP_PWR | NENA_TEMP_PWR | NENA_HGBWAMP_PWR |
			NENA_UNUSED1_PWR);
    reg_la1_data = value;
			
    value = reg_la2_data | (NENA_OV2_PWR | NENA_UNUSED2_PWR | NENA_LSXO_PWR |
			NENA_UNUSED3_PWR | NENA_POR_PWR | NENA_OV1_PWR |
			NENA_BRNOUT_PWR);
    reg_la2_data = value;
}

/*----------------------------------------------------------------------*/
/* Initialize logic analyzrer						*/
/*----------------------------------------------------------------------*/

void init_logic_analyzer()
{
    // Start with all data bits zero except for the sense-negative
    // power supply enables.  This is equivalent to calling
    // powerdown_all() above.

    reg_la0_data = 0x00000000;
    reg_la1_data = NENA_BANDGAP_PWR | NENA_HSXO_PWR | NENA_LPAMP_PWR |
			NENA_COMP_PWR | NENA_TEMP_PWR | NENA_HGBWAMP_PWR |
			NENA_UNUSED1_PWR;
			
    reg_la2_data = NENA_OV2_PWR | NENA_UNUSED2_PWR | NENA_LSXO_PWR |
			NENA_UNUSED3_PWR | NENA_POR_PWR | NENA_OV1_PWR |
			NENA_BRNOUT_PWR;
    reg_la3_data = 0x00000000;

    // All logic analyzer outputs being used should be driven.
    // No issue just enabling all of them.  Enable the outputs
    // as well, even though only a few in the upper registers are
    // being used.

    reg_la0_iena = 0xffffffff;
    reg_la1_iena = 0xffffffff;
    reg_la2_iena = 0xffffffff;
    reg_la3_iena = 0xffffffff;

    reg_la0_oenb = 0xffffffff;
    reg_la1_oenb = 0xffffffff;
    reg_la2_oenb = 0xffffffff;
    reg_la3_oenb = 0xffffffff;

}

