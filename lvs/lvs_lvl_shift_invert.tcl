# LVS the 1.8V->3.3V level shifter with differential outputs
# Run this with "netgen -batch source lvs_lvl_shift_invert.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK_PATH sky130A
}

set circuit1 [readnet spice ../netlist/layout/lvl_shift_invert.spice]

set circuit2 [readnet spice ../netlist/schematic/lvl_shift_invert.spice]
readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hvl/spice/sky130_fd_sc_hvl.spice $circuit2

lvs "$circuit1 lvl_shift_invert" "$circuit2 lvl_shift_invert" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl lvl_shift_invert_comp.out
