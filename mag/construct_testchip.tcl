# Construct the test chip

if {[catch {set PDK_ROOT $::env(PDK_ROOT)}]} {
    set PDK_ROOT /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK sky130A
}

# Pull the cells which have GDS
# gds readonly true
# gds rescale false
# gds drccheck off

# Pre-read the standard cell GDS
gds read $PDK_ROOT/$PDK/libs.ref/sky130_fd_sc_hd/gds/sky130_fd_sc_hd.gds
gds read $PDK_ROOT/$PDK/libs.ref/sky130_fd_sc_hvl/gds/sky130_fd_sc_hvl.gds

# Force the standard cell GDS just read to take precedence
gds noduplicates true

# These have cells of the same name with different contents, so enforce unique names
gds unique true
gds read ../../chipalooza/sky130_ajc_ip__brownout/gds/sky130_ajc_ip__brownout.gds
gds read ../../chipalooza/sky130_ajc_ip__por/gds/sky130_ajc_ip__por.gds
gds read ../../chipalooza/sky130_ajc_ip__overvoltage/gds/sky130_ajc_ip__overvoltage.gds
gds unique false

# Non-chipalooza items
gds read ../../weiser_analog_mpw7/gds/bandgap.gds
gds read ../../weiser_analog_mpw7/gds/bias_basis_current.gds

# For the rest, there are no known name collisions.
gds read ../../chipalooza/sky130_be_ip__lsxo/gds/sky130_be_ip__lsxo.gds
gds read ../../chipalooza/sky130_rodovalho_ip__lpopamp/gds/lpopamp.gds
# gds read ../../chipalooza/sky130_ac3e_ip__temp_sdc/modules/SDC_DIGITAL/layout/SDC_DIGITAL.gds

# Not from .mag . . .
# addpath ../../chipalooza/sky130_ac3e_ip__temp_sdc/modules
# addpath ../../chipalooza/sky130_ajc_ip__brownout/mag
# addpath ../../chipalooza/sky130_ajc_ip__overvoltage/mag
# addpath ../../chipalooza/sky130_ajc_ip__por/mag
# addpath ../../chipalooza/sky130_be_ip__lsxo/mag
# addpath ../../chipalooza/sky130_rodovalho_ip__lpopamp/mag

# The remainder will come from .mag (unless I create individual GDS files)

addpath ../../chipalooza/hsxo-cpz1/mag
addpath ../../chipalooza/sky130_ak_ip__comparator/mag
addpath ../../chipalooza/sky130_od_ip__tempsensor/mag
addpath ../../chipalooza/sky130_td_ip__opamp_hp/mag
addpath ../../chipalooza/sky130_vbl_ip__overvoltage/mag

# Load the project wrapper cell
load user_analog_project_wrapper
