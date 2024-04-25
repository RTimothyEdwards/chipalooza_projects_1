# LVS the analog mux with 1.8V select
# Run this with "netgen -batch source lvs_analog_mux_sel1v8.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK_PATH sky130A
}

set circuit1 [readnet spice ../netlist/layout/analog_mux_sel1v8.spice]

set circuit2 [readnet spice ../netlist/schematic/analog_mux_sel1v8.spice]
readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hvl/spice/sky130_fd_sc_hvl.spice $circuit2

lvs "$circuit1 analog_mux_sel1v8" "$circuit2 analog_mux_sel1v8" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl analog_mux_sel1v8_comp.out
