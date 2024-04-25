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

CARAVEL_ROOT?=$(PWD)/caravel
PRECHECK_ROOT?=${HOME}/mpw_precheck
SIM ?= RTL
CUP_ROOT?=$(PWD)

SKYWATER_COMMIT=f70d8ca46961ff92719d8870a18a076370b85f6c
export OPEN_PDKS_COMMIT?=78b7bc32ddb4b6f14f76883c2e2dc5b5de9d1cbc
export PDK?=sky130A
export PDKPATH?=$(PDK_ROOT)/$(PDK)
# Install lite version of caravel, (1): caravel-lite, (0): caravel
CARAVEL_LITE?=1

MPW_TAG ?= mpw-9i
export PDK_ROOT?=$(PWD)/dependencies/pdks

ifeq ($(CARAVEL_LITE),1)
	CARAVEL_NAME := caravel-lite
	CARAVEL_REPO := https://github.com/efabless/caravel-lite
	CARAVEL_TAG := $(MPW_TAG)
else
	CARAVEL_NAME := caravel
	CARAVEL_REPO := https://github.com/efabless/caravel
	CARAVEL_TAG := $(MPW_TAG)
endif

# Include Caravel Makefile Targets
.PHONY: % : check-caravel
%: 
	export CARAVEL_ROOT=$(CARAVEL_ROOT) && $(MAKE) -f $(CARAVEL_ROOT)/Makefile $@

# Verify Target for running simulations
.PHONY: verify
verify:
	cd ./verilog/dv/ && \
	export SIM=${SIM} && \
		$(MAKE) -j$(THREADS)

# Install DV setup
.PHONY: simenv
simenv:
	docker pull efabless/dv_setup:latest

PATTERNS=$(shell cd verilog/dv && find * -maxdepth 0 -type d)
DV_PATTERNS = $(foreach dv, $(PATTERNS), verify-$(dv))
TARGET_PATH=$(shell pwd)
VERIFY_COMMAND="cd ${TARGET_PATH}/verilog/dv/$* && export SIM=${SIM} && make"
$(DV_PATTERNS): verify-% : ./verilog/dv/% 
	docker run -v ${TARGET_PATH}:${TARGET_PATH} -v ${PDK_ROOT}:${PDK_ROOT} \
                -v ${CARAVEL_ROOT}:${CARAVEL_ROOT} \
                -e TARGET_PATH=${TARGET_PATH} -e PDK_ROOT=${PDK_ROOT} \
                -e CARAVEL_ROOT=${CARAVEL_ROOT} \
                -u $(id -u $$USER):$(id -g $$USER) efabless/dv_setup:latest \
                sh -c $(VERIFY_COMMAND)
				
# Openlane Makefile Targets
BLOCKS = $(shell cd openlane && find * -maxdepth 0 -type d)
.PHONY: $(BLOCKS)
$(BLOCKS): %:
	cd openlane && $(MAKE) $*

.PHONY: setup
setup: check_dependencies install check-env install_mcw pdk-with-volare setup-timing-scripts setup-cocotb

# Install caravel
.PHONY: install
install:
	@echo "Installing $(CARAVEL_NAME).."
	@git clone -b $(CARAVEL_TAG) $(CARAVEL_REPO) $(CARAVEL_ROOT)

# Create symbolic links to caravel's main files
.PHONY: simlink
simlink: check-caravel
### Symbolic links relative path to $CARAVEL_ROOT 
	$(eval MAKEFILE_PATH := $(shell realpath --relative-to=openlane $(CARAVEL_ROOT)/openlane/Makefile))
	mkdir -p openlane
	cd openlane &&\
	ln -sf $(MAKEFILE_PATH) Makefile

BLOCKS = $(shell cd lvs && find * -maxdepth 0 -type d)
LVS_BLOCKS = $(foreach block, $(BLOCKS), lvs-$(block))
$(LVS_BLOCKS): lvs-% : ./lvs/%/lvs_config.json uncompress check-pdk check-precheck
	@$(eval INPUT_DIRECTORY := $(shell pwd))
	@cd $(PRECHECK_ROOT) && \
	docker run -v $(PRECHECK_ROOT):$(PRECHECK_ROOT) \
	-v $(INPUT_DIRECTORY):$(INPUT_DIRECTORY) \
	-v $(PDK_ROOT):$(PDK_ROOT) \
	-u $(shell id -u $(USER)):$(shell id -g $(USER)) \
	efabless/mpw_precheck:latest bash -c "cd $(PRECHECK_ROOT) ; python3 checks/lvs_check/lvs.py --pdk_path $(PDK_ROOT)/$(PDK) --design_directory $(INPUT_DIRECTORY) --output_directory $(INPUT_DIRECTORY)/lvs --design_name $* --config_file $(INPUT_DIRECTORY)/lvs/$*/lvs_config.json"

# Update Caravel
.PHONY: update_caravel
update_caravel: check-caravel
	cd $(CARAVEL_ROOT)/ && git checkout $(CARAVEL_TAG) && git pull

# Uninstall Caravel
.PHONY: uninstall
uninstall: 
	rm -rf $(CARAVEL_ROOT)

# Install Openlane
.PHONY: openlane
openlane: 
	cd openlane && $(MAKE) openlane

# Install Pre-check
# Default installs to the user home directory, override by "export PRECHECK_ROOT=<precheck-installation-path>"
.PHONY: precheck
precheck:
	@git clone --depth=1 --branch $(MPW_TAG) https://github.com/efabless/mpw_precheck.git $(PRECHECK_ROOT)
	@docker pull efabless/mpw_precheck:latest

.PHONY: run-precheck
run-precheck: check-pdk check-precheck
	@if [ "$$DISABLE_LVS" = "1" ]; then\
		$(eval INPUT_DIRECTORY := $(shell pwd)) \
		cd $(PRECHECK_ROOT) && \
		docker run -v $(PRECHECK_ROOT):$(PRECHECK_ROOT) \
		-v $(INPUT_DIRECTORY):$(INPUT_DIRECTORY) \
		-v $(PDK_ROOT):$(PDK_ROOT) \
		-e INPUT_DIRECTORY=$(INPUT_DIRECTORY) \
		-e PDK_PATH=$(PDK_ROOT)/$(PDK) \
		-e PDK_ROOT=$(PDK_ROOT) \
		-e PDKPATH=$(PDKPATH) \
		-u $(shell id -u $(USER)):$(shell id -g $(USER)) \
		efabless/mpw_precheck:latest bash -c "cd $(PRECHECK_ROOT) ; python3 mpw_precheck.py --input_directory $(INPUT_DIRECTORY) --pdk_path $(PDK_ROOT)/$(PDK) license makefile default documentation consistency gpio_defines xor magic_drc klayout_feol klayout_beol klayout_offgrid klayout_met_min_ca_density klayout_pin_label_purposes_overlapping_drawing klayout_zeroarea"; \
	else \
		$(eval INPUT_DIRECTORY := $(shell pwd)) \
		cd $(PRECHECK_ROOT) && \
		docker run -v $(PRECHECK_ROOT):$(PRECHECK_ROOT) \
		-v $(INPUT_DIRECTORY):$(INPUT_DIRECTORY) \
		-v $(PDK_ROOT):$(PDK_ROOT) \
		-e INPUT_DIRECTORY=$(INPUT_DIRECTORY) \
		-e PDK_PATH=$(PDK_ROOT)/$(PDK) \
		-e PDK_ROOT=$(PDK_ROOT) \
		-e PDKPATH=$(PDKPATH) \
		-u $(shell id -u $(USER)):$(shell id -g $(USER)) \
		efabless/mpw_precheck:latest bash -c "cd $(PRECHECK_ROOT) ; python3 mpw_precheck.py --input_directory $(INPUT_DIRECTORY) --pdk_path $(PDK_ROOT)/$(PDK)"; \
	fi

# Clean 
.PHONY: clean
clean:
	cd ./verilog/dv/ && \
		$(MAKE) -j$(THREADS) clean

check-caravel:
	@if [ ! -d "$(CARAVEL_ROOT)" ]; then \
		echo "Caravel Root: "$(CARAVEL_ROOT)" doesn't exists, please export the correct path before running make. "; \
		exit 1; \
	fi

check-precheck:
	@if [ ! -d "$(PRECHECK_ROOT)" ]; then \
		echo "Pre-check Root: "$(PRECHECK_ROOT)" doesn't exists, please export the correct path before running make. "; \
		exit 1; \
	fi

check-pdk:
	@if [ ! -d "$(PDK_ROOT)" ]; then \
		echo "PDK Root: "$(PDK_ROOT)" doesn't exists, please export the correct path before running make. "; \
		exit 1; \
	fi

.PHONY: help
help:
	cd $(CARAVEL_ROOT) && $(MAKE) help 
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

.PHONY: check_dependencies
check_dependencies:
	@if [ ! -d "$(PWD)/dependencies" ]; then \
		mkdir $(PWD)/dependencies; \
	fi

.PHONY: setup-timing-scripts
setup-timing-scripts: $(TIMING_ROOT)
	@( cd $(TIMING_ROOT) && git pull )
	@#( cd $(TIMING_ROOT) && git fetch && git checkout $(MPW_TAG); )

.PHONY: setup-cocotb
setup-cocotb: 
	@pip install caravel-cocotb==1.0.0 
	@(python3 $(PROJECT_ROOT)/verilog/dv/setup-cocotb.py $(CARAVEL_ROOT) $(MCW_ROOT) $(PDK_ROOT) $(PDK) $(PROJECT_ROOT))
	@docker pull efabless/dv:latest
	@docker pull efabless/dv:cocotb
