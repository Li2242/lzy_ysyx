VERILATOR = verilator
#参数
VERILATOR_FLAGS = --cc --exe --build --trace --top-module npc
CFLAGS = -g -O3 -I tools/capstone/repo/include
LDFLAGS = -lreadline
#-Wall未加
ALL_FLAGS = $(VERILATOR_FLAGS) -CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"
CSRC = csrc/*.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

IMG ?=

.PHONY: sim run clean

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	echo "sim"
	$(VERILATOR) $(ALL_FLAGS) $(CSRC) $(VSRC)

run: sim $(CSRC) $(VSRC)
	echo "run"
	./$(OBJ_DIR)/Vnpc $(IMG)


clean:
	rm -rf obj_dir waveform.vcd waveform.view
include ../Makefile
