
#TOOLCHAIN_PATH=/usr/bin/
#TOOLCHAIN_PATH=/usr/local/bin/
TOOLCHAIN_PATH=/opt/riscv32imc/bin/
# TOOLCHAIN_PATH=/ef/apps/bin/

# Set the prefix for `riscvXX-unknown-elf-*`
# On installations using `multilib`, this will be `riscv64` even for compiling to 32-bit targets
#TOOLCHAIN_PREFIX=riscv64-unknown-elf
TOOLCHAIN_PREFIX=riscv32-unknown-elf
#TOOLCHAIN_PREFIX=riscv32
INCLUDES=-I$(shell pwd) -I../ -I../generated/

VOLTAGE=$(shell python3 -c "from gpio_config_def import voltage; print(voltage)")

# ---- Test patterns for chipalooza test chip 1 ----

.SUFFIXES:

PATTERN = chipalooza_test_hgbwamp

hex:  ${PATTERN:=.hex}

%.elf: %.c ../sections.lds ../crt0_vex.S ../chipalooza_util.c ../stub.c
	$(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-gcc -I../ -I../generated/ -O0 -mabi=ilp32 -march=rv32i -D__vexriscv__ -Wl,-Bstatic,-T,../sections.lds,--strip-debug -ffreestanding -nostdlib -o $@ ../crt0_vex.S ../isr.c ../stub.c ../chipalooza_util.c $<
	${TOOLCHAIN_PATH}$(TOOLCHAIN_PREFIX)-objdump -D ${PATTERN}.elf > ${PATTERN}.lst

%.hex: %.elf
	$(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objcopy -O verilog $< $@
	sed -ie 's/@1000/@0000/g' $@

%.bin: %.elf
	$(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objcopy -O binary $< $@

client: client.c
	gcc client.c -o client

flash: ${PATTERN}.hex
	python3 ../util/caravel_hkflash.py $<
	python3 ../util/caravel_hkstop.py

# ---- Clean ----

clean:
	rm -f *.elf *.hex *.bin *.vvp *.vcd

.PHONY: clean hex all flash

