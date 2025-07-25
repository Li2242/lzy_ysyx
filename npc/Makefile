VERILATOR = verilator
#-Wall未加
CFLAGS = --cc --exe --build -O3  --trace --top-module npc
CSRC = csrc/main.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

IMG ?=

.PHONY: sim run clean

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	echo "sim"
	$(VERILATOR) $(CFLAGS) $(CSRC) $(VSRC)

run: sim $(CSRC) $(VSRC)
	echo "run"
	./$(OBJ_DIR)/Vnpc $(IMG)


clean:
	rm -rf obj_dir waveform.vcd waveform.view
include ../Makefile
