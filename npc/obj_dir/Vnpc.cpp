// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vnpc__pch.h"

//============================================================
// Constructors

Vnpc::Vnpc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vnpc__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , alu_result{vlSymsp->TOP.alu_result}
    , pc{vlSymsp->TOP.pc}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vnpc::Vnpc(const char* _vcname__)
    : Vnpc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vnpc::~Vnpc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vnpc___024root___eval_debug_assertions(Vnpc___024root* vlSelf);
#endif  // VL_DEBUG
void Vnpc___024root___eval_static(Vnpc___024root* vlSelf);
void Vnpc___024root___eval_initial(Vnpc___024root* vlSelf);
void Vnpc___024root___eval_settle(Vnpc___024root* vlSelf);
void Vnpc___024root___eval(Vnpc___024root* vlSelf);

void Vnpc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnpc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vnpc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vnpc___024root___eval_static(&(vlSymsp->TOP));
        Vnpc___024root___eval_initial(&(vlSymsp->TOP));
        Vnpc___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vnpc___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vnpc::eventsPending() { return false; }

uint64_t Vnpc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vnpc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vnpc___024root___eval_final(Vnpc___024root* vlSelf);

VL_ATTR_COLD void Vnpc::final() {
    Vnpc___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vnpc::hierName() const { return vlSymsp->name(); }
const char* Vnpc::modelName() const { return "Vnpc"; }
unsigned Vnpc::threads() const { return 1; }
void Vnpc::prepareClone() const { contextp()->prepareClone(); }
void Vnpc::atClone() const {
    contextp()->threadPoolpOnClone();
}
