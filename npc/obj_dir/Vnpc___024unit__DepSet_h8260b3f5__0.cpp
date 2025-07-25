// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024unit.h"

extern "C" void ebreak(unsigned int pc);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    ebreak(pc__Vcvt);
}

extern "C" void halt();

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_halt_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_halt_TOP____024unit\n"); );
    // Body
    halt();
}
