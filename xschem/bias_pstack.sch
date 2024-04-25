v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {50nA} 180 -120 0 0 0.4 0.4 {}
N 190 -510 230 -510 {
lab=avdd}
N 190 -570 190 -540 {
lab=avdd}
N 190 -300 190 -260 {
lab=itail}
N 190 -330 230 -330 {
lab=avdd}
N 190 -200 190 -160 {
lab=itail}
N 230 -570 230 -330 {
lab=avdd}
N 190 -400 190 -360 {
lab=vcasc}
N 190 -480 190 -460 {
lab=#net1}
N 190 -260 190 -200 {
lab=itail}
N 190 -430 230 -430 {
lab=avdd}
N 60 -430 150 -430 {
lab=pcasc}
N 60 -510 150 -510 {
lab=pbias}
N 60 -570 230 -570 {
lab=avdd}
N 100 -330 150 -330 {
lab=enb}
N 60 -380 190 -380 {
lab=vcasc}
N 120 -330 120 -280 {
lab=enb}
N 120 -220 120 -160 {
lab=avss}
N 80 -160 120 -160 {
lab=avss}
C {sky130_fd_pr/pfet_g5v0d10v5.sym} 170 -510 0 0 {name=M13
W=3
L=1
nf=1
mult=1
ad="'int((nf+1)/2) * W/nf * 0.29'" 
pd="'2*int((nf+1)/2) * (W/nf + 0.29)'"
as="'int((nf+2)/2) * W/nf * 0.29'" 
ps="'2*int((nf+2)/2) * (W/nf + 0.29)'"
nrd="'0.29 / W'" nrs="'0.29 / W'"
sa=0 sb=0 sd=0
model=pfet_g5v0d10v5
spiceprefix=X
}
C {devices/iopin.sym} 60 -570 0 1 {name=p6 lab=avdd}
C {devices/iopin.sym} 190 -160 0 0 {name=p8 lab=itail}
C {sky130_fd_pr/pfet_g5v0d10v5.sym} 170 -330 0 0 {name=M18
W=3
L=1
nf=1
mult=1
ad="'int((nf+1)/2) * W/nf * 0.29'" 
pd="'2*int((nf+1)/2) * (W/nf + 0.29)'"
as="'int((nf+2)/2) * W/nf * 0.29'" 
ps="'2*int((nf+2)/2) * (W/nf + 0.29)'"
nrd="'0.29 / W'" nrs="'0.29 / W'"
sa=0 sb=0 sd=0
model=pfet_g5v0d10v5
spiceprefix=X
}
C {devices/ipin.sym} 100 -330 0 0 {name=p12 lab=enb}
C {devices/lab_wire.sym} 130 -510 0 0 {name=p16 sig_type=std_logic lab=pbias}
C {sky130_fd_pr/pfet_g5v0d10v5.sym} 170 -430 0 0 {name=M14
W=3
L=1
nf=1
mult=1
ad="'int((nf+1)/2) * W/nf * 0.29'" 
pd="'2*int((nf+1)/2) * (W/nf + 0.29)'"
as="'int((nf+2)/2) * W/nf * 0.29'" 
ps="'2*int((nf+2)/2) * (W/nf + 0.29)'"
nrd="'0.29 / W'" nrs="'0.29 / W'"
sa=0 sb=0 sd=0
model=pfet_g5v0d10v5
spiceprefix=X
}
C {devices/lab_wire.sym} 130 -430 0 0 {name=p17 sig_type=std_logic lab=pcasc}
C {devices/ipin.sym} 60 -430 0 0 {name=p1 lab=pcasc}
C {devices/iopin.sym} 60 -380 0 1 {name=p2 lab=vcasc}
C {devices/ipin.sym} 60 -510 0 0 {name=p3 lab=pbias}
C {sky130_fd_pr/diode.sym} 120 -250 0 0 {name=D1
model=diode_pw2nd_05v5
area=2.025e11
perim=1.8e6
spiceprefix=X
}
C {devices/iopin.sym} 80 -160 0 1 {name=p5 lab=avss}
