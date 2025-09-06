
# 代表动态库 capstone 的路径
LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
# 用是 添加头文件搜索路径
CFLAGS += -I$(NPC_HOME)/tools/capstone/repo/include
#src/utils/disasm.c 这个源文件在编译之前，必须先保证 $(LIBCAPSTONE) 存在。
src/utils/disasm.c: $(LIBCAPSTONE)
#如果 libcapstone.so.5 不存在，就会执行：
$(LIBCAPSTONE):
	$(MAKE) -C tools/capstone
