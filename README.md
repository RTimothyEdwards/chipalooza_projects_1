# Caravel Analog User

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) [![CI](https://github.com/efabless/caravel_user_project_analog/actions/workflows/user_project_ci.yml/badge.svg)](https://github.com/efabless/caravel_user_project_analog/actions/workflows/user_project_ci.yml) [![Caravan Build](https://github.com/efabless/caravel_user_project_analog/actions/workflows/caravan_build.yml/badge.svg)](https://github.com/efabless/caravel_user_project_analog/actions/workflows/caravan_build.yml)

---

| :exclamation: Important Note            |
|-----------------------------------------|

This is the first test chip from the Chipalooza challenge 2024.
11 designs made it on the April tapeout.

The projects on this tapeout and their source URLs are as follows:

	1.  	High-speed crystal oscillator (4-16MHz)
		hsxo-cpz1 
		https://github.com/efabless/sky130_ht_ip__hsxo_cpz1 (forked)
		https://github.com/htfab/hsxo-cpz1
		Tamas Hubai

	2.  	Brownout detector
		sky130_ajc_ip__brownout
		https://github.com/efabless/sky130_ajc_ip__brownout (forked)
		https://github.com/ajcci/sky130_ajc_ip__brownout
		Robin Tsang

	3.  	Overvoltage detector
		sky130_ajc_ip__overvoltage
		https://github.com/efabless/sky130_ajc_ip__overvoltage (forked)
		https://github.com/ajcci/sky130_ajc_ip__overvoltage
		Robin Tsang

	4.  	Power-on-Reset
		sky130_ajc_ip__por
		https://github.com/efabless/sky130_ajc_ip__por (forked)
		https://github.com/ajcci/sky130_ajc_ip__por
		Robin Tsang

	5.  	Comparator
		sky130_ak_ip__comparator
		https://github.com/efabless/sky130_ak_ip__comparator (forked)
		https://github.com/andrewkkang/sky130_ak_ip__comparator
		Andrew Kang

	6.  	Low-speed crystal oscillator (32kHz)
		sky130_be_ip__lsxo
		https://github.com/efabless/sky130_be_ip__lsxo (forked)
		https://github.com/b-etz/sky130_be_ip__lsxo
		Brady Etz

	7.  	Temperature sensor
		sky130_od_ip__tempsensor
		https://github.com/efabless/sky130_od_ip__tempsensor (forked)
		https://github.com/ordicker/sky130_od_ip__tempsensor
		Or Dicker

	8.  	Low power operational amplifier
		sky130_rodovalho_ip__lpopamp
		https://github.com/efabless/sky130_rodovalho_ip__lpopamp (forked)
		https://github.com/lhrodovalho/sky130_rodovalho_ip__lpopamp
		Luis Henrique Rodovalho

	9.  	High gain-bandwidth operational amplifier
		sky130_td_ip__opamp_hp
		https://github.com/efabless/sky130_td_ip__opamp_hp (forked)
		https://github.com/tdextrous/sky130_td_ip__opamp_hp
		Thomas Dexter

	10. 	Overvoltage detector
		sky130_vbl_ip__overvoltage
		https://github.com/efabless/sky130_vbl_ip__overvoltage (forked)
		https://github.com/LDFranck/sky130_vbl_ip__overvoltage
		Lucas Franck, William Orlato, and Toni Tejada

	11.	Bandgap (not from Chipalooza)
		bandgap
		https://github.com/efabless/sky130_cw_ip (forked)
		https://github.com/christoph-weiser/mpw7
		Christoph Weiser

	12.	Power FET (not from Chipalooza)
		power_stage
		(in this repository)
		Weston Braun

	13.	Bias current generator (not from Chipalooza)
		bias_generator
		(in this repository)
		Tim Edwards

	14.	Ground-isolated analog switch (not from Chipalooza)
		isolated_switch_ena1v8
		(in this repository)
		Tim Edwards

(Documentation, including test instructions, still needs to be completed)

:---: | :---

Building:

Get the dependencies above by doing "make get_ip_blocks" in the top level
directory.  This will clone all of the IP blocks from various github
repository sources into the "dependencies" directory.

The test chip is generated in magic by running magic in the mag/ directory
and issuing the command "source construct_testchip.tcl".

Verifying:

In the top level directory, do "make run-precheck".  This requires at
least setting environment variables PDK_ROOT, PDK, and PRECHECK_ROOT.
If the PDK is installed with open_pdks, then PRECHECK_ROOT can be set
to open_pdks/sources/precheck_sky130.

Testing:

All projects are connected either to the logic analyzer (128 I/O bits) or
the GPIO pins.  Generally speaking, static control bits (enable and trim,
for example) are logic analyzer outputs.  Dynamic digital bits are routed
to GPIO digital outputs, while analog I/O are routed to the analog
connections of the GPIO.

Each power supply is routed through gated power pFETs so each project
can be powered individually.  Each power supply connection internally
is routed to a bare analog pin for monitoring the supply voltage of
the project.  Be aware that these are ESD-sensitive points!

Power supplies are enabled through a differential switch.  Due to
time constraints, the differential signals (enable, !enable) were
both routed to the logic analyzer.  Both bits need to be set
correctly.

Most projects take current biases which are distributed by a central
bias current generator circuit.  Various test point bias currents are
connected through ground-isolated switches to GPIO analog signals.

Project circuit blocks are described below, starting at the top left
corner of the chip and working counterclockwise around the chip
perimeter.

High Gain-Bandwidth Operational Amplifier
(Thomas Dexter)
Enable:  la_data_in[37]
Bias:    100nA	when selected
	Selection: la_data_in[40] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor:  io_analog[10] (pin GPIO 24) "mon_hgbw_opamp"
Power supply enable: la_data_in[60]
Amp output:  gpio_noesd[7] (pin GPIO 25) "hgbw_opamp_out"
Amp negative input: gpio_analog[8] (pin GPIO 26) "hgbw_opamp_in-" when selected
	Selection: la_data_in[36] = 1
Amp positive input: gpio_analog[9] (pin GPIO 27) "hgbw_opamp_in+" when selected
	Selection: la_data_in[34] = 1

---

Temperature sensor
(Or Dicker)
Enable: la_data_in[35]
Bias:  gpio_noesd[2] (pin GPIO 9) "1.2V_bias" (nominally 1.2V) when selected
	Selection: la_data_in[122] = 1
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[9] (pin GPIO 23) "mon_temp_sense"
Power supply enable: la_data_in[58]
Vbe1_out: gpio_analog[9] (pin GPIO 27) "temp_sense_vbe1" when selected
	Selection: la_data_in[34] = 0
Vbe2_out: gpio_analog[8] (pin GPIO 26) "temp_sense_vbe2" when selected
	Selection: la_data_in[36] = 0

---

Comparator
(Andrew Kang)
Enable: la_data_in[28]
Hysteresis: la_data_in[29:30]
Trim: la_data_in[25:27],la_data_in[33:31]
Bias:	400nA	when selected
	Selection:  la_data_in[44] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[8] (pin GPIO 22) "mon_comparator"
Power supply enable: la_data_in[56]
Comparator output: io_out[17] (pin GPIO 28) "comparator_out"
Comparator negative input:  gpio_analog[12] (pin GPIO 30) "comparator_in-" when selected
	Selection: la_data_in[22] = 1
Comparator positive input:  gpio_analog[11] (pin GPIO 29) "comparator_in+" when selected
	Selection: la_data_in[23] = 1
	
---

Low power operational amplifier
(Luis Henrique Rodovalho)
Enable: la_data_in[21]
Bias:  10uA when selected
	Selection:  la_data_in[46] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[7] (pin GPIO 21) "mon_lpopamp"
Power supply enable: la_data_in[54]
Amplifier output:  gpio_analog[13] (pin GPIO 31) "lpopamp_out"
Amplifier negative input: gpio_analog[11] (pin GPIO 29) "lpopamp_in-" when selected
	Selection: la_data_in[23] = 0
Amplifier positive input: gpio_analog[12] (pin GPIO 30) "lpopamp_in+" when selected
	Selection: la_data_in[22] = 0

---

High speed crystal oscillator
(Tamas Hubai)
Enable: la_data_in[19]
Standby: la_data_in[20]
Bias:  10uA when selected
	Selection: la_data_in[47] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[6] (pin GPIO 20) "mon_hsxo"
Power supply enable:  la_data_in[52]
Oscillator out:  io_out[23] (pin GPIO 34) "hsxo_out"
Crystal Xin:  gpio_analog[14] (pin GPIO 32) "hsxo_xin"
Crystal Xout: gpio_analog[15] (pin GPIO 33) "hsxo_xout"

---

Bandgap (Christoph Weiser)
Enable: none (enable via power supply)
Bias:  self-biased
Trim: la_data_in[9,8,10,7,11,6,12,5,13,4,14,3,15,2,16,1]
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[5] (pin GPIO 19) "mon_bandgap"
Power supply enable: la_data_in[50]
Bandgap output:  gpio_analog[16] (pin GPIO 34) "bandgap_out" when selected
	Selection:  la_data_in[18] = 1

---

Brownout detector (Robin Tsang)
Enable: la_data_in[109]
Bias: gpio_noesd[2] (pin GPIO 9) "1.2V_bias" (nominally 1.2V) when selected
	Selection: la_data_in[122] = 0
Bias: 200nA when selected
	Selection: la_data_in[43] = 0
Trip point select (otrip):  la_data_in[112:113,111]
Trip point select (vtrip):  la_data_in[107:106,108]
Force enable RC osc: la_data_in[115]
Force disable RC osc: la_data_in[114]
Force short oneshot: la_data_in[116]
Current source select: la_data_in[110]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[0] (pin GPIO 14) "mon_brownout"
Power supply enable: la_data_in[77]
Outb: io_out[0] (pin GPIO 0) "brownout_outb"
Dcomp: io_out[1] (pin GPIO 1) "brownout_dcomp"
Vunder: io_out[5] (pin GPIO 5) "brownout_vunder"
Timed out: la_data_out[117]

---

Overvoltage detector (Robin Tsang)
Enable: la_data_in[100]
Bias: gpio_noesd[2] (pin GPIO 9) "1.2V_bias" (nominally 1.2V) when selected
	Selection: la_data_in[122] = 0
Bias: 200nA when selected
	Selection: la_data_in[42] = 0
Trip point select (otrip):  la_data_in[105:102]
Current source select: la_data_in[101]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[1] (pin GPIO 15) "mon_overvoltage1"
Power supply enable: la_data_in[75]
Ovout: io_out[6] (pin GPIO 6) "overvoltage1_ovout"

---

Power-on-reset (Robin Tsang)
Bias: gpio_noesd[2] (pin GPIO 9) "1.2V_bias" (nominally 1.2V) when selected
	Selection: la_data_in[122] = 0
Bias: 200nA when selected
	Selection: la_data_in[41] = 0
Trip point select (otrip): la_data_in[96:98]
Force PDN: la_data_in[94]
Force enable RC osc: la_data_in[93]
Force disable RC osc: la_data_in[92]
Force short oneshot: la_data_in[99]
Current source select: la_data_in[95]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[2] (pin GPIO 16) "mon_por"
Power supply enable: la_data_in[73]
POR: io_out[7] (pin GPIO 7) "por_out"
PORb: io_out[8] (pin GPIO 8) "por_outb"
Osc_clk: io_out[3] (pin GPIO 3) "por_osc_clk"
Dcomp: io_out[2] (pin GPIO 2) "por_dcomp"
Pwup_filt: io_out[4] (pin GPIO 4) "por_pwup_filt"
Startup timed out: la_data_out[120]
POR timed out: la_data_out[119]

---

Low-speed (32kHz) crystal oscillator (Brady Etz)
Enable: la_data_in[86]
Standby: la_data_in[85]
Bias: 50nA when selected
	Selection: la_data_in[39] = 0
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[3] (pin GPIO 17) "mon_lsxo"
Power supply enable: la_data_in[69]
Dout: io_out[12] (pin GPIO 12) "lsxo_out"
Crystal XIn: gpio_noesd[3] (pin GPIO 10) "lsxo_xin"
Crystal XOut: gpio_noesd[4] (pin GPIO 11) "lsxs_xout"

---

Overvoltage detector (Lucas Franck & William Orlato)
Enable: la_data_in[91]
Bias: gpio_noesd[2] (pin GPIO 9) "1.2V_bias" (nominally 1.2V) when selected
	Selection: la_data_in[122] = 1
Bias: 600nA when selected
	Selection: la_data_in[45] = 0
Trip point select (vtrip): la_data_in[87:90]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[4] (pin GPIO 18) "mon_overvoltage2"
Power supply enable: la_data_in[65]
OVout: io_out[13] (pin GPIO 13) "overvoltage2_out"

---

All bias currents are regulated by an input bias voltage which is
nominally 3.3V but may be adjusted up or down to trim the bias
(limit max. voltage VDDIO + 0.3V to avoid forward biasing the ESD
diodes into the power supply).
Bias in: gpio_analog[17] (pin GPIO 35) "bias_trim_in"

---

Three power FETs are unused but should be kept disabled:
Enable:  la_data_in[62], la_data_in[67], la_data_in[71]

---

The bias generator has a master enable signal that will enable
all bias currents:

Enable bias generator:  la_data_in[79] 

It also has a separate disable signal for the sources (which is
all of the biases used by projects on this chip):

Disable bias generator sources:  la_data_in[48] 

---

These current sources/sinks are multiplexed to analog pins not otherwise
being used for projects.  The "enable" or "disable" bit enables or disables
the current bias, and "selection" connects it to the associated pin:

100nA source (test0): gpio_analog[16] (pin GPIO 34) when selected
	Disable: la_data_in[49]
	Selection: la_data_in[18] = 0 (at pin)

100nA source (test1): gpio_analog[10] (pin GPIO 28) when selected
	Disable: la_data_in[38]
	Selection: la_data_in[17] = 1 (at pin)

100nA sink (test1): gpio_analog[6] (pin GPIO 13) when selected
	Enable:  la_data_in[84]
	Selection: la_data_in[124] = 1 (at pin)

3.7uA sink (sink_3700): gpio_analog[5] (pin GPIO 12) when selected
	Enable:  la_data_in[83]
	Selection: la_data_in[123] = 1 (at pin)

5.0uA sink (sink_5000_1): gpio_analog[1] (pin GPIO 8) when selected
	Enable:  la_data_in[81]
	Selection: la_data_in[121] = 1 (at pin)

100nA sink (test0): gpio_analog[0] (pin GPIO 7) when selected
	Enable:  la_data_in[78]
	Selection: la_data_in[118] = 1 (at pin)

---

Refer to [README](docs/source/index.rst) for this sample project documentation. 

Refer to docs/chipalooza_testchip1.pdf (.ps) for a package pinout drawing.

---

Chip QFN-64 package pinout:

Pin  Signal(s)
 1   vssa2
 2   mprj_io[25] hgbw_opamp_out
 3   mprj_io[26] hgbw_opamp_in- temp_sense_vbe2
 4   mprj_io[27] hgbw_opamp_in+ temp_sense_vbe1
 5   mprj_io[28] comparator_out source_100_1
 6   mprj_io[29] comparator_in+ lpopamp_in-
 7   mprj_io[30] comparator_in- lpopamp_in+
 8   mprj_io[31] lpopamp_out
 9   vdda2
10   vssd2
11   mprj_io[32] hsxo_xin
12   mprj_io[33] hsxo_xout
13   mprj_io[34] hsxo_out  bandgap_out source_100_0
14   mprj_io[35] bias_trim_in
15   mprj_io[36]
16   mprj_io[37]
17   vddio
18   vccd
19   N/C
20   vssa
21   resetb
22   clock
23   vssd
24   flash_csb
25   flash_clk
26   flash_io0
27   flash_io1
28   gpio
29   vssio
30   vdda
31   mprj_io[0] brownout_outb
32   mprj_io[1] brownout_dcomp
37   mprj_io[2] por_dcomp
34   mprj_io[3] por_osc_clk
35   mprj_io[4] por_pwup_filt
36   mprj_io[5] brownout_vunder
37   mprj_io[6] overvoltage1_ovout
38   vssa1
39   vssd1
40   vdda1
41   mprj_io[7] por_out  sink_100_0
42   mprj_io[8] por_outb
43   mprj_io[9]  1.2V_bias
44   mprj_io[10] lsxo_xin
45   mprj_io[11] lsxo_xout
46   mprj_io[12] lsxo_out  sink_3700
47   vdda1
48   mprj_io[13] overvoltage2_out  sink_100_1
49   vccd1
50   mprj_io[14] mon_brownout
51   mprj_io[15] mon_overvoltage1
52   vssa1
53   mprj_io[16] mon_por
54   mprj_io[17] mon_lsxo
55   mprj_io[18] mon_overvoltage2
56   vssio
57   mprj_io[19] mon_bandgap
58   mprj_io[20] mon_hsxo
59   mprj_io[21] mon_lpopamp
60   mprj_io[22] mon_comparator
61   mprj_io[23] mon_temp_sense
62   mprj_io[24] mon_hgbw_opamp
63   vccd2
64   vddio

---

NOTES:  The following pins have dual analog and digital functions.  The
analog function is enabled/disabled by a ground isolation swtch, and the
digital function is enabled/disabled by configuring the GPIO from
software.

pin 41:  por_out (digital), sink_100_0 (analog)
pin 42:  porb_out (digital), sink_5000_1 (analog)
pin 46:  lsxo_out (digital), sink_3700 (analog)
pin 5:   comparator_out (digital), source_100_1 (analog)
pin 13:  hsxo_out (digital), bandgap_out, source_100_0 (analog, multiplexed)*

*Because the analog on pin 13 is multiplexed, the analog can only be
 completely disabled by selecting source_100_0 as the multiplexer input and
 then disabling the current source.  This is not ideal but should not
 interfere with the HSXO output.

---

Logic analyzer map:

la_data_in[16:1]  Bandgap trim (not in order)
la_data_in[17]	  Select source_test_1 at pin
la_data_in[18]    Select bandgap_out (1) or source_test_0 (0)
la_data_in[19]	  HSXO enable
la_data_in[20]	  HSXO standby
la_data_in[21]	  LP opamp enable
la_data_in[22]	  Select comparator_in- (1) or lpopamp_in+ (0)
la_data_in[23]	  Select comparator_in+ (1) or lpopamp_in- (0)
la_data_in[27:25] Comparator trim
la_data_in[28]	  Comparator enable
la_data_in[30:29] Comparator hysteresis
la_data_in[33:31] Comparator trim
la_data_in[34]	  Select hgbw_opamp_in+ (1) or temp_sense_vbe1 (0)
la_data_in[35]	  Temperature sensor enable
la_data_in[36]	  Select hgbw_opamp_in- (1) or temp_sense_vbe2 (0)
la_data_in[37]	  HGBW op amp enable
la_data_in[38]	  Disable source_test_1 at bias
la_data_in[39]	  Disable LSXO 50nA bias
la_data_in[40] 	  Disable HGBW op amp 100nA bias
la_data_in[41] 	  Disable POR 200nA bias
la_data_in[42]	  Disable Overvoltage1 200nA bias
la_data_in[43]	  Disable Brownout 200nA bias
la_data_in[44]	  Disable Comparator 400nA bias
la_data_in[45]	  Disable Overvoltage2 600nA bias
la_data_in[46]	  Disable LP op amp 10uA bias
la_data_in[47]	  Disable HSXO 10uA bias
la_data_in[48] 	  Disable bias generator sources
la_data_in[49]	  Disable source_test_0
la_data_in[50]	  Enable Bandgap power supply
la_data_in[52]	  Enable HSXO power supply
la_data_in[54]	  Enable LP op amp power supply
la_data_in[56]	  Enable Comparator power supply
la_data_in[58]	  Enable Temperature sensor power supply
la_data_in[60]	  Enable HGBW op amp power supply
la_data_in[62]	  (Enable unused power supply)
la_data_in[65]	  Enable Overvoltage2 power supply
la_data_in[67]	  (Enable unused power supply)
la_data_in[69]	  Enable LSXO power supply
la_data_in[71]	  (Enable unused power supply)
la_data_in[73]	  Enable POR power supply
la_data_in[75]	  Enable Overvoltage1 power supply
la_data_in[77]	  Enable Brownout power supply
la_data_in[78]	  Enable sink_test_0
la_data_in[79]	  Enable bias generator (master enable)
la_data_in[80]	  Enable sink_5000_0 (unused)
la_data_in[81]	  Enable sink_5000_1
la_data_in[82]	  Enable sink_5000_2 (unused)
la_data_in[83]	  Enable sink_3700
la_data_in[84]	  Enable sink_test_1
la_data_in[85]    LSXO Standby
la_data_in[86]    LSXO Enable
la_data_in[90:87] Overvoltage2 trip point selection
la_data_in[91]	  Overvoltage2 enable
la_data_in[92]	  POR force disable RC oscillator
la_data_in[93]	  POR force enable RC oscillator
la_data_in[94]	  POR force PDN
la_data_in[95]	  POR current source select
la_data_in[98:96] POR trip point select
la_data_in[99]	  POR force short oneshot
la_data_in[100]	  Overvoltage1 enable
la_data_in[101]	  Overvoltage1 current source select
la_data_in[105:102] Overvoltage1 trip point select
la_data_in[108:106] Brownout trip point (vtrip) select
la_data_in[109]	  Brownout enable
la_data_in[110]	  Brownout current source select
la_data_in[113:111] Brownout trip point (otrip) select
la_data_in[114]	  Brownout force disable RC oscillator
la_data_in[115]	  Brownout force enable RC oscillator
la_data_in[116]	  Brownout force short oneshot
la_data_out[117]  Brownout timed out
la_data_in[118]	  Select sink_test_0 at pin
la_data_out[119]  POR timed out
la_data_out[120]  POR startup timed out
la_data_in[121]	  Select sink_5000_1 at pin
la_data_in[122]	  Select 1.2V bias (see above)
la_data_in[123]	  Select sink_3700 at pin
la_data_in[124]	  Select sink_test_1 at pin
la_data_in[125]	  Enable sink_2000 (unused)

---

Test plan:

Write a software routine to run on flash that communicates via UART.
Because projects use GPIO[1-4] (housekeeping SPI) and GPIO[5-6] (UART),
use pin GPIO[36] to toggle between the UART and project I/O, and use
pin GPIO[37] to toggle between the housekeeping SPI and project I/O.
Program should communicate with the host computer to select and
identify projects, and to set trim and other configuration bits as
needed.
