# LVS the pMOS power stage
# Run this with "netgen -batch source lvs_power_stage.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK_PATH sky130A
}

set circuit1 [readnet spice ../netlist/layout/power_stage.spice]

set circuit2 [readnet spice ../netlist/schematic/power_stage.spice]

lvs "$circuit1 power_stage" "$circuit2 power_stage" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl power_stage_comp.out
