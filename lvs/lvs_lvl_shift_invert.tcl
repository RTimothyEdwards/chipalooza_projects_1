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
#
# LVS the 1.8V->3.3V level shifter with differential outputs
# Run this with "netgen -batch source lvs_lvl_shift_invert.tcl"

if {[catch {set PDK_PATH $::env(PDK_PATH)}]} {
    set PDK_PATH /usr/share/pdk
}
if {[catch {set PDK $::env(PDK)}]} {
    set PDK sky130A
}

set circuit1 [readnet spice ../netlist/layout/lvl_shift_invert.spice]

set circuit2 [readnet spice ../netlist/schematic/lvl_shift_invert.spice]
readnet spice $PDK_PATH/$PDK/libs.ref/sky130_fd_sc_hvl/spice/sky130_fd_sc_hvl.spice $circuit2

lvs "$circuit1 lvl_shift_invert" "$circuit2 lvl_shift_invert" $PDK_PATH/$PDK/libs.tech/netgen/sky130A_setup.tcl lvl_shift_invert_comp.out
