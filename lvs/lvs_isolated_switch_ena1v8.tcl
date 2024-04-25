# LVS the isolated switch with 1.8V enable
# Run this with "netgen -batch source lvs_isolated_switch_ena1v8.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK_PATH sky130A
}

set circuit1 [readnet spice ../netlist/layout/isolated_switch_ena1v8.spice]

set circuit2 [readnet spice ../netlist/schematic/isolated_switch_ena1v8.spice]
readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hvl/spice/sky130_fd_sc_hvl.spice $circuit2

lvs "$circuit1 isolated_switch_ena1v8" "$circuit2 isolated_switch_ena1v8" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl isolated_switch_ena1v8_comp.out
