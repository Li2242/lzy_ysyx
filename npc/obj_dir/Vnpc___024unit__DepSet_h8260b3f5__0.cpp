// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024unit.h"

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_pmem_read_TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void ebreak(unsigned int pc);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    ebreak(pc__Vcvt);
}
