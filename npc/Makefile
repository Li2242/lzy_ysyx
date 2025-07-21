VERILATOR = verilator

CFLAGS = --cc --exe --build -O2 -Wall --trace --top-module npc
CSRC = csrc/main.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

IMG ?=

.PHONY: sim run clean

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(CFLAGS) $(CSRC) $(VSRC)

run: sim $(CSRC) $(VSRC)
	./$(OBJ_DIR)/Vnpc $(IMG)


clean:
	rm -rf obj_dir
include ../Makefile
