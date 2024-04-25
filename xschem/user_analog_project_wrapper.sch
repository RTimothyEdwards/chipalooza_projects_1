v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
N 3600 -170 3780 -170 {
lab=vccd1}
N 3600 -150 3780 -150 {
lab=vccd2}
N 3600 -130 3780 -130 {
lab=vdda1}
N 3600 -110 3780 -110 {
lab=vdda2}
N 4080 -170 4260 -170 {
lab=io_oeb[26:0]}
N 4080 -150 4260 -150 {
lab=io_out[26:0]}
N 4080 -130 4260 -130 {
lab=gpio_noesd[17:0]}
N 4080 -110 4260 -110 {
lab=gpio_analog[17:0]}
N 4080 -90 4260 -90 {
lab=io_analog[10:0]}
N 4080 -70 4260 -70 {
lab=la_data_in[127:0]}
N 3600 -90 3780 -90 {
lab=vssa1}
N 3600 -70 3780 -70 {
lab=vssa2}
N 3600 -50 3780 -50 {
lab=la_data_out[127:0]}
N 3600 -30 3780 -30 {
lab=vssd2}
N 3600 -10 3780 -10 {
lab=vssd1}
C {devices/iopin.sym} 3240 -470 0 0 {name=p1 lab=vdda1}
C {devices/iopin.sym} 3240 -440 0 0 {name=p2 lab=vdda2}
C {devices/iopin.sym} 3240 -410 0 0 {name=p3 lab=vssa1}
C {devices/iopin.sym} 3240 -380 0 0 {name=p4 lab=vssa2}
C {devices/iopin.sym} 3240 -350 0 0 {name=p5 lab=vccd1}
C {devices/iopin.sym} 3240 -320 0 0 {name=p6 lab=vccd2}
C {devices/iopin.sym} 3240 -290 0 0 {name=p7 lab=vssd1}
C {devices/iopin.sym} 3240 -260 0 0 {name=p8 lab=vssd2}
C {devices/ipin.sym} 3290 -190 0 0 {name=p9 lab=wb_clk_i}
C {devices/ipin.sym} 3290 -160 0 0 {name=p10 lab=wb_rst_i}
C {devices/ipin.sym} 3290 -130 0 0 {name=p11 lab=wbs_stb_i}
C {devices/ipin.sym} 3290 -100 0 0 {name=p12 lab=wbs_cyc_i}
C {devices/ipin.sym} 3290 -70 0 0 {name=p13 lab=wbs_we_i}
C {devices/ipin.sym} 3290 -40 0 0 {name=p14 lab=wbs_sel_i[3:0]}
C {devices/ipin.sym} 3290 -10 0 0 {name=p15 lab=wbs_dat_i[31:0]}
C {devices/ipin.sym} 3290 20 0 0 {name=p16 lab=wbs_adr_i[31:0]}
C {devices/opin.sym} 3280 80 0 0 {name=p17 lab=wbs_ack_o}
C {devices/opin.sym} 3280 110 0 0 {name=p18 lab=wbs_dat_o[31:0]}
C {devices/ipin.sym} 3290 150 0 0 {name=p19 lab=la_data_in[127:0]}
C {devices/opin.sym} 3280 180 0 0 {name=p20 lab=la_data_out[127:0]}
C {devices/ipin.sym} 3290 260 0 0 {name=p21 lab=io_in[26:0]}
C {devices/ipin.sym} 3290 290 0 0 {name=p22 lab=io_in_3v3[26:0]}
C {devices/ipin.sym} 3280 570 0 0 {name=p23 lab=user_clock2}
C {devices/opin.sym} 3280 320 0 0 {name=p24 lab=io_out[26:0]}
C {devices/opin.sym} 3280 350 0 0 {name=p25 lab=io_oeb[26:0]}
C {devices/iopin.sym} 3250 410 0 0 {name=p26 lab=gpio_analog[17:0]}
C {devices/iopin.sym} 3250 440 0 0 {name=p27 lab=gpio_noesd[17:0]}
C {devices/iopin.sym} 3250 470 0 0 {name=p29 lab=io_analog[10:0]}
C {devices/iopin.sym} 3250 500 0 0 {name=p30 lab=io_clamp_high[2:0]}
C {devices/iopin.sym} 3250 530 0 0 {name=p31 lab=io_clamp_low[2:0]}
C {devices/opin.sym} 3270 600 0 0 {name=p32 lab=user_irq[2:0]}
C {devices/ipin.sym} 3290 210 0 0 {name=p28 lab=la_oenb[127:0]}
C {chipalooza_testchip1.sym} 3930 -90 0 0 {name=x1}
C {devices/lab_pin.sym} 4260 -170 0 1 {name=p217 sig_type=std_logic lab=io_oeb[26:0]}
C {devices/lab_pin.sym} 4260 -150 0 1 {name=p33 sig_type=std_logic lab=io_out[26:0]}
C {devices/lab_pin.sym} 4260 -130 0 1 {name=p34 sig_type=std_logic lab=gpio_noesd[17:0]}
C {devices/lab_pin.sym} 4260 -110 0 1 {name=p35 sig_type=std_logic lab=gpio_analog[17:0]}
C {devices/lab_pin.sym} 4260 -90 0 1 {name=p36 sig_type=std_logic lab=io_analog[10:0]}
C {devices/lab_pin.sym} 4260 -70 0 1 {name=p37 sig_type=std_logic lab=la_data_in[127:0]}
C {devices/lab_pin.sym} 3600 -50 0 0 {name=p38 sig_type=std_logic lab=la_data_out[127:0]}
C {devices/lab_pin.sym} 3600 -30 0 0 {name=p39 sig_type=std_logic lab=vssd2}
C {devices/lab_pin.sym} 3600 -10 0 0 {name=p40 sig_type=std_logic lab=vssd1}
C {devices/lab_pin.sym} 3600 -70 0 0 {name=p41 sig_type=std_logic lab=vssa2}
C {devices/lab_pin.sym} 3600 -90 0 0 {name=p42 sig_type=std_logic lab=vssa1}
C {devices/lab_pin.sym} 3600 -110 0 0 {name=p43 sig_type=std_logic lab=vdda2}
C {devices/lab_pin.sym} 3600 -130 0 0 {name=p44 sig_type=std_logic lab=vdda1}
C {devices/lab_pin.sym} 3600 -150 0 0 {name=p45 sig_type=std_logic lab=vccd2}
C {devices/lab_pin.sym} 3600 -170 0 0 {name=p46 sig_type=std_logic lab=vccd1}
