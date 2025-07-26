VERILATOR = verilator
#参数
VERILATOR_FLAGS = --cc --exe --build --trace --top-module npc
CFLAGS = -g -O3
# 头文件路径
CFLAGS += -I /home/lzy14/ysyx/ysyx-workbench/npc/csrc/include/
# Link the readline library
LDFLAGS = -lreadline
LDFLAGS += -Ltools/capstone/repo -lcapstone
#-Wall未加
ALL_FLAGS = $(VERILATOR_FLAGS) -CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"
CSRC = csrc/*.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir

#如果没有传入镜像文件就置为空
IMG ?=

# Include all filelist.mk to merge file lists
FILELIST_MK = $(shell find -L ./utils -name "filelist.mk")
include $(FILELIST_MK)

all:
	@echo "Write this Makefile by your self."

sim: $(LIBCAPSTONE) $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	echo "sim"
	$(VERILATOR) $(ALL_FLAGS) $(CSRC) $(VSRC)

run: sim
	echo "run"
	./$(OBJ_DIR)/Vnpc $(IMG)


.PHONY: sim run clean

clean:
	rm -rf obj_dir waveform.vcd waveform.view
include ../Makefile
