VERILATOR = verilator

CFLAGS = --cc --exe --build -O3 -Wall --trace -Wno-UNDRIVEN -Wno-UNUSEDSIGNAL
CSRC = csrc/main.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir


all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	./$(OBJ_DIR)/Vnpc

run:$(CSRC) $(VSRC)
	$(VERILATOR) $(CFLAGS) --top-module npc $(CSRC) $(VSRC)

clean:
	rm -rf obj_dir
include ../Makefile
