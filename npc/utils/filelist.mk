

LIBCAPSTONE = tools/capstone/repo/libcapstone.so.5
src/utils/disasm.c: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C tools/capstone
