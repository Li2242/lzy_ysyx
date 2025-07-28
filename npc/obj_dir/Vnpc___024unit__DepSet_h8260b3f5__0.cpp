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

extern "C" int v_pmem_read(int raddr);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &v_pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int v_pmem_read__Vfuncrtn__Vcvt;
    v_pmem_read__Vfuncrtn__Vcvt = v_pmem_read(raddr__Vcvt);
    v_pmem_read__Vfuncrtn = v_pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void v_pmem_write(unsigned int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit\n"); );
    // Body
    unsigned int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    v_pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}
