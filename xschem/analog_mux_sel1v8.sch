v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {Analog multiplexer with ground-isolated switches and 1.8V select} -190 -90 0 0 0.4 0.4 {}
N 10 30 50 30 {
lab=#net1}
N 350 30 380 30 {
lab=avss}
N 380 -10 380 30 {
lab=avss}
N 380 -10 410 -10 {
lab=avss}
N 350 50 410 50 {
lab=inA}
N 350 70 410 70 {
lab=out}
N 350 90 380 90 {
lab=avdd}
N 380 90 380 120 {
lab=avdd}
N 380 120 410 120 {
lab=avdd}
N 20 200 50 200 {
lab=#net2}
N 30 30 30 120 {
lab=#net1}
N -60 120 30 120 {
lab=#net1}
N -60 120 -60 200 {
lab=#net1}
N 350 260 380 260 {
lab=avdd}
N 380 260 380 310 {
lab=avdd}
N 380 310 420 310 {
lab=avdd}
N 410 70 480 70 {
lab=out}
N 480 70 480 240 {
lab=out}
N 350 240 480 240 {
lab=out}
N 480 240 510 240 {
lab=out}
N 350 220 420 220 {
lab=inB}
N 350 200 380 200 {
lab=avss}
N 380 160 380 200 {
lab=avss}
N 380 160 410 160 {
lab=avss}
N -180 270 -140 270 {
lab=dvdd}
N -180 250 -140 250 {
lab=dvss}
N -170 30 -70 30 {
lab=selA}
N -140 30 -140 70 {
lab=selA}
N -140 130 -140 250 {
lab=dvss}
C {isolated_switch.sym} 200 60 0 0 {name=x1}
C {lsbuflv2hv_1.sym} -30 30 0 0 {name=x2 LVPWR=dvdd VGND=dvss VNB=dvss VPB=avdd VPWR=avdd prefix=sky130_fd_sc_hvl__ }
C {devices/ipin.sym} -170 30 0 0 {name=p1 lab=selA}
C {devices/iopin.sym} 410 -10 0 0 {name=p2 lab=avss}
C {devices/iopin.sym} 510 240 0 0 {name=p3 lab=out}
C {devices/iopin.sym} 410 50 0 0 {name=p4 lab=inA}
C {devices/iopin.sym} 410 120 0 0 {name=p5 lab=avdd}
C {isolated_switch.sym} 200 230 0 0 {name=x3}
C {sky130_stdcells/inv_2.sym} -20 200 0 0 {name=x4 VGND=dvss VNB=dvss VPB=avdd VPWR=avdd prefix=sky130_fd_sc_hvl__ }
C {devices/lab_pin.sym} 420 310 0 1 {name=p6 sig_type=std_logic lab=avdd}
C {devices/iopin.sym} 420 220 0 0 {name=p7 lab=inB}
C {devices/lab_pin.sym} 410 160 0 1 {name=p8 sig_type=std_logic lab=avss}
C {devices/iopin.sym} -180 270 0 1 {name=p9 lab=dvdd}
C {devices/lab_pin.sym} -140 270 0 1 {name=p10 sig_type=std_logic lab=dvdd}
C {devices/iopin.sym} -180 250 0 1 {name=p11 lab=dvss}
C {devices/lab_pin.sym} -140 250 0 1 {name=p12 sig_type=std_logic lab=dvss}
C {sky130_fd_pr/diode.sym} -140 100 0 0 {name=D1
model=diode_pw2nd_05v5
area=2.304e11
perim=1.92e6
spiceprefix=X
}
