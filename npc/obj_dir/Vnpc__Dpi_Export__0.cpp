// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vnpc.h"
#include "Vnpc__Syms.h"
#include "verilated_dpi.h"


svBitVecVal Vnpc::get_reg(int index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root::get_reg\n"); );
    // Init
    IData/*31:0*/ index__Vcvt;
    index__Vcvt = 0;
    IData/*31:0*/ get_reg__Vfuncrtn__Vcvt;
    get_reg__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("get_reg");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vnpc__Vcb_get_reg_t __Vcb = (Vnpc__Vcb_get_reg_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    index__Vcvt = index;
    (*__Vcb)((Vnpc__Syms*)(__Vscopep->symsp()), index__Vcvt, get_reg__Vfuncrtn__Vcvt);
    svBitVecVal get_reg__Vfuncrtn[1];
    for (size_t get_reg__Vfuncrtn__Vidx = 0; get_reg__Vfuncrtn__Vidx < 1; ++get_reg__Vfuncrtn__Vidx) VL_SET_SVBV_I(32, get_reg__Vfuncrtn + 1 * get_reg__Vfuncrtn__Vidx, get_reg__Vfuncrtn__Vcvt);
    return get_reg__Vfuncrtn[0];
}
