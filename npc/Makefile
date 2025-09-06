VERILATOR = verilator
#参数
VERILATOR_FLAGS = --cc --exe  --build  --top-module npc
CFLAGS = -g -O3
# 头文件路径
CFLAGS += -I$(NPC_HOME)/csrc/include/

# Link the readline library
LDFLAGS = -lreadline

#-Wall未加
ALL_FLAGS = $(VERILATOR_FLAGS) -CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"
CSRC = csrc/*.cpp
CSRC += utils/*.cpp
CSRC += csrc/device/*.cpp
VSRC = vsrc/*.v
OBJ_DIR = obj_dir
BUILD_DIR = ./build
$(shell mkdir -p $(BUILD_DIR))

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt -d $(NPC_HOME)/tools/riscv32-nemu-interpreter-so
#如果没有传入镜像文件就置为空
IMG ?=

#Weather to generate a waveform file?
trace ?= 0
ifeq ($(trace),1)
    VERILATOR_FLAGS += --trace
    CFLAGS += -DVTRACE
endif

# Include all filelist.mk to merge file lists
FILELIST_MK = $(shell find -L ./utils -name "filelist.mk")
include $(FILELIST_MK)

all:
	@echo "Write this Makefile by your self."

sim: $(CSRC) $(VSRC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(ALL_FLAGS) $(CSRC) $(VSRC)

# Dependence is sim
run: sim
	./$(OBJ_DIR)/Vnpc $(ARGS) $(IMG)

#在 Makefile 中打印任意变量的名字和它的值。
p-%:
	@echo $* = $($*)

.PHONY: sim run clean

#Clean up
clean:
	rm -rf obj_dir waveform.vcd waveform.view $(BUILD_DIR)
include ../Makefile
