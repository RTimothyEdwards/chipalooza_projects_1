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
Enable:  la_data_out[37]
Bias:    100nA	when selected
	Selection: la_data_out[40] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor:  io_analog[10]
Power supply enable: la_data_out[60]
Power supply !enable: la_data_out[61]
Amp output:  gpio_noesd[7]
Amp negative input: gpio_analog[8] when selected
	Selection: la_data_out[36] = 1
Amp positive input: gpio_analog[9] when selected
	Selection: la_data_out[34] = 1

---

Temperature sensor
(Or Dicker)
Enable: la_data_out[35]
Bias:  gpio_noesd[2] (nominally 1.2V) when selected
	Selection: la_data_out[122] = 1
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[9]
Power supply enable: la_data_out[58]
Power supply !enable: la_data_out[59]
Vbe1_out: gpio_analog[8] when selected
	Selection: la_data_out[36] = 0
Vbe2_out: gpio_analog[9] when selected
	Selection: la_data_out[34] = 0

---

Comparator
(Andrew Kang)
Enable: la_data_out[28]
Hysteresis: la_data_out[29:30]
Trim: la_data_out[25:27],la_data_out[33:31]
Bias:	400nA	when selected
	Selection:  la_data_out[44] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[8]
Power supply enable: la_data_out[56]
Power supply !enable: la_data_out[57]
Comparator output: io_out[17]
Comparator negative input:  gpio_analog[12] when selected
	Selection: la_data_out[22] = 1
Comparator positive input:  gpio_analog[11] when selected
	Selection: la_data_out[23] = 1
	
---

Low power operational amplifier
(Luis Henrique Rodovalho)
Enable: la_data_out[21]
Bias:  10uA when selected
	Selection:  la_data_out[46] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[7]
Power supply enable: la_data_out[54]
Power supply !enable: la_data_out[55]
Amplifier output:  gpio_analog[13]
Amplifier negative input: gpio_analog[11] when selected
	Selection: la_data_out[23] = 0
Amplifier positive input: gpio_analog[12] when selected
	Selection: la_data_out[22] = 0

---

High speed crystal oscillator
(Tamas Hubai)
Enable: la_data_out[19]
Standby: la_data_out[20]
Bias:  10uA when selected
	Selection: la_data_out[47] = 0
Upstream analog power supply: vdda2/vssa2
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[6]
Power supply enable:  la_data_out[52]
Power supply !enable: la_data_out[53]
Oscillator out:  io_out[23]
Crystal Xin:  gpio_analog[14]
Crystal Xout: gpio_analog[15]

---

Bandgap (Christoph Weiser)
Enable: none (enable via power supply)
Bias:  self-biased
Trim: la_data_out[9,8,10,7,11,6,12,5,13,4,14,3,15,2,16,1]
Upstream digital power supply: vccd2/vssd2
Power supply monitor: io_analog[5]
Power supply enable: la_data_out[50]
Power supply !enable: la_data_out[51]
Bandgap output:  gpio_analog[16] when selected
	Selection:  la_data_out[18] = 1

---

Brownout detector (Robin Tsang)
Enable: la_data_out[109]
Bias: gpio_noesd[2] (nominally 1.2V) when selected
	Selection: la_data_out[122] = 0
Bias: 200nA when selected
	Selection: la_data_out[43] = 0
Trip point select (otrip):  la_data_out[112:113,111]
Trip point select (vtrip):  la_data_out[107:106,108]
Force enable RC osc: la_data_out[115]
Force disable RC osc: la_data_out[114]
Force short oneshot: la_data_out[116]
Current source select: la_data_out[110]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[0]
Power supply enable: la_data_out[77]
Power supply !enable: la_data_out[76]
Outb: io_out[0]
Dcomp: io_out[1]
Vunder: io_out[5]
Timed out: la_data_in[116]

---

Overvoltage detector (Robin Tsang)
Enable: la_data_out[100]
Bias: gpio_noesd[2] (nominally 1.2V) when selected
	Selection: la_data_out[122] = 0
Bias: 200nA when selected
	Selection: la_data_out[42] = 0
Trip point select (otrip):  la_data_out[105:102]
Current source select: la_data_out[101]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[1]
Power supply enable: la_data_out[75]
Power supply !enable: la_data_out[74]
Ovout: io_out[6]

---

Power-on-reset (Robin Tsang)
Bias: gpio_noesd[2] (nominally 1.2V) when selected
	Selection: la_data_out[122] = 0
Bias: 200nA when selected
	Selection: la_data_out[41] = 0
Trip point select (otrip): la_data_out[96:98]
Force PDN: la_data_out[94]
Force enable RC osc: la_data_out[93]
Force disable RC osc: la_data_out[92]
Force short oneshot: la_data_out[99]
Current source select: la_data_out[95]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[2]
Power supply enable: la_data_out[73]
Power supply !enable: la_data_out[72]
POR: io_out[7]
PORb: io_out[9]
Osc_clk: io_out[3]
Dcomp: io_out[2]
Pwup_filt: io_out[4]
Startup timed out: la_data_in[120]
POR timed out: la_data_io[119]

---

Low-speed (32kHz) crystal oscillator (Brady Etz)
Enable: la_data_out[86]
Standby: la_data_out[85]
Bias: 50nA when selected
	Selection: la_data_out[39] = 0
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[3]
Power supply enable: la_data_out[69]
Power supply !enable: la_data_out[68]
Dout: io_out[12]
Crystal XIn: gpio_noesd[3]
Crystal XOut: gpio_noesd[4]

---

Overvoltage detector (Lucas Franck & William Orlato)
Enable: la_data_out[91]
Bias: gpio_noesd[2] (nominally 1.2V) when selected
	Selection: la_data_out[122] = 1
Trip point select (vtrip): la_data_out[87:90]
Upstream analog power supply: vdda1/vssa1
Upstream digital power supply: vccd1/vssd1
Power supply monitor: io_analog[4]
Power supply enable: la_data_out[65]
Power supply !enable: la_data_out[64]
OVout: io_out[13]

---

Three power FETs are unused but should be kept disabled:
Enable:  la_data_out[62], la_data_out[67], la_data_out[71]
Disable: la_data_out[63], la_data_out[66], la_data_out[70]

---

These current sources/sinks are multiplexed to analog pins not otherwise
being used for projects:

100nA source (test0): gpio_analog[16] when selected
	Selection: la_data_out[18] = 0

100nA source (test1): gpio_analog[10] when selected
	Selection: la_data_out[17] = 1

100nA sink (test1): gpio_analog[6] when selected
	Selection: la_data_out[124] = 1

3.7uA sink (snk_3700): gpio_analog[5] when selected
	Selection: la_data_out[123] = 1

100nA sink (test0): gpio_analog[0] when selected
	Selection: la_data_out[118] = 1

---

Refer to [README](docs/source/index.rst) for this sample project documentation. 
