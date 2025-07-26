VERILATOR = verilator
#参数
VERILATOR_FLAGS = --cc --exe --build --trace --top-module npc
CFLAGS = -g -O3 -I tools/capstone/repo/include -I csrc/include/
# Link the readline library
LDFLAGS = -lreadline
#-Wall未加
ALL_FLAGS = $(VERILATOR_FLAGS) -CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"
CSRC = csrc/*.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

#如果没有传入镜像文件就置为空
IMG ?=

# Include all filelist.mk to merge file lists
FILELIST_MK = $(shell find -L ./src -name "filelist.mk")
include $(FILELIST_MK)

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	echo "sim"
	$(VERILATOR) $(ALL_FLAGS) $(CSRC) $(VSRC)

run: sim $(CSRC) $(VSRC)
	echo "run"
	./$(OBJ_DIR)/Vnpc $(IMG)


.PHONY: sim run clean

clean:
	rm -rf obj_dir waveform.vcd waveform.view
include ../Makefile
