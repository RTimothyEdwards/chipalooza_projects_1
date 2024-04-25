v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {48x48 grid} 1110 -600 0 0 0.4 0.4 {}
T {Power switch with waffle pFET power transistor} 750 -1180 0 0 0.4 0.4 {}
N 980 -560 980 -440 { lab=SW_NODE}
N 980 -640 980 -620 { lab=VDD_PWR}
N 980 -640 1220 -640 { lab=VDD_PWR}
N 980 -590 1000 -590 { lab=VDD_PWR}
N 1000 -640 1000 -590 { lab=VDD_PWR}
N 900 -590 940 -590 { lab=P_DRIVE}
N 1050 -780 1070 -780 { lab=VSS}
N 1070 -800 1070 -780 { lab=VSS}
N 890 -960 910 -960 { lab=P_IN}
N 1070 -1060 1070 -1040 { lab=VDD_PWR}
N 890 -880 910 -880 { lab=P_IN_N}
N 1230 -920 1250 -920 { lab=P_DRIVE}
N 990 -780 1050 -780 {
lab=VSS}
N 820 -960 890 -960 {
lab=P_IN}
N 820 -880 890 -880 {
lab=P_IN_N}
N 850 -640 1010 -640 {
lab=VDD_PWR}
C {devices/ipin.sym} 820 -960 0 0 {name=p5 lab=P_IN}
C {devices/ipin.sym} 820 -880 0 0 {name=p6 lab=P_IN_N}
C {devices/ipin.sym} 980 -440 0 0 {name=p9 lab=SW_NODE}
C {devices/ipin.sym} 850 -640 0 0 {name=p1 lab=VDD_PWR}
C {devices/ipin.sym} 990 -780 0 0 {name=p3 lab=VSS}
C {sky130_fd_pr/pfet_g5v0d10v5.sym} 960 -590 0 0 {name=M14
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
C {devices/lab_wire.sym} 900 -590 0 0 {name=l8 sig_type=std_logic lab=P_DRIVE}
C {devices/lab_wire.sym} 1150 -640 0 0 {name=l10 sig_type=std_logic lab=VDD_PWR}
C {devices/lab_wire.sym} 980 -490 0 0 {name=l17 sig_type=std_logic lab=SW_NODE}
C {gate_drive.sym} 1070 -920 0 0 {name=x2}
C {devices/lab_wire.sym} 1050 -780 0 0 {name=l26 sig_type=std_logic lab=VSS}
C {devices/lab_wire.sym} 1250 -920 0 1 {name=l30 sig_type=std_logic lab=P_DRIVE}
C {devices/lab_wire.sym} 890 -960 0 0 {name=l31 sig_type=std_logic lab=P_IN}
C {devices/lab_wire.sym} 890 -880 0 0 {name=l32 sig_type=std_logic lab=P_IN_N}
C {devices/lab_wire.sym} 1070 -1060 0 0 {name=l33 sig_type=std_logic lab=VDD_PWR}
