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

# Pull all layout of individual projects.  NOTE:  Need a Makefile and
# build target to handle cloning repositories, or let CACE handle it.

addpath ../../chipalooza_forked/sky130_ht_ip__hsxo_cpz1/mag
addpath ../../chipalooza_forked/sky130_ak_ip__comparator/mag
addpath ../../chipalooza_forked/sky130_od_ip__tempsensor/mag
addpath ../../chipalooza_forked/sky130_td_ip__opamp_hp/mag
addpath ../../chipalooza_forked/sky130_vbl_ip__overvoltage/mag
addpath ../../chipalooza_forked/sky130_be_ip__lsxo/mag
addpath ../../chipalooza_forked/sky130_rodovalho_ip__lpopamp/mag
addpath ../../chipalooza_forked/sky130_ajc_ip__brownout/mag
addpath ../../chipalooza_forked/sky130_ajc_ip__por/mag
addpath ../../chipalooza_forked/sky130_ajc_ip__overvoltage/mag

# Non-chipalooza items, GDS only
gds read ../../weiser_analog_mpw7/gds/bandgap.gds
gds read ../../weiser_analog_mpw7/gds/bias_basis_current.gds

# Load the project wrapper cell.  Dereference any cell locations;  cells
# shoud only come from known paths.
load user_analog_project_wrapper -dereference
