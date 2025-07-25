// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VNPC__DPI_H_
#define VERILATED_VNPC__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vsrc/npc.v:1:30
    extern void ebreak(unsigned int pc);
    // DPI import at vsrc/RegisterFile.v:2:30
    extern void isa_reg_display(const svOpenArrayHandle rf_data);
    // DPI import at vsrc/RegisterFile.v:3:30
    extern void isa_reg_str2val(const svOpenArrayHandle rf_data);

#ifdef __cplusplus
}
#endif

#endif  // guard
