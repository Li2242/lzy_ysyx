// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnpc__Syms.h"


VL_ATTR_COLD void Vnpc___024root__trace_init_sub__TOP__0(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_sub__TOP__0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+84,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+88,0,"inst_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("npc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+84,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+88,0,"inst_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"nextpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"IFU_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+98,0,"IFU_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+35,0,"ifu_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"ifu_next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"ifu_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"ifu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+38,0,"pc_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"inst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+41,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+42,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+45,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"reg_cwen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"mem_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"mem_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"is_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"reg_from_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"reg_from_pc_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"reg_from_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"imm_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"imm_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"imm_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+57,0,"is_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"is_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"is_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"is_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"is_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"is_auipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"is_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"is_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"is_lbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"is_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"is_sb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+71,0,"opcode_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+75,0,"funct3_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+90,0,"final_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"csr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+62,0,"src1_is_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"src2_is_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"alu_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"alu_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+93,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+86,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"add_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+76,0,"add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+84,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"craddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+91,0,"crdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+46,0,"cwen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"cwaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+78,0,"cwdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"mcycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"mcycleh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"mvendorid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"marchid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder3_8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+41,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+75,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder7_128", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+40,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declArray(c+71,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_regfile2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+103,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+84,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+90,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+78,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+92,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+3+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vnpc___024root__trace_init_top(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_init_top\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vnpc___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vnpc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vnpc___024root__trace_register(Vnpc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_register\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vnpc___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vnpc___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vnpc___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vnpc___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_const_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_const_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+97,(0U));
    bufp->fullBit(oldp+98,(1U));
    bufp->fullIData(oldp+99,(vlSelfRef.npc__DOT__ifu_rdata),32);
    bufp->fullIData(oldp+100,(vlSelfRef.npc__DOT__imm_R),32);
    bufp->fullIData(oldp+101,(0x79737978U),32);
    bufp->fullIData(oldp+102,(0x17e634bU),32);
    bufp->fullIData(oldp+103,(5U),32);
    bufp->fullIData(oldp+104,(0x20U),32);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vnpc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0\n"); );
    // Init
    Vnpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vnpc___024root*>(voidSelf);
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vnpc___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vnpc___024root__trace_full_0_sub_0(Vnpc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnpc___024root__trace_full_0_sub_0\n"); );
    Vnpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.npc__DOT__u_csr__DOT__mcycle),32);
    bufp->fullIData(oldp+2,(vlSelfRef.npc__DOT__u_csr__DOT__mcycleh),32);
    bufp->fullIData(oldp+3,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[0]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[1]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[2]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[3]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[4]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[5]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[6]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[7]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[8]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[9]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[10]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[11]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[12]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[13]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[14]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[15]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[16]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[17]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[18]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[19]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[20]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[21]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[22]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[23]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[24]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[25]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[26]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[27]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[28]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[29]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[30]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.npc__DOT__u_regfile2__DOT__rf[31]),32);
    bufp->fullBit(oldp+35,(vlSelfRef.npc__DOT__ifu_state));
    bufp->fullBit(oldp+36,((1U & (~ (IData)(vlSelfRef.npc__DOT__ifu_state)))));
    bufp->fullIData(oldp+37,(vlSelfRef.npc__DOT__ifu_raddr),32);
    bufp->fullBit(oldp+38,(vlSelfRef.npc__DOT__pc_valid));
    bufp->fullIData(oldp+39,(vlSelfRef.npc__DOT__inst_reg),32);
    bufp->fullCData(oldp+40,((0x7fU & vlSelfRef.npc__DOT__inst_reg)),7);
    bufp->fullCData(oldp+41,((7U & (vlSelfRef.npc__DOT__inst_reg 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+43,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+44,((0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                       >> 7U))),5);
    bufp->fullBit(oldp+45,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x37U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                  [0x6fU] 
                                                  | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                                     | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                                        | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                           | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                              | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                                 | (IData)(vlSelfRef.npc__DOT__reg_cwen)))))))))));
    bufp->fullBit(oldp+46,(vlSelfRef.npc__DOT__reg_cwen));
    bufp->fullBit(oldp+47,(vlSelfRef.npc__DOT__mem_ren));
    bufp->fullBit(oldp+48,(vlSelfRef.npc__DOT__mem_wen));
    bufp->fullBit(oldp+49,(((IData)(vlSelfRef.npc__DOT__mem_ren) 
                            | (IData)(vlSelfRef.npc__DOT__mem_wen))));
    bufp->fullBit(oldp+50,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x6fU] | (IData)(vlSelfRef.npc__DOT__is_jalr))));
    bufp->fullBit(oldp+51,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x37U]));
    bufp->fullIData(oldp+52,(vlSelfRef.npc__DOT__imm),32);
    bufp->fullIData(oldp+53,((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelfRef.npc__DOT__inst_reg 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+54,((0xfffff000U & vlSelfRef.npc__DOT__inst_reg)),32);
    bufp->fullIData(oldp+55,(((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                            >> 0x1fU))) 
                                << 0x15U) | (0x100000U 
                                             & (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0xbU))) 
                              | (((0xff000U & vlSelfRef.npc__DOT__inst_reg) 
                                  | (0x800U & (vlSelfRef.npc__DOT__inst_reg 
                                               >> 9U))) 
                                 | (0x7feU & (vlSelfRef.npc__DOT__inst_reg 
                                              >> 0x14U))))),32);
    bufp->fullIData(oldp+56,((((- (IData)((vlSelfRef.npc__DOT__inst_reg 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 7U))))),32);
    bufp->fullBit(oldp+57,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x33U]));
    bufp->fullBit(oldp+58,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x13U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [3U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x67U] 
                                               | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                               [0x73U])))));
    bufp->fullBit(oldp+59,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x37U] | vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                            [0x17U])));
    bufp->fullBit(oldp+60,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x6fU]));
    bufp->fullBit(oldp+61,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x23U]));
    bufp->fullBit(oldp+62,(vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                           [0x17U]));
    bufp->fullBit(oldp+63,(vlSelfRef.npc__DOT__is_add));
    bufp->fullBit(oldp+64,(vlSelfRef.npc__DOT__is_jalr));
    bufp->fullBit(oldp+65,(vlSelfRef.npc__DOT__is_addi));
    bufp->fullBit(oldp+66,(vlSelfRef.npc__DOT__is_lw));
    bufp->fullBit(oldp+67,(vlSelfRef.npc__DOT__is_lbu));
    bufp->fullBit(oldp+68,((IData)(((0x2000U == (0x7000U 
                                                 & vlSelfRef.npc__DOT__inst_reg)) 
                                    & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                    [0x23U]))));
    bufp->fullBit(oldp+69,((IData)(((0U == (0x7000U 
                                            & vlSelfRef.npc__DOT__inst_reg)) 
                                    & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                    [0x23U]))));
    bufp->fullBit(oldp+70,((0x100073U == vlSelfRef.npc__DOT__inst_reg)));
    bufp->fullWData(oldp+71,(vlSelfRef.npc__DOT__opcode_d),128);
    bufp->fullCData(oldp+75,((((((7U == (7U & (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0xcU))) 
                                 << 7U) | ((6U == (7U 
                                                   & (vlSelfRef.npc__DOT__inst_reg 
                                                      >> 0xcU))) 
                                           << 6U)) 
                               | (((5U == (7U & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0xcU))) 
                                   << 5U) | ((4U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0xcU))) 
                                             << 4U))) 
                              | ((((3U == (7U & (vlSelfRef.npc__DOT__inst_reg 
                                                 >> 0xcU))) 
                                   << 3U) | ((2U == 
                                              (7U & 
                                               (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0xcU))) 
                                             << 2U)) 
                                 | (((1U == (7U & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0xcU))) 
                                     << 1U) | (0U == 
                                               (7U 
                                                & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0xcU))))))),8);
    bufp->fullBit(oldp+76,(((IData)(vlSelfRef.npc__DOT__is_add) 
                            | (IData)(vlSelfRef.npc__DOT__src2_is_imm))));
    bufp->fullBit(oldp+77,(vlSelfRef.npc__DOT__src2_is_imm));
    bufp->fullIData(oldp+78,(vlSelfRef.npc__DOT__src1),32);
    bufp->fullIData(oldp+79,(((IData)(vlSelfRef.npc__DOT__mem_ren)
                               ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                               : 0U)),32);
    bufp->fullIData(oldp+80,(vlSelfRef.npc__DOT__raddr),32);
    bufp->fullIData(oldp+81,(((IData)(vlSelfRef.npc__DOT__mem_wen)
                               ? vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0
                               : 0x80000000U)),32);
    bufp->fullCData(oldp+82,(((IData)(((0U == (0x7000U 
                                               & vlSelfRef.npc__DOT__inst_reg)) 
                                       & vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                       [0x23U])) ? 1U
                               : 0xfU)),8);
    bufp->fullSData(oldp+83,((0xfffU & vlSelfRef.npc__DOT__imm)),12);
    bufp->fullBit(oldp+84,(vlSelfRef.clk));
    bufp->fullBit(oldp+85,(vlSelfRef.reset));
    bufp->fullIData(oldp+86,(vlSelfRef.alu_result),32);
    bufp->fullIData(oldp+87,(vlSelfRef.pc),32);
    bufp->fullBit(oldp+88,(vlSelfRef.inst_valid));
    bufp->fullIData(oldp+89,(((IData)(vlSelfRef.npc__DOT__is_jalr)
                               ? (0xfffffffeU & vlSelfRef.npc__DOT____VdfgRegularize_h467b3cb3_0_0)
                               : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                  [0x6fU] ? (vlSelfRef.pc 
                                             + vlSelfRef.npc__DOT__imm)
                                   : ((IData)(4U) + vlSelfRef.pc)))),32);
    bufp->fullIData(oldp+90,(((IData)(vlSelfRef.npc__DOT__mem_ren)
                               ? ((IData)(vlSelfRef.npc__DOT__mem_ren)
                                   ? vlSelfRef.npc__DOT____VdfgExtracted_hd008e9d4__0
                                   : 0U) : ((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                             [0x6fU] 
                                             | (IData)(vlSelfRef.npc__DOT__is_jalr))
                                             ? ((IData)(4U) 
                                                + vlSelfRef.pc)
                                             : (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                [0x37U]
                                                 ? vlSelfRef.npc__DOT__imm
                                                 : 
                                                ((IData)(vlSelfRef.npc__DOT__reg_cwen)
                                                  ? 
                                                 ((0xb00U 
                                                   == 
                                                   (0xfffU 
                                                    & vlSelfRef.npc__DOT__imm))
                                                   ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                                                   : 
                                                  ((0xb02U 
                                                    == 
                                                    (0xfffU 
                                                     & vlSelfRef.npc__DOT__imm))
                                                    ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                                    : 
                                                   ((0xf11U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelfRef.npc__DOT__imm))
                                                     ? 0x79737978U
                                                     : 
                                                    ((0xf12U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelfRef.npc__DOT__imm))
                                                      ? 0x17e634bU
                                                      : 0U))))
                                                  : vlSelfRef.alu_result))))),32);
    bufp->fullIData(oldp+91,(((0xb00U == (0xfffU & vlSelfRef.npc__DOT__imm))
                               ? vlSelfRef.npc__DOT__u_csr__DOT__mcycle
                               : ((0xb02U == (0xfffU 
                                              & vlSelfRef.npc__DOT__imm))
                                   ? vlSelfRef.npc__DOT__u_csr__DOT__mcycleh
                                   : ((0xf11U == (0xfffU 
                                                  & vlSelfRef.npc__DOT__imm))
                                       ? 0x79737978U
                                       : ((0xf12U == 
                                           (0xfffU 
                                            & vlSelfRef.npc__DOT__imm))
                                           ? 0x17e634bU
                                           : 0U))))),32);
    bufp->fullIData(oldp+92,(((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                               >> 0x14U)))
                               ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                              [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                         >> 0x14U))])),32);
    bufp->fullIData(oldp+93,((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                              [0x17U] ? vlSelfRef.pc
                               : vlSelfRef.npc__DOT__src1)),32);
    bufp->fullIData(oldp+94,(((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                               ? vlSelfRef.npc__DOT__imm
                               : ((0U == (0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                   >> 0x14U)))
                                   ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                  [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                             >> 0x14U))]))),32);
    bufp->fullIData(oldp+95,(((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                               [0x17U] ? vlSelfRef.pc
                                : vlSelfRef.npc__DOT__src1) 
                              + ((IData)(vlSelfRef.npc__DOT__src2_is_imm)
                                  ? vlSelfRef.npc__DOT__imm
                                  : ((0U == (0x1fU 
                                             & (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x14U)))
                                      ? 0U : vlSelfRef.npc__DOT__u_regfile2__DOT__rf
                                     [(0x1fU & (vlSelfRef.npc__DOT__inst_reg 
                                                >> 0x14U))])))),32);
    bufp->fullBit(oldp+96,(((vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                             [0x17U] | (vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                        [0x37U] | (
                                                   vlSelfRef.npc__DOT__u_decoder7_128__DOT____VdfgBinToOneHot_Tab_hbc128af0_0_0
                                                   [0x6fU] 
                                                   | ((IData)(vlSelfRef.npc__DOT__is_jalr) 
                                                      | ((IData)(vlSelfRef.npc__DOT__is_addi) 
                                                         | ((IData)(vlSelfRef.npc__DOT__is_add) 
                                                            | ((IData)(vlSelfRef.npc__DOT__is_lw) 
                                                               | ((IData)(vlSelfRef.npc__DOT__is_lbu) 
                                                                  | (IData)(vlSelfRef.npc__DOT__reg_cwen))))))))) 
                            & (IData)(vlSelfRef.inst_valid))));
}
