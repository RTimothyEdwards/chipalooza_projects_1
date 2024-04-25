# LVS the current bias generator
# Run this with "netgen -batch source lvs_bias_generator.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK_PATH sky130A
}

set circuit1 [readnet spice ../netlist/layout/bias_generator.spice]

set circuit2 [readnet spice ../netlist/schematic/bias_generator.spice]

lvs "$circuit1 bias_generator" "$circuit2 bias_generator" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl bias_generator_comp.out -noflatten="bias_nstack bias_pstack"

