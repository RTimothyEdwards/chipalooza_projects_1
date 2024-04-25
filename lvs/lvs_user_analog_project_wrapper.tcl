# LVS the entire user project top level (user_analog_project_wrapper)
#
# Run this with "netgen -batch source lvs_user_analog_project_wrapper.tcl"
#
# NOTE: Chipalooza projects are black-boxed

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK sky130A
}

set circuit1 [readnet spice ../netlist/layout/user_analog_project_wrapper.spice]

set circuit2 [readnet spice ../netlist/schematic/user_analog_project_wrapper.spice]

# Read the digital standard cell libraries (HD and HVL libraries used)
readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hvl/spice/sky130_fd_sc_hvl.spice $circuit2
#
# readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hd/spice/sky130_fd_sc_hd.spice $circuit2

lvs "$circuit1 user_analog_project_wrapper" "$circuit2 user_analog_project_wrapper" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl user_analog_project_wrapper_comp.out
