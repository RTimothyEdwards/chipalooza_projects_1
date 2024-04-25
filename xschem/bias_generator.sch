v {xschem version=3.4.5 file_version=1.2
}
G {}
K {}
V {}
S {}
E {}
T {1uA} -720 -50 0 0 0.4 0.4 {}
T {50nA} -1130 -530 0 0 0.4 0.4 {}
T {50nA} -1150 -50 0 0 0.4 0.4 {}
T {100nA} -220 -530 0 0 0.4 0.4 {}
T {100nA} 150 -540 0 0 0.4 0.4 {}
T {100nA} -210 -40 0 0 0.4 0.4 {}
T {Make a single source modular and tile together as many as needed to make the
current needed by the target circuit.} -110 -630 0 0 0.4 0.4 {}
T {100nA} 130 -30 0 0 0.4 0.4 {}
T {10uA} 540 -540 0 0 0.4 0.4 {}
T {10uA} 890 -540 0 0 0.4 0.4 {}
T {5uA} 460 -40 0 0 0.4 0.4 {}
T {5uA} 820 -40 0 0 0.4 0.4 {}
T {5uA} 1180 -40 0 0 0.4 0.4 {}
T {600nA} 1290 -530 0 0 0.4 0.4 {}
T {400nA} 1680 -530 0 0 0.4 0.4 {}
T {200nA} 2060 -530 0 0 0.4 0.4 {}
T {200nA} 2440 -530 0 0 0.4 0.4 {}
T {200nA} 2810 -530 0 0 0.4 0.4 {}
T {100nA} 3180 -530 0 0 0.4 0.4 {}
T {50nA} 3550 -530 0 0 0.4 0.4 {}
T {3.75uA} 1530 -40 0 0 0.4 0.4 {}
T {2uA} 1880 -40 0 0 0.4 0.4 {}
T {mirror 1:20} -1170 20 0 0 0.4 0.4 {}
T {mirror 1:1} -1160 -590 0 0 0.4 0.4 {}
N -500 -400 -500 -370 {
lab=ref_in}
N -500 -310 -500 -260 {
lab=pcasc}
N -480 -340 -450 -340 {
lab=avss}
N -450 -340 -450 -230 {
lab=avss}
N -480 -230 -450 -230 {
lab=avss}
N -530 -160 -500 -160 {
lab=#net1}
N -870 -160 -830 -160 {
lab=ena}
N -830 -140 -830 -80 {
lab=nbias}
N -830 -80 -510 -80 {
lab=nbias}
N -510 -140 -510 -80 {
lab=nbias}
N -530 -140 -510 -140 {
lab=nbias}
N -1310 -160 -1270 -160 {
lab=ena}
N -1290 -220 -1290 -160 {
lab=ena}
N -1290 -220 -870 -220 {
lab=ena}
N -870 -220 -870 -160 {
lab=ena}
N -970 -120 -970 -60 {
lab=avss}
N -970 -60 -450 -60 {
lab=avss}
N -530 -120 -530 -60 {
lab=avss}
N -1270 -80 -830 -80 {
lab=nbias}
N -1270 -140 -1270 -80 {
lab=nbias}
N -970 -160 -930 -160 {
lab=#net2}
N -1330 -370 -1280 -370 {
lab=enb}
N -980 -410 -940 -410 {
lab=avdd}
N -940 -490 -940 -410 {
lab=avdd}
N -1330 -490 -940 -490 {
lab=avdd}
N -980 -370 -900 -370 {
lab=pbias}
N -1280 -450 -900 -450 {
lab=pbias}
N -1280 -450 -1280 -410 {
lab=pbias}
N -1310 -470 -880 -470 {
lab=pcasc}
N -1310 -470 -1310 -390 {
lab=pcasc}
N -1310 -390 -1280 -390 {
lab=pcasc}
N -500 -200 -500 -160 {
lab=#net1}
N -450 -230 -450 -60 {
lab=avss}
N -880 -470 380 -470 {
lab=pcasc}
N -900 -450 390 -450 {
lab=pbias}
N -940 -490 380 -490 {
lab=avdd}
N -1330 -60 -970 -60 {
lab=avss}
N -450 -60 390 -60 {
lab=avss}
N -510 -80 380 -80 {
lab=nbias}
N -330 -450 -330 -400 {
lab=pbias}
N -360 -380 -330 -380 {
lab=pcasc}
N -360 -470 -360 -380 {
lab=pcasc}
N -330 -140 -330 -80 {
lab=nbias}
N -30 -120 -30 -60 {
lab=avss}
N -30 -490 -30 -400 {
lab=avdd}
N -30 -320 -30 -280 {
lab=src_test0}
N -330 -360 -330 -300 {
lab=enb_test0}
N -330 -210 -330 -160 {
lab=ena_test0}
N -30 -200 -30 -160 {
lab=snk_test0}
N 0 -140 0 -80 {
lab=nbias}
N 300 -120 300 -60 {
lab=avss}
N 0 -210 0 -160 {
lab=ena_test1}
N 300 -200 300 -160 {
lab=snk_test1}
N 40 -450 40 -400 {
lab=pbias}
N 10 -380 40 -380 {
lab=pcasc}
N 10 -470 10 -380 {
lab=pcasc}
N 340 -490 340 -400 {
lab=avdd}
N 340 -320 340 -280 {
lab=src_test1}
N 40 -360 40 -300 {
lab=enb_test1}
N 410 -450 410 -400 {
lab=pbias}
N 380 -380 410 -380 {
lab=pcasc}
N 380 -470 380 -380 {
lab=pcasc}
N 710 -490 710 -400 {
lab=avdd}
N 710 -320 710 -280 {
lab=src_10000_0}
N 410 -360 410 -300 {
lab=enb_10000_0}
N 380 -490 1040 -490 {
lab=avdd}
N 380 -470 1040 -470 {
lab=pcasc}
N 390 -450 1040 -450 {
lab=pbias}
N 340 -140 340 -80 {
lab=nbias}
N 640 -120 640 -60 {
lab=avss}
N 340 -210 340 -160 {
lab=ena_5000_0}
N 640 -200 640 -160 {
lab=snk_5000_0}
N 390 -60 1050 -60 {
lab=avss}
N 790 -450 790 -400 {
lab=pbias}
N 760 -380 790 -380 {
lab=pcasc}
N 760 -470 760 -380 {
lab=pcasc}
N 1090 -490 1090 -400 {
lab=avdd}
N 1090 -320 1090 -280 {
lab=src_10000_1}
N 790 -360 790 -300 {
lab=enb_10000_1}
N 710 -140 710 -80 {
lab=nbias}
N 1010 -120 1010 -60 {
lab=avss}
N 710 -210 710 -160 {
lab=ena_5000_1}
N 1010 -200 1010 -160 {
lab=snk_5000_1}
N 1070 -140 1070 -80 {
lab=nbias}
N 1370 -120 1370 -60 {
lab=avss}
N 1070 -210 1070 -160 {
lab=ena_5000_2}
N 1370 -200 1370 -160 {
lab=snk_5000_2}
N 1050 -60 1690 -60 {
lab=avss}
N 1180 -450 1180 -400 {
lab=pbias}
N 1150 -380 1180 -380 {
lab=pcasc}
N 1150 -470 1150 -380 {
lab=pcasc}
N 1480 -490 1480 -400 {
lab=avdd}
N 1480 -320 1480 -280 {
lab=src_600}
N 1180 -360 1180 -300 {
lab=enb_600}
N 1040 -490 1960 -490 {
lab=avdd}
N 1040 -470 1960 -470 {
lab=pcasc}
N 1040 -450 1960 -450 {
lab=pbias}
N 1570 -450 1570 -400 {
lab=pbias}
N 1540 -380 1570 -380 {
lab=pcasc}
N 1540 -470 1540 -380 {
lab=pcasc}
N 1870 -490 1870 -400 {
lab=avdd}
N 1870 -320 1870 -280 {
lab=src_400}
N 1570 -360 1570 -300 {
lab=enb_400}
N 1950 -450 1950 -400 {
lab=pbias}
N 1920 -380 1950 -380 {
lab=pcasc}
N 1920 -470 1920 -380 {
lab=pcasc}
N 2250 -490 2250 -400 {
lab=avdd}
N 1950 -360 1950 -300 {
lab=enb_200_0}
N 1960 -450 2880 -450 {
lab=pbias}
N 1960 -470 2870 -470 {
lab=pcasc}
N 1960 -490 2870 -490 {
lab=avdd}
N 2330 -450 2330 -400 {
lab=pbias}
N 2300 -380 2330 -380 {
lab=pcasc}
N 2300 -470 2300 -380 {
lab=pcasc}
N 2630 -490 2630 -400 {
lab=avdd}
N 2630 -320 2630 -280 {
lab=src_200_1}
N 2330 -360 2330 -300 {
lab=enb_200_1}
N 2700 -450 2700 -400 {
lab=pbias}
N 2670 -380 2700 -380 {
lab=pcasc}
N 2670 -470 2670 -380 {
lab=pcasc}
N 3000 -490 3000 -400 {
lab=avdd}
N 3000 -320 3000 -280 {
lab=src_200_2}
N 2700 -360 2700 -300 {
lab=enb_200_2}
N 2870 -490 3620 -490 {
lab=avdd}
N 3070 -450 3070 -400 {
lab=pbias}
N 3040 -380 3070 -380 {
lab=pcasc}
N 3040 -470 3040 -380 {
lab=pcasc}
N 3370 -490 3370 -400 {
lab=avdd}
N 3370 -320 3370 -280 {
lab=src_100}
N 3070 -360 3070 -300 {
lab=enb_100}
N 3440 -450 3440 -400 {
lab=pbias}
N 3410 -380 3440 -380 {
lab=pcasc}
N 3410 -470 3410 -380 {
lab=pcasc}
N 3740 -490 3740 -400 {
lab=avdd}
N 3740 -320 3740 -280 {
lab=src_50}
N 3440 -360 3440 -300 {
lab=enb_50}
N 3620 -490 3740 -490 {
lab=avdd}
N 2870 -470 3410 -470 {
lab=pcasc}
N 2880 -450 3440 -450 {
lab=pbias}
N 1420 -140 1420 -80 {
lab=nbias}
N 1720 -120 1720 -60 {
lab=avss}
N 1420 -210 1420 -160 {
lab=ena_3700}
N 1720 -200 1720 -160 {
lab=snk_3700}
N 1690 -60 1720 -60 {
lab=avss}
N 1770 -140 1770 -80 {
lab=nbias}
N 2070 -120 2070 -60 {
lab=avss}
N 1770 -210 1770 -160 {
lab=ena_2000}
N 2070 -200 2070 -160 {
lab=snk_2000}
N 2040 -60 2070 -60 {
lab=avss}
N 1720 -60 2040 -60 {
lab=avss}
N 1420 -80 1770 -80 {
lab=nbias}
N -980 -330 -930 -330 {
lab=#net2}
N -930 -330 -930 -160 {
lab=#net2}
N -980 -350 -920 -350 {
lab=avss}
N -920 -350 -920 -60 {
lab=avss}
N 2250 -320 2250 -290 {
lab=src_200_0}
N -30 -340 -20 -340 {
lab=avss}
N -20 -340 -20 -60 {
lab=avss}
N 340 -340 360 -340 {
lab=avss}
N 360 -340 360 -250 {
lab=avss}
N 320 -250 360 -250 {
lab=avss}
N 320 -250 320 -60 {
lab=avss}
N 710 -340 730 -340 {
lab=avss}
N 730 -340 730 -250 {
lab=avss}
N 690 -250 730 -250 {
lab=avss}
N 690 -250 690 -60 {
lab=avss}
N 1090 -340 1110 -340 {
lab=avss}
N 1110 -340 1110 -240 {
lab=avss}
N 1050 -240 1110 -240 {
lab=avss}
N 1050 -240 1050 -60 {
lab=avss}
N 1480 -340 1510 -340 {
lab=avss}
N 1510 -340 1510 -240 {
lab=avss}
N 1400 -240 1510 -240 {
lab=avss}
N 1400 -240 1400 -60 {
lab=avss}
N 1870 -340 1890 -340 {
lab=avss}
N 1890 -340 1890 -250 {
lab=avss}
N 1750 -250 1890 -250 {
lab=avss}
N 1750 -250 1750 -60 {
lab=avss}
N 2070 -60 3760 -60 {
lab=avss}
N 2250 -340 2280 -340 {
lab=avss}
N 2280 -340 2280 -60 {
lab=avss}
N 2630 -340 2660 -340 {
lab=avss}
N 2660 -340 2660 -60 {
lab=avss}
N 3000 -340 3030 -340 {
lab=avss}
N 3030 -340 3030 -60 {
lab=avss}
N 3370 -340 3400 -340 {
lab=avss}
N 3400 -340 3400 -60 {
lab=avss}
N 3740 -340 3760 -340 {
lab=avss}
N 3760 -340 3760 -60 {
lab=avss}
N 380 -80 1420 -80 {
lab=nbias}
N -620 -290 -500 -290 {
lab=pcasc}
N -620 -470 -620 -290 {
lab=pcasc}
N -900 -450 -900 -370 {}
C {bias_nstack.sym} -680 -140 0 0 {name=x2[19:0]}
C {sky130_fd_pr/res_high_po_0p35.sym} -500 -230 0 1 {name=R3
L=900
model=res_high_po_0p35
spiceprefix=X
mult=1}
C {devices/ipin.sym} -500 -400 0 0 {name=p38 lab=ref_in}
C {sky130_fd_pr/res_high_po_0p35.sym} -500 -340 0 1 {name=R4
L=1500
model=res_high_po_0p35
spiceprefix=X
mult=1}
C {devices/iopin.sym} -1330 -60 0 1 {name=p39 lab=avss}
C {devices/ipin.sym} -1310 -160 0 0 {name=p40 lab=ena}
C {bias_nstack.sym} -1120 -140 0 0 {name=x4}
C {bias_pstack.sym} -1130 -370 0 0 {name=x2}
C {devices/ipin.sym} -1330 -370 0 0 {name=p41 lab=enb}
C {devices/iopin.sym} -1330 -490 0 1 {name=p42 lab=avdd}
C {bias_pstack.sym} -180 -360 0 0 {name=x13[1:0]}
C {bias_nstack.sym} -180 -140 0 0 {name=x17[1:0]}
C {devices/lab_wire.sym} -390 -80 0 0 {name=p43 sig_type=std_logic lab=nbias}
C {devices/lab_wire.sym} -450 -450 0 0 {name=p44 sig_type=std_logic lab=pbias}
C {devices/lab_wire.sym} -450 -470 0 0 {name=p45 sig_type=std_logic lab=pcasc}
C {devices/ipin.sym} -330 -300 0 1 {name=p46 lab=enb_test0}
C {devices/ipin.sym} -330 -210 0 1 {name=p47 lab=ena_test0}
C {devices/iopin.sym} -30 -280 0 1 {name=p48 lab=src_test0}
C {devices/iopin.sym} -30 -200 0 1 {name=p49 lab=snk_test0}
C {bias_nstack.sym} 150 -140 0 0 {name=x18[1:0]}
C {devices/ipin.sym} 0 -210 0 1 {name=p50 lab=ena_test1}
C {devices/iopin.sym} 300 -200 0 1 {name=p51 lab=snk_test1}
C {bias_pstack.sym} 190 -360 0 0 {name=x16[1:0]}
C {devices/ipin.sym} 40 -300 0 1 {name=p52 lab=enb_test1}
C {devices/iopin.sym} 340 -280 0 1 {name=p53 lab=src_test1}
C {bias_pstack.sym} 560 -360 0 0 {name=x8[199:0]}
C {devices/ipin.sym} 410 -300 0 1 {name=p54 lab=enb_10000_0}
C {devices/iopin.sym} 710 -280 0 1 {name=p55 lab=src_10000_0}
C {bias_nstack.sym} 490 -140 0 0 {name=x9[99:0]}
C {devices/ipin.sym} 340 -210 0 1 {name=p56 lab=ena_5000_0}
C {devices/iopin.sym} 640 -200 0 1 {name=p57 lab=snk_5000_0}
C {bias_pstack.sym} 940 -360 0 0 {name=x10[199:0]}
C {devices/ipin.sym} 790 -300 0 1 {name=p58 lab=enb_10000_1}
C {devices/iopin.sym} 1090 -280 0 1 {name=p59 lab=src_10000_1}
C {bias_nstack.sym} 860 -140 0 0 {name=x1[99:0]}
C {devices/ipin.sym} 710 -210 0 1 {name=p60 lab=ena_5000_1}
C {devices/iopin.sym} 1010 -200 0 1 {name=p61 lab=snk_5000_1}
C {bias_nstack.sym} 1220 -140 0 0 {name=x3[99:0]}
C {devices/ipin.sym} 1070 -210 0 1 {name=p62 lab=ena_5000_2}
C {devices/iopin.sym} 1370 -200 0 1 {name=p63 lab=snk_5000_2}
C {bias_pstack.sym} 1330 -360 0 0 {name=x4[11:0]}
C {devices/ipin.sym} 1180 -300 0 1 {name=p64 lab=enb_600}
C {devices/iopin.sym} 1480 -280 0 1 {name=p65 lab=src_600}
C {bias_pstack.sym} 1720 -360 0 0 {name=x5[7:0]}
C {devices/ipin.sym} 1570 -300 0 1 {name=p66 lab=enb_400}
C {devices/iopin.sym} 1870 -280 0 1 {name=p67 lab=src_400}
C {bias_pstack.sym} 2100 -360 0 0 {name=x6[3:0]}
C {devices/ipin.sym} 1950 -300 0 1 {name=p68 lab=enb_200_0}
C {devices/iopin.sym} 2250 -290 0 1 {name=p69 lab=src_200_0}
C {bias_pstack.sym} 2480 -360 0 0 {name=x7[3:0]}
C {devices/ipin.sym} 2330 -300 0 1 {name=p70 lab=enb_200_1}
C {devices/iopin.sym} 2630 -280 0 1 {name=p71 lab=src_200_1}
C {bias_pstack.sym} 2850 -360 0 0 {name=x11[3:0]}
C {devices/ipin.sym} 2700 -300 0 1 {name=p72 lab=enb_200_2}
C {devices/iopin.sym} 3000 -280 0 1 {name=p73 lab=src_200_2}
C {bias_pstack.sym} 3220 -360 0 0 {name=x12[1:0]}
C {devices/ipin.sym} 3070 -300 0 1 {name=p74 lab=enb_100}
C {devices/iopin.sym} 3370 -280 0 1 {name=p75 lab=src_100}
C {bias_pstack.sym} 3590 -360 0 0 {name=x13}
C {devices/ipin.sym} 3440 -300 0 1 {name=p76 lab=enb_50}
C {devices/iopin.sym} 3740 -280 0 1 {name=p77 lab=src_50}
C {bias_nstack.sym} 1570 -140 0 0 {name=x14[74:0]}
C {devices/ipin.sym} 1420 -210 0 1 {name=p78 lab=ena_3700}
C {devices/iopin.sym} 1720 -200 0 1 {name=p79 lab=snk_3700}
C {bias_nstack.sym} 1920 -140 0 0 {name=x15[39:0]}
C {devices/ipin.sym} 1770 -210 0 1 {name=p80 lab=ena_2000}
C {devices/iopin.sym} 2070 -200 0 1 {name=p81 lab=snk_2000}
