v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {50nA} -200 -330 0 0 0.4 0.4 {}
N -140 60 -40 60 {
lab=nbias}
N -180 90 -180 110 {
lab=avss}
N -220 60 -180 60 {
lab=avss}
N -140 -0 -140 60 {
lab=nbias}
N -220 60 -220 110 {
lab=avss}
N -180 -30 -180 30 {
lab=#net1}
N -140 -60 -140 -0 {
lab=nbias}
N -220 -60 -180 -60 {
lab=avss}
N -220 -60 -220 60 {
lab=avss}
N -180 -220 -180 -190 {
lab=itail}
N -220 -160 -180 -160 {
lab=avss}
N -220 -160 -220 -60 {
lab=avss}
N -180 -130 -180 -90 {
lab=vcasc}
N -180 -280 -180 -220 {
lab=itail}
N -220 110 -180 110 {
lab=avss}
N -180 110 -110 110 {
lab=avss}
N -180 -280 -110 -280 {
lab=itail}
N -180 -110 -100 -110 {
lab=vcasc}
N -140 -160 30 -160 {
lab=ena}
N -0 -160 0 -90 {
lab=ena}
N 0 -30 -0 -0 {
lab=avss}
C {sky130_fd_pr/nfet_g5v0d10v5.sym} -160 60 0 1 {name=M3
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
model=nfet_g5v0d10v5
spiceprefix=X
}
C {devices/iopin.sym} -110 110 0 0 {name=p4 lab=avss}
C {devices/ipin.sym} 30 -160 0 1 {name=p5 lab=ena}
C {sky130_fd_pr/nfet_05v0_nvt.sym} -160 -60 0 1 {name=M6
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
model=nfet_05v0_nvt
spiceprefix=X
}
C {sky130_fd_pr/nfet_g5v0d10v5.sym} -160 -160 0 1 {name=M12
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
model=nfet_g5v0d10v5
spiceprefix=X
}
C {devices/ipin.sym} -40 60 0 1 {name=p1 lab=nbias}
C {devices/iopin.sym} -110 -280 0 0 {name=p2 lab=itail}
C {devices/iopin.sym} -100 -110 0 0 {name=p3 lab=vcasc}
C {sky130_fd_pr/diode.sym} 0 -60 0 0 {name=D1
model=diode_pw2nd_05v5
area=2.025e11
perim=1.8e6
spiceprefix=X
}
C {devices/lab_pin.sym} 0 0 0 0 {name=p6 sig_type=std_logic lab=avss}
