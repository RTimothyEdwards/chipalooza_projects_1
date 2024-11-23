/*----------------------------------------------------------*/
/* Utility function prototypes for the chipalooza_testchip1 */
/*----------------------------------------------------------*/
/* Written by Tim Edwards, Efabless			    */
/* November 22, 2024					    */
/*----------------------------------------------------------*/

/* Bandgap reference */

void bandgap_powerup();
void bandgap_powerdown();
void bandgap_select_output();
void bandgap_set_trim(uint16_t value);

/* 4-16MHHz crystal oscillator */

void hsxo_powerup();
void hsxo_powerdown();
void hsxo_enable();
void hsxo_disable();
void hsxo_run();
void hsxo_standby();
void hsxo_bias_enable();
void hsxo_bias_disable();

/* 32kHz crystal oscillator */

void lsxo_powerup();
void lsxo_powerdown();
void lsxo_enable();
void lsxo_disable();
void lsxo_run();
void lsxo_standby();
void lsxo_bias_enable();
void lsxo_bias_disable();

/* Low-power op amp */

void lp_opamp_powerup();
void lp_opamp_powerdown();
void lp_opamp_enable();
void lp_opamp_disable();
void lp_opamp_enable_inputs();
void lp_opamp_bias_enable();
void lp_opamp_bias_disable();

/* Comparator */

void comparator_powerup();
void comparator_powerdown();
void comparator_enable();
void comparator_disable();
void comparator_enable_inputs();
void comparator_bias_enable();
void comparator_bias_disable();
void comparator_set_hyst(uint8_t value);
void comparator_set_trim(uint8_t value);

/* Temperature sensor */

void tempsense_powerup();
void tempsense_powerdown();
void tempsense_enable();
void tempsense_disable();
void tempsense_enable_outputs();

/* High gain-bandwidth op amp */

void hgbw_opamp_powerup();
void hgbw_opamp_powerdown();
void hgbw_opamp_enable();
void hgbw_opamp_disable();
void hgbw_opamp_enable_inputs();
void hgbw_opamp_bias_enable();
void hgbw_opamp_bias_disable();

/* overvoltage detector (2) */

void overvoltage2_powerup();
void overvoltage2_powerdown();
void overvoltage2_enable();
void overvoltage2_disable();
void overvoltage2_bias_enable();
void overvoltage2_bias_disable();
void overvoltage2_set_trippoint(uint8_t value);

/* power-on-reset */

void por_powerup();
void por_powerdown();
void por_vbg_enable();
void por_vbg_disable();
void por_bias_enable();
void por_bias_disable();
void por_osc_default();
void por_force_osc_on();
void por_force_osc_off();
void por_pdn_default();
void por_force_pdn();
void por_select_external_bias();
void por_select_internal_bias();
void por_oneshot_mode();
void por_continuous_mode();
void por_set_trippoint(uint8_t value);
uint8_t por_get_timeout();
uint8_t por_get_startup_timeout();

/* overvoltage detector (1) */

void overvoltage1_powerup();
void overvoltage1_powerdown();
void overvoltage1_enable();
void overvoltage1_disable();
void overvoltage1_bias_enable();
void overvoltage1_bias_disable();
void overvoltage1_select_external_bias();
void overvoltage1_select_internal_bias();
void overvoltage1_set_trippoint(uint8_t value);

/* Brownout detector */

void brownout_powerup();
void brownout_powerdown();
void brownout_vbg_enable();
void brownout_vbg_disable();
void brownout_bias_enable();
void brownout_bias_disable();
void brownout_select_external_bias();
void brownout_select_internal_bias();
void brownout_set_vtrippoint(uint8_t value);
void brownout_set_otrippoint(uint8_t value);
void brownout_osc_default();
void brownout_force_osc_on();
void brownout_force_osc_off();
void brownout_oneshot_mode();
void brownout_continuous_mode();
uint8_t brownout_get_timeout();

/* Bias generator */

void biasgen_enable();
void biasgen_disable();

/* Bias generator test outputs */

void biasgen_sources_enable();
void biasgen_sources_disable();
void biasgen_source_test0_enable();
void biasgen_source_test0_disable();
void biasgen_source_test0_enable_output();
void biasgen_source_test0_disable_output();
void biasgen_source_test1_enable();
void biasgen_source_test1_disable();
void biasgen_source_test1_enable_output();
void biasgen_source_test1_disable_output();
void biasgen_sink_test0_enable();
void biasgen_sink_test0_disable();
void biasgen_sink_test0_enable_output();
void biasgen_sink_test0_disable_output();
void biasgen_sink_test1_enable();
void biasgen_sink_test1_disable();
void biasgen_sink_test1_enable_output();
void biasgen_sink_test1_disable_output();
void biasgen_sink_test_3700_enable();
void biasgen_sink_test_3700_disable();
void biasgen_sink_test_3700_enable_output();
void biasgen_sink_test_3700_disable_output();
void biasgen_sink_test_5000_enable();
void biasgen_sink_test_5000_disable();
void biasgen_sink_test_5000_enable_output();
void biasgen_sink_test_5000_disable_output();

/* Power switching */

void powerdown_unused();
void powerdown_all();

/* General */

void init_logic_analyzer();
