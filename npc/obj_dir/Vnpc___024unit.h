// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnpc.h for the primary calling header

#ifndef VERILATED_VNPC___024UNIT_H_
#define VERILATED_VNPC___024UNIT_H_  // guard

#include "verilated.h"


class Vnpc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vnpc___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vnpc__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnpc___024unit(Vnpc__Syms* symsp, const char* v__name);
    ~Vnpc___024unit();
    VL_UNCOPYABLE(Vnpc___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
