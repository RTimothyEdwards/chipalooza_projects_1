v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
N 430 80 560 80 {
lab=avdd}
N 430 180 460 180 {
lab=avss}
N 460 180 460 220 {
lab=avss}
N 560 80 560 220 {
lab=avdd}
N 460 280 560 280 {
lab=GND}
N 430 160 650 160 {
lab=source0}
N 650 160 650 210 {
lab=source0}
N 650 210 650 220 {
lab=source0}
N 430 140 720 140 {
lab=source1}
N 740 140 740 220 {
lab=source1}
N 430 120 720 120 {
lab=sink0}
N 740 40 740 120 {
lab=sink0}
N 430 100 650 100 {
lab=sink1}
N 650 40 650 100 {
lab=sink1}
N 570 -20 720 -20 {
lab=avdd}
N 560 -20 560 80 {
lab=avdd}
N 560 -20 570 -20 {
lab=avdd}
N 90 280 460 280 {
lab=GND}
N 20 280 90 280 {
lab=GND}
N 20 160 130 160 {
lab=ena}
N 20 180 130 180 {
lab=ena}
N 20 200 130 200 {
lab=ena}
N -50 280 20 280 {
lab=GND}
N -50 120 -50 220 {
lab=enb}
N -50 120 130 120 {
lab=enb}
N -140 280 -50 280 {
lab=GND}
N -140 80 -140 220 {
lab=ref}
N -140 80 130 80 {
lab=ref}
N 20 160 20 220 {
lab=ena}
N -50 140 130 140 {
lab=enb}
N -50 100 130 100 {
lab=enb}
N -50 100 -50 120 {
lab=enb}
N 560 280 720 280 {
lab=GND}
N 720 140 740 140 {
lab=source1}
N 720 120 740 120 {
lab=sink0}
N 720 -20 740 -20 {
lab=avdd}
N 720 280 740 280 {
lab=GND}
C {bias_generator_test.sym} 280 140 0 0 {name=x1}
C {devices/vsource.sym} 560 250 0 0 {name=Vvdd value=3.3 savecurrent=false}
C {devices/vsource.sym} 460 250 0 0 {name=Vvss value=0 savecurrent=false}
C {devices/gnd.sym} 500 280 0 0 {name=l1 lab=GND}
C {devices/vsource.sym} 650 250 0 0 {name=Vsource0 value=1 savecurrent=false}
C {devices/vsource.sym} 740 250 0 0 {name=Vsource1 value=1.5 savecurrent=false}
C {devices/vsource.sym} 650 10 0 0 {name=Vsink1 value=1 savecurrent=false}
C {devices/vsource.sym} 740 10 0 0 {name=Vsink0 value=1.5 savecurrent=false}
C {devices/lab_pin.sym} 740 140 0 1 {name=p1 sig_type=std_logic lab=source1}
C {devices/lab_pin.sym} 650 160 0 1 {name=p2 sig_type=std_logic lab=source0}
C {devices/lab_pin.sym} 740 120 0 1 {name=p3 sig_type=std_logic lab=sink0}
C {devices/lab_pin.sym} 650 100 0 1 {name=p4 sig_type=std_logic lab=sink1}
C {devices/vsource.sym} 20 250 0 0 {name=Vena value=3.3 savecurrent=false}
C {devices/vsource.sym} -50 250 0 0 {name=Venb value=0 savecurrent=false}
C {devices/vsource.sym} -140 250 0 0 {name=Vref value=DC 3.3 savecurrent=false}
C {devices/lab_wire.sym} 90 80 0 0 {name=p5 sig_type=std_logic lab=ref}
C {devices/lab_wire.sym} 90 200 0 0 {name=p6 sig_type=std_logic lab=ena}
C {devices/lab_wire.sym} 90 120 0 0 {name=p7 sig_type=std_logic lab=enb}
C {devices/lab_wire.sym} 440 180 0 1 {name=p8 sig_type=std_logic lab=avss}
C {devices/lab_wire.sym} 450 80 0 1 {name=p9 sig_type=std_logic lab=avdd}
C {devices/code_shown.sym} -230 -150 0 0 {name=s1 only_toplevel=false value=".option savecurrents
.control
save all
dc Vref 2 3.3 0.1
print I(Vsink1) I(vsink0) I(vsource0) I(vsource1)
print I(v.x1.vmeas) I(v.x1.vmeas1) I(v.x1.vmeas2) I(v.x1.vmeas3) I(v.x1.vmeas4) I(v.x1.vmeas5)
.endc"}
C {devices/code_shown.sym} 350 -130 0 0 {name=s2 only_toplevel=false value=".lib /usr/share/pdk/sky130A/libs.tech/combined/sky130.lib.spice tt
"}
