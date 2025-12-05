// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb__Syms.h"


VL_ATTR_COLD void Vtb___024root__trace_init_sub__TOP__0(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_sub__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"fifo_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+52,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"fifo_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"tx_wire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"tx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"rx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+16,0,"rx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"compute_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"cpu_freq_mhz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"disk_speed_mbps",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"memory_usage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"temperature_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"score",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"score_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("telemetry_packet", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+2+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+54,0,"packet_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+55,0,"byte_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("received_bytes", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+24+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+32,0,"rx_byte_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"prev_rx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_receiver", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+57,0,"clk_freq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+58,0,"baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"data_trans",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"data_received",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+16,0,"state_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"cycles_per_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+60,0,"half_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+34,0,"current_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+35,0,"next_state",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"sample_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"bit_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+38,0,"shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+39,0,"parity_recv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"prev_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"parity_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_scoring", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+61,0,"SCALE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"compute_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"cpu_freq_mhz",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+19,0,"disk_speed_mbps",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"memory_usage",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+21,0,"temperature_c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+22,0,"score",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"COEFF_F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+63,0,"COEFF_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+64,0,"COEFF_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+65,0,"COEFF_T",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+41,0,"term_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"term_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"term_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"term_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"sum_intermediate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"score_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_transmitter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+57,0,"clock_freq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+58,0,"baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+52,0,"fifo_empty",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"fifo_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"transmit_wire",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"state_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"cycles_per_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+46,0,"current_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+56,0,"next_state",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+11,0,"bit_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"bit_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+48,0,"trans_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+49,0,"parity_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"bit_period_complete",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb___024root__trace_init_top(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_top\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtb___024root__trace_register(Vtb___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_register\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+57,(0x02faf080U),32);
    bufp->fullIData(oldp+58,(0x00002580U),32);
    bufp->fullIData(oldp+59,(0x00001458U),32);
    bufp->fullIData(oldp+60,(0x00000a2cU),32);
    bufp->fullIData(oldp+61,(0x00000064U),32);
    bufp->fullIData(oldp+62,(0x00000023U),32);
    bufp->fullIData(oldp+63,(0x0000001eU),32);
    bufp->fullIData(oldp+64,(0x00000014U),32);
    bufp->fullIData(oldp+65,(0x0000000fU),32);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.tb__DOT__rst));
    bufp->fullCData(oldp+2,(vlSelfRef.tb__DOT__telemetry_packet[0]),8);
    bufp->fullCData(oldp+3,(vlSelfRef.tb__DOT__telemetry_packet[1]),8);
    bufp->fullCData(oldp+4,(vlSelfRef.tb__DOT__telemetry_packet[2]),8);
    bufp->fullCData(oldp+5,(vlSelfRef.tb__DOT__telemetry_packet[3]),8);
    bufp->fullCData(oldp+6,(vlSelfRef.tb__DOT__telemetry_packet[4]),8);
    bufp->fullCData(oldp+7,(vlSelfRef.tb__DOT__telemetry_packet[5]),8);
    bufp->fullCData(oldp+8,(vlSelfRef.tb__DOT__telemetry_packet[6]),8);
    bufp->fullCData(oldp+9,(vlSelfRef.tb__DOT__telemetry_packet[7]),8);
    bufp->fullBit(oldp+10,(vlSelfRef.tb__DOT__u_receiver__DOT__prev_data));
    bufp->fullIData(oldp+11,(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter),32);
    bufp->fullBit(oldp+12,((0x00001457U == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter)));
    bufp->fullBit(oldp+13,(vlSelfRef.tb__DOT__tx_wire));
    bufp->fullBit(oldp+14,((0U != (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))));
    bufp->fullCData(oldp+15,(vlSelfRef.tb__DOT__rx_data),8);
    bufp->fullBit(oldp+16,(vlSelfRef.tb__DOT__rx_busy));
    bufp->fullBit(oldp+17,(vlSelfRef.tb__DOT__compute_enable));
    bufp->fullSData(oldp+18,(vlSelfRef.tb__DOT__cpu_freq_mhz),16);
    bufp->fullSData(oldp+19,(vlSelfRef.tb__DOT__disk_speed_mbps),16);
    bufp->fullSData(oldp+20,(vlSelfRef.tb__DOT__memory_usage),16);
    bufp->fullSData(oldp+21,(vlSelfRef.tb__DOT__temperature_c),16);
    bufp->fullIData(oldp+22,(vlSelfRef.tb__DOT__u_scoring__DOT__score_reg),32);
    bufp->fullBit(oldp+23,(vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg));
    bufp->fullCData(oldp+24,(vlSelfRef.tb__DOT__received_bytes[0]),8);
    bufp->fullCData(oldp+25,(vlSelfRef.tb__DOT__received_bytes[1]),8);
    bufp->fullCData(oldp+26,(vlSelfRef.tb__DOT__received_bytes[2]),8);
    bufp->fullCData(oldp+27,(vlSelfRef.tb__DOT__received_bytes[3]),8);
    bufp->fullCData(oldp+28,(vlSelfRef.tb__DOT__received_bytes[4]),8);
    bufp->fullCData(oldp+29,(vlSelfRef.tb__DOT__received_bytes[5]),8);
    bufp->fullCData(oldp+30,(vlSelfRef.tb__DOT__received_bytes[6]),8);
    bufp->fullCData(oldp+31,(vlSelfRef.tb__DOT__received_bytes[7]),8);
    bufp->fullIData(oldp+32,(vlSelfRef.tb__DOT__rx_byte_index),32);
    bufp->fullBit(oldp+33,(vlSelfRef.tb__DOT__prev_rx_busy));
    bufp->fullCData(oldp+34,(vlSelfRef.tb__DOT__u_receiver__DOT__current_state),3);
    bufp->fullCData(oldp+35,(vlSelfRef.tb__DOT__u_receiver__DOT__next_state),3);
    bufp->fullIData(oldp+36,(vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter),32);
    bufp->fullCData(oldp+37,(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index),3);
    bufp->fullCData(oldp+38,(vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg),8);
    bufp->fullBit(oldp+39,(vlSelfRef.tb__DOT__u_receiver__DOT__parity_recv));
    bufp->fullBit(oldp+40,((1U & VL_REDXOR_8(vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg))));
    bufp->fullIData(oldp+41,(vlSelfRef.tb__DOT__u_scoring__DOT__term_f),32);
    bufp->fullIData(oldp+42,(vlSelfRef.tb__DOT__u_scoring__DOT__term_d),32);
    bufp->fullIData(oldp+43,(vlSelfRef.tb__DOT__u_scoring__DOT__term_m),32);
    bufp->fullIData(oldp+44,(vlSelfRef.tb__DOT__u_scoring__DOT__term_t),32);
    bufp->fullIData(oldp+45,(vlSelfRef.tb__DOT__u_scoring__DOT__sum_intermediate),32);
    bufp->fullCData(oldp+46,(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state),4);
    bufp->fullCData(oldp+47,(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index),3);
    bufp->fullCData(oldp+48,(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg),8);
    bufp->fullBit(oldp+49,((1U & VL_REDXOR_8(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg))));
    bufp->fullBit(oldp+50,(vlSelfRef.tb__DOT__clk));
    bufp->fullCData(oldp+51,(vlSelfRef.tb__DOT__fifo_data_out),8);
    bufp->fullBit(oldp+52,(VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index)));
    bufp->fullBit(oldp+53,(vlSelfRef.tb__DOT__fifo_read));
    bufp->fullIData(oldp+54,(vlSelfRef.tb__DOT__packet_index),32);
    bufp->fullIData(oldp+55,(vlSelfRef.tb__DOT__byte_count),32);
    bufp->fullCData(oldp+56,(vlSelfRef.tb__DOT__u_transmitter__DOT__next_state),4);
}
