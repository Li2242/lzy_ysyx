// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"

extern "C" void ebreak(unsigned int pc);

void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    ebreak(pc__Vcvt);
}

extern "C" int v_pmem_read(int raddr, int len);

void Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ len, IData/*31:0*/ &v_pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_v_pmem_read_TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    raddr__Vcvt = raddr;
    int len__Vcvt;
    len__Vcvt = len;
    int v_pmem_read__Vfuncrtn__Vcvt;
    v_pmem_read__Vfuncrtn__Vcvt = v_pmem_read(raddr__Vcvt, len__Vcvt);
    v_pmem_read__Vfuncrtn = (v_pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void v_pmem_write(unsigned int waddr, int wdata, char wmask);

void Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_v_pmem_write_TOP____024unit\n"); );
    // Body
    unsigned int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    char wmask__Vcvt;
    wmask__Vcvt = wmask;
    v_pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}
