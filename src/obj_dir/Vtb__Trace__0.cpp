// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb__DOT__rst));
        bufp->chgCData(oldp+1,(vlSelfRef.tb__DOT__telemetry_packet[0]),8);
        bufp->chgCData(oldp+2,(vlSelfRef.tb__DOT__telemetry_packet[1]),8);
        bufp->chgCData(oldp+3,(vlSelfRef.tb__DOT__telemetry_packet[2]),8);
        bufp->chgCData(oldp+4,(vlSelfRef.tb__DOT__telemetry_packet[3]),8);
        bufp->chgCData(oldp+5,(vlSelfRef.tb__DOT__telemetry_packet[4]),8);
        bufp->chgCData(oldp+6,(vlSelfRef.tb__DOT__telemetry_packet[5]),8);
        bufp->chgCData(oldp+7,(vlSelfRef.tb__DOT__telemetry_packet[6]),8);
        bufp->chgCData(oldp+8,(vlSelfRef.tb__DOT__telemetry_packet[7]),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+9,(vlSelfRef.tb__DOT__u_receiver__DOT__prev_data));
        bufp->chgIData(oldp+10,(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter),32);
        bufp->chgBit(oldp+11,((0x00001457U == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter)));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+12,(vlSelfRef.tb__DOT__tx_wire));
        bufp->chgBit(oldp+13,((0U != (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))));
        bufp->chgCData(oldp+14,(vlSelfRef.tb__DOT__rx_data),8);
        bufp->chgBit(oldp+15,(vlSelfRef.tb__DOT__rx_busy));
        bufp->chgBit(oldp+16,(vlSelfRef.tb__DOT__compute_enable));
        bufp->chgSData(oldp+17,(vlSelfRef.tb__DOT__cpu_freq_mhz),16);
        bufp->chgSData(oldp+18,(vlSelfRef.tb__DOT__disk_speed_mbps),16);
        bufp->chgSData(oldp+19,(vlSelfRef.tb__DOT__memory_usage),16);
        bufp->chgSData(oldp+20,(vlSelfRef.tb__DOT__temperature_c),16);
        bufp->chgIData(oldp+21,(vlSelfRef.tb__DOT__u_scoring__DOT__score_reg),32);
        bufp->chgBit(oldp+22,(vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg));
        bufp->chgCData(oldp+23,(vlSelfRef.tb__DOT__received_bytes[0]),8);
        bufp->chgCData(oldp+24,(vlSelfRef.tb__DOT__received_bytes[1]),8);
        bufp->chgCData(oldp+25,(vlSelfRef.tb__DOT__received_bytes[2]),8);
        bufp->chgCData(oldp+26,(vlSelfRef.tb__DOT__received_bytes[3]),8);
        bufp->chgCData(oldp+27,(vlSelfRef.tb__DOT__received_bytes[4]),8);
        bufp->chgCData(oldp+28,(vlSelfRef.tb__DOT__received_bytes[5]),8);
        bufp->chgCData(oldp+29,(vlSelfRef.tb__DOT__received_bytes[6]),8);
        bufp->chgCData(oldp+30,(vlSelfRef.tb__DOT__received_bytes[7]),8);
        bufp->chgIData(oldp+31,(vlSelfRef.tb__DOT__rx_byte_index),32);
        bufp->chgBit(oldp+32,(vlSelfRef.tb__DOT__prev_rx_busy));
        bufp->chgCData(oldp+33,(vlSelfRef.tb__DOT__u_receiver__DOT__current_state),3);
        bufp->chgCData(oldp+34,(vlSelfRef.tb__DOT__u_receiver__DOT__next_state),3);
        bufp->chgIData(oldp+35,(vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter),32);
        bufp->chgCData(oldp+36,(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index),3);
        bufp->chgCData(oldp+37,(vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg),8);
        bufp->chgBit(oldp+38,(vlSelfRef.tb__DOT__u_receiver__DOT__parity_recv));
        bufp->chgBit(oldp+39,((1U & VL_REDXOR_8(vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg))));
        bufp->chgIData(oldp+40,(vlSelfRef.tb__DOT__u_scoring__DOT__term_f),32);
        bufp->chgIData(oldp+41,(vlSelfRef.tb__DOT__u_scoring__DOT__term_d),32);
        bufp->chgIData(oldp+42,(vlSelfRef.tb__DOT__u_scoring__DOT__term_m),32);
        bufp->chgIData(oldp+43,(vlSelfRef.tb__DOT__u_scoring__DOT__term_t),32);
        bufp->chgIData(oldp+44,(vlSelfRef.tb__DOT__u_scoring__DOT__sum_intermediate),32);
        bufp->chgCData(oldp+45,(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state),4);
        bufp->chgCData(oldp+46,(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index),3);
        bufp->chgCData(oldp+47,(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg),8);
        bufp->chgBit(oldp+48,((1U & VL_REDXOR_8(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg))));
    }
    bufp->chgBit(oldp+49,(vlSelfRef.tb__DOT__clk));
    bufp->chgCData(oldp+50,(vlSelfRef.tb__DOT__fifo_data_out),8);
    bufp->chgBit(oldp+51,(VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index)));
    bufp->chgBit(oldp+52,(vlSelfRef.tb__DOT__fifo_read));
    bufp->chgIData(oldp+53,(vlSelfRef.tb__DOT__packet_index),32);
    bufp->chgIData(oldp+54,(vlSelfRef.tb__DOT__byte_count),32);
    bufp->chgCData(oldp+55,(vlSelfRef.tb__DOT__u_transmitter__DOT__next_state),4);
}

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Body
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
