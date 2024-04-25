v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {Level-shift up with differential outputs} -190 -90 0 0 0.4 0.4 {}
N 10 30 50 30 {
lab=out3v3}
N -120 30 -70 30 {
lab=in1v8}
N 20 200 50 200 {
lab=xxx}
N 30 30 30 120 {
lab=out3v3}
N -60 120 30 120 {
lab=out3v3}
N -60 120 -60 200 {
lab=out3v3}
N -150 270 -110 270 {
lab=dvdd}
N -150 300 -110 300 {
lab=dvss}
N -150 330 -110 330 {
lab=avdd}
C {lsbuflv2hv_1.sym} -30 30 0 0 {name=x2 LVPWR=dvdd VGND=dvss VNB=dvss VPB=avdd VPWR=avdd prefix=sky130_fd_sc_hvl__ }
C {devices/ipin.sym} -120 30 0 0 {name=p1 lab=in1v8}
C {sky130_stdcells/inv_2.sym} -20 200 0 0 {name=x4 VGND=dvss VNB=dvss VPB=avdd VPWR=avdd prefix=sky130_fd_sc_hvl__ }
C {devices/iopin.sym} -150 270 0 1 {name=p9 lab=dvdd}
C {devices/lab_pin.sym} -110 270 0 1 {name=p10 sig_type=std_logic lab=dvdd}
C {devices/iopin.sym} -150 300 0 1 {name=p11 lab=dvss}
C {devices/lab_pin.sym} -110 300 0 1 {name=p12 sig_type=std_logic lab=dvss}
C {devices/iopin.sym} -150 330 0 1 {name=p13 lab=avdd}
C {devices/lab_pin.sym} -110 330 0 1 {name=p15 sig_type=std_logic lab=avdd}
C {devices/opin.sym} 50 30 0 0 {name=p17 lab=out3v3}
C {devices/opin.sym} 50 200 0 0 {name=p18 lab=outb3v3}
