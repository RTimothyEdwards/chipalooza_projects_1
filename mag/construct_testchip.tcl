# SPDX-FileCopyrightText: 2020 Efabless Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

# Construct the test chip

if {[catch {set PDK_ROOT $::env(PDK_ROOT)}]} {
    set PDK_ROOT /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK sky130A
}

# The remainder will come from .mag (unless I create individual GDS files)

addpath ../../chipalooza/hsxo-cpz1/mag
# addpath ../../chipalooza/sky130_ak_ip__comparator/mag
addpath ../../chipalooza/sky130_od_ip__tempsensor/mag
addpath ../../chipalooza/sky130_td_ip__opamp_hp/mag
addpath ../../chipalooza/sky130_vbl_ip__overvoltage/mag
addpath ../../chipalooza/sky130_be_ip__lsxo/mag
addpath ../../chipalooza/sky130_rodovalho_ip__lpopamp/mag

# These have been modified to remove same names of non-matching circuits:
# comparator, ibias_gen, rc_osc, rstring_mux, schmitt_trigger
addpath ../../chipalooza/sky130_ajc_ip__brownout/mag
addpath ../../chipalooza/sky130_ajc_ip__por/mag
addpath ../../chipalooza/sky130_ajc_ip__overvoltage/mag

# Pull the cells which have GDS
# gds readonly true
# gds rescale false
# gds drccheck off

# Force the standard cell GDS just read to take precedence
gds noduplicates true

# Non-chipalooza items, GDS only
gds read ../../weiser_analog_mpw7/gds/bandgap.gds
gds read ../../weiser_analog_mpw7/gds/bias_basis_current.gds

gds noduplicates false

# Test---Read project from GDS as read-only
gds readonly true
gds rescale false
gds read ../../chipalooza/sky130_ak_ip__comparator/gds/sky130_ak_ip__comparator.gds.gz

# Load the project wrapper cell
load user_analog_project_wrapper
