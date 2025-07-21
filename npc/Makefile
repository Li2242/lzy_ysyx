VERILATOR = verilator

CFLAGS = --cc --exe --build -O3 -Wall --trace --top-module npc
CSRC = csrc/main.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

IMG ?=

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	./$(OBJ_DIR)/Vnpc

run:$(CSRC) $(VSRC)
	$(VERILATOR) $(CFLAGS)   $(CSRC) $(VSRC) $(IMG)

clean:
	rm -rf obj_dir
include ../Makefile
