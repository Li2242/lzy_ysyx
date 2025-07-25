// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnpc.h for the primary calling header

#include "Vnpc__pch.h"
#include "Vnpc__Syms.h"
#include "Vnpc___024unit.h"

extern "C" void info_reg(const svOpenArrayHandle rf_data);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_info_reg__Vdpioc2_TOP____024unit(const VlUnpacked<IData/*31:0*/, 32> &rf_data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_info_reg__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const int rf_data__Vopenprops__ulims[2] = {31, 0};
    static const int rf_data__Vopenprops__plims[2] = {31, 0};
    static const VerilatedVarProps rf_data__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Unpacked{}, 1, rf_data__Vopenprops__ulims, VerilatedVarProps::Packed{}, 1, rf_data__Vopenprops__plims);
    VerilatedDpiOpenVar rf_data__Vopenarray (&rf_data__Vopenprops, &rf_data);
    info_reg(&rf_data__Vopenarray);
}

extern "C" void ebreak(unsigned int pc);

VL_INLINE_OPT void Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vnpc___024unit____Vdpiimwrap_ebreak_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) pc__Vcvt = pc;
    ebreak(pc__Vcvt);
}
