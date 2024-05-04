v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {48x48 grid} 1760 -880 0 0 0.4 0.4 {}
T {Power switch with waffle pFET power transistor} 930 -1120 0 0 0.4 0.4 {}
N 1630 -840 1630 -720 { lab=SW_NODE}
N 1630 -920 1630 -900 { lab=VDD_PWR}
N 1630 -920 1870 -920 { lab=VDD_PWR}
N 1630 -870 1650 -870 { lab=VDD_PWR}
N 1650 -920 1650 -870 { lab=VDD_PWR}
N 1500 -920 1660 -920 {
lab=VDD_PWR}
N 910 -830 1080 -830 {
lab=VDD_PWR}
N 1010 -810 1080 -810 {
lab=VSS}
N 1010 -790 1080 -790 {
lab=DVSS}
N 430 -1040 480 -1040 {
lab=P_IN}
N 480 -1040 480 -1010 {
lab=P_IN}
N 480 -1010 730 -1010 {
lab=P_IN}
N 810 -1010 840 -1010 {
lab=#net1}
N 920 -1010 960 -1010 {
lab=#net2}
N 820 -1010 820 -870 {
lab=#net1}
N 820 -870 1080 -870 {
lab=#net1}
N 960 -1010 960 -850 {
lab=#net2}
N 960 -850 1080 -850 {
lab=#net2}
N 1380 -870 1590 -870 {
lab=P_DRIVE}
C {devices/ipin.sym} 430 -1040 0 0 {name=p5 lab=P_IN}
C {devices/ipin.sym} 1630 -720 0 0 {name=p9 lab=SW_NODE}
C {devices/ipin.sym} 1500 -920 0 0 {name=p1 lab=VDD_PWR}
C {devices/ipin.sym} 1010 -810 0 0 {name=p3 lab=VSS}
C {sky130_fd_pr/pfet_g5v0d10v5.sym} 1610 -870 0 0 {name=M14
L=0.5
W=4.38
nf=1
mult=4512
ad="'int((nf+1)/2) * W/nf * 0.29'" 
pd="'2*int((nf+1)/2) * (W/nf + 0.29)'"
as="'int((nf+2)/2) * W/nf * 0.29'" 
ps="'2*int((nf+2)/2) * (W/nf + 0.29)'"
nrd="'0.29 / W'" nrs="'0.29 / W'"
sa=0 sb=0 sd=0
model=pfet_g5v0d10v5
spiceprefix=X
}
C {devices/lab_wire.sym} 1800 -920 0 0 {name=l10 sig_type=std_logic lab=VDD_PWR}
C {devices/lab_wire.sym} 1630 -770 0 0 {name=l17 sig_type=std_logic lab=SW_NODE}
C {gate_drive.sym} 1230 -830 0 0 {name=x2}
C {devices/lab_wire.sym} 1400 -870 0 1 {name=l30 sig_type=std_logic lab=P_DRIVE}
C {devices/lab_wire.sym} 910 -830 0 0 {name=l33 sig_type=std_logic lab=VDD_PWR}
C {devices/ipin.sym} 1010 -790 0 0 {name=p2 lab=DVSS}
C {sky130_stdcells/inv_4.sym} 770 -1010 0 0 {name=x1 VGND=DVSS VNB=DVSS VPB=DVDD VPWR=DVDD prefix=sky130_fd_sc_hd__ }
C {sky130_stdcells/inv_4.sym} 880 -1010 0 0 {name=x3 VGND=DVSS VNB=DVSS VPB=DVDD VPWR=DVDD prefix=sky130_fd_sc_hd__ }
C {sky130_stdcells/decap_3.sym} 570 -900 0 0 {name=x4[1:0] VGND=DVSS VNB=DVSS VPB=DVDD VPWR=DVDD prefix=sky130_fd_sc_hd__ }
C {sky130_stdcells/tapvpwrvgnd_1.sym} 570 -940 0 0 {name=x6[2:0] VGND=DVSS VPWR=DVDD prefix=sky130_fd_sc_hd__ }
C {sky130_stdcells/diode_2.sym} 570 -1040 0 0 {name=x9 VGND=DVSS VNB=DVSS VPB=DVDD VPWR=DVDD prefix=sky130_fd_sc_hd__ }
C {devices/ipin.sym} 1010 -730 0 0 {name=p4 lab=DVDD}
