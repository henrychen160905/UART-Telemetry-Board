// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb.sv", 
                                             151);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("\n=== UART Telemetry Benchmark Integration Test ===\n\n",0);
    vlSelfRef.tb__DOT__telemetry_packet[0U] = 0x94U;
    vlSelfRef.tb__DOT__telemetry_packet[1U] = 0x11U;
    vlSelfRef.tb__DOT__telemetry_packet[2U] = 0xd0U;
    vlSelfRef.tb__DOT__telemetry_packet[3U] = 7U;
    vlSelfRef.tb__DOT__telemetry_packet[4U] = 0U;
    vlSelfRef.tb__DOT__telemetry_packet[5U] = 0x40U;
    vlSelfRef.tb__DOT__telemetry_packet[6U] = 0x46U;
    vlSelfRef.tb__DOT__telemetry_packet[7U] = 0U;
    VL_WRITEF_NX("Sending telemetry packet:\n  CPU Freq: 4500 MHz\n  Disk Speed: 2000 Mb/s\n  Memory: 16384 MB\n  Temperature: 70\302\260C\n\n",0);
    vlSelfRef.tb__DOT__rst = 1U;
    vlSelfRef.tb__DOT__packet_index = 0U;
    vlSelfRef.tb__DOT__byte_count = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000064ULL, 
                                         nullptr, "tb.sv", 
                                         182);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb__DOT__rst = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000032ULL, 
                                         nullptr, "tb.sv", 
                                         184);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Starting transmission...\n\n",0);
    while ((8U != vlSelfRef.tb__DOT__byte_count)) {
        co_await vlSelfRef.__VtrigSched_h6935404c__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( (32'sh8 == tb.byte_count))", 
                                                             "tb.sv", 
                                                             189);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb.sv", 
                                         190);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg)))) {
        co_await vlSelfRef.__VtrigSched_hd68e30b0__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( tb.u_scoring.valid_reg)", 
                                                             "tb.sv", 
                                                             193);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000064ULL, 
                                         nullptr, "tb.sv", 
                                         194);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("tb.sv", 196, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000002faf080ULL, 
                                         nullptr, "tb.sv", 
                                         207);
    VL_WRITEF_NX("ERROR: Test timeout!\n",0);
    VL_FINISH_MT("tb.sv", 209, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vtrigprevexpr_hfd828878__0;
    __Vtrigprevexpr_hfd828878__0 = 0;
    // Body
    __Vtrigprevexpr_hfd828878__0 = (8U == vlSelfRef.tb__DOT__byte_count);
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg) 
                                                       != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__u_scoring__DOT__valid_reg__0)) 
                                                      << 4U) 
                                                     | (((((IData)(__Vtrigprevexpr_hfd828878__0) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr_hfd828878__1)) 
                                                          << 3U) 
                                                         | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.tb__DOT__rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__rst__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.tb__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__rst__0 
        = vlSelfRef.tb__DOT__rst;
    vlSelfRef.__Vtrigprevexpr_hfd828878__1 = __Vtrigprevexpr_hfd828878__0;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__u_scoring__DOT__valid_reg__0 
        = vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered
                                         [0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000010ULL 
                                         | vlSelfRef.__VactTriggered
                                         [0U]);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*3:0*/, 512> Vtb__ConstPool__TABLE_h12d1cb42_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vtb__ConstPool__TABLE_hb99346d6_0;

void Vtb___024root___act_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.tb__DOT__u_transmitter__DOT__fifo_empty 
        = VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index);
    vlSelfRef.tb__DOT__fifo_data_out = (VL_GTS_III(32, 8U, vlSelfRef.tb__DOT__packet_index)
                                         ? vlSelfRef.tb__DOT__telemetry_packet
                                        [(7U & vlSelfRef.tb__DOT__packet_index)]
                                         : 0U);
    __Vtableidx1 = ((VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index) 
                     << 8U) | (((IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index) 
                                << 5U) | (((0x00001457U 
                                            == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter) 
                                           << 4U) | (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))));
    vlSelfRef.tb__DOT__u_transmitter__DOT__next_state 
        = Vtb__ConstPool__TABLE_h12d1cb42_0[__Vtableidx1];
    vlSelfRef.tb__DOT__fifo_read = Vtb__ConstPool__TABLE_hb99346d6_0
        [__Vtableidx1];
}

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000001cULL & vlSelfRef.__VactTriggered
         [0U])) {
        Vtb___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tb__DOT__packet_index;
    __Vdly__tb__DOT__packet_index = 0;
    IData/*31:0*/ __VdlyMask__tb__DOT__packet_index;
    __VdlyMask__tb__DOT__packet_index = 0;
    IData/*31:0*/ __Vdly__tb__DOT__u_transmitter__DOT__bit_counter;
    __Vdly__tb__DOT__u_transmitter__DOT__bit_counter = 0;
    // Body
    __Vdly__tb__DOT__u_transmitter__DOT__bit_counter 
        = vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter;
    vlSelfRef.__Vdly__tb__DOT__u_transmitter__DOT__bit_index 
        = vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index;
    vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__shift_reg 
        = vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg;
    vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter 
        = vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter;
    vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index 
        = vlSelfRef.tb__DOT__u_receiver__DOT__bit_index;
    vlSelfRef.__Vdly__tb__DOT__rx_byte_index = vlSelfRef.tb__DOT__rx_byte_index;
    vlSelfRef.__Vdly__tb__DOT__prev_rx_busy = vlSelfRef.tb__DOT__prev_rx_busy;
    vlSelfRef.__VdlySet__tb__DOT__received_bytes__v0 = 0U;
    if (vlSelfRef.tb__DOT__rst) {
        __Vdly__tb__DOT__packet_index = 0U;
        __VdlyMask__tb__DOT__packet_index = 0xffffffffU;
        vlSelfRef.__Vdly__tb__DOT__u_transmitter__DOT__bit_index = 0U;
    } else {
        if (((IData)(vlSelfRef.tb__DOT__fifo_read) 
             & (~ (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__fifo_empty)))) {
            __Vdly__tb__DOT__packet_index = ((IData)(1U) 
                                             + vlSelfRef.tb__DOT__packet_index);
            __VdlyMask__tb__DOT__packet_index = 0xffffffffU;
        }
        if ((0U == (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))) {
            vlSelfRef.__Vdly__tb__DOT__u_transmitter__DOT__bit_index = 0U;
        } else if (((2U == (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state)) 
                    & (0x00001457U == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter))) {
            vlSelfRef.__Vdly__tb__DOT__u_transmitter__DOT__bit_index 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index)));
        }
    }
    if (((IData)(vlSelfRef.tb__DOT__rst) | (0U == (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state)))) {
        __Vdly__tb__DOT__u_transmitter__DOT__bit_counter = 0U;
    } else if ((0U != (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))) {
        __Vdly__tb__DOT__u_transmitter__DOT__bit_counter 
            = ((0x00001457U == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter)
                ? 0U : ((IData)(1U) + vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter));
    }
    vlSelfRef.tb__DOT__packet_index = ((__Vdly__tb__DOT__packet_index 
                                        & __VdlyMask__tb__DOT__packet_index) 
                                       | (vlSelfRef.tb__DOT__packet_index 
                                          & (~ __VdlyMask__tb__DOT__packet_index)));
    __VdlyMask__tb__DOT__packet_index = 0U;
    vlSelfRef.tb__DOT__u_receiver__DOT__prev_data = 
        ((IData)(vlSelfRef.tb__DOT__rst) || (IData)(vlSelfRef.tb__DOT__tx_wire));
    vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter 
        = __Vdly__tb__DOT__u_transmitter__DOT__bit_counter;
}

void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg))) {
        VL_WRITEF_NX("CPU Freq:    %0# MHz\nDisk Speed:  %0# Mb/s\nMemory:      %0# MB\nTemperature: %0# \302\260C\nBenchmark Score (scaled): %0#\nBenchmark Score (actual): %0#.%02#\n\n=== Test Complete ===\n\n",0,
                     16,vlSelfRef.tb__DOT__cpu_freq_mhz,
                     16,(IData)(vlSelfRef.tb__DOT__disk_speed_mbps),
                     16,vlSelfRef.tb__DOT__memory_usage,
                     16,(IData)(vlSelfRef.tb__DOT__temperature_c),
                     32,vlSelfRef.tb__DOT__u_scoring__DOT__score_reg,
                     32,VL_DIV_III(32, vlSelfRef.tb__DOT__u_scoring__DOT__score_reg, (IData)(0x00000064U)),
                     32,VL_MODDIV_III(32, vlSelfRef.tb__DOT__u_scoring__DOT__score_reg, (IData)(0x00000064U)));
    }
}

void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__u_transmitter__DOT__fifo_empty 
        = VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index);
}

void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__tb__DOT__byte_count;
    __Vdly__tb__DOT__byte_count = 0;
    IData/*31:0*/ __VdlyMask__tb__DOT__byte_count;
    __VdlyMask__tb__DOT__byte_count = 0;
    CData/*7:0*/ __VdlyVal__tb__DOT__received_bytes__v0;
    __VdlyVal__tb__DOT__received_bytes__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb__DOT__received_bytes__v0;
    __VdlyDim0__tb__DOT__received_bytes__v0 = 0;
    // Body
    vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg = 
        ((1U & (~ (IData)(vlSelfRef.tb__DOT__rst))) 
         && (1U & (~ (IData)(vlSelfRef.tb__DOT__compute_enable))));
    if (vlSelfRef.tb__DOT__rst) {
        vlSelfRef.tb__DOT__u_scoring__DOT__score_reg = 0U;
        vlSelfRef.tb__DOT__u_scoring__DOT__sum_intermediate = 0U;
        vlSelfRef.tb__DOT__u_scoring__DOT__term_f = 0U;
        vlSelfRef.tb__DOT__u_scoring__DOT__term_d = 0U;
        vlSelfRef.tb__DOT__u_scoring__DOT__term_m = 0U;
        vlSelfRef.tb__DOT__u_scoring__DOT__term_t = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.tb__DOT__compute_enable)))) {
            vlSelfRef.tb__DOT__u_scoring__DOT__score_reg 
                = vlSelfRef.tb__DOT__u_scoring__DOT__sum_intermediate;
            vlSelfRef.tb__DOT__u_scoring__DOT__sum_intermediate 
                = (((vlSelfRef.tb__DOT__u_scoring__DOT__term_f 
                     + vlSelfRef.tb__DOT__u_scoring__DOT__term_d) 
                    + vlSelfRef.tb__DOT__u_scoring__DOT__term_m) 
                   + vlSelfRef.tb__DOT__u_scoring__DOT__term_t);
        }
        if (vlSelfRef.tb__DOT__compute_enable) {
            vlSelfRef.tb__DOT__u_scoring__DOT__term_f 
                = ((IData)(0x00000023U) * (IData)(vlSelfRef.tb__DOT__cpu_freq_mhz));
            vlSelfRef.tb__DOT__u_scoring__DOT__term_d 
                = ((IData)(0x0000001eU) * (IData)(vlSelfRef.tb__DOT__disk_speed_mbps));
            vlSelfRef.tb__DOT__u_scoring__DOT__term_m 
                = ((IData)(0x00000014U) * (IData)(vlSelfRef.tb__DOT__memory_usage));
            vlSelfRef.tb__DOT__u_scoring__DOT__term_t 
                = ((IData)(0x0000000fU) * (IData)(vlSelfRef.tb__DOT__temperature_c));
        }
    }
    if (vlSelfRef.tb__DOT__rst) {
        vlSelfRef.__Vdly__tb__DOT__rx_byte_index = 0U;
        vlSelfRef.__Vdly__tb__DOT__prev_rx_busy = 0U;
        __Vdly__tb__DOT__byte_count = 0U;
        __VdlyMask__tb__DOT__byte_count = 0xffffffffU;
        vlSelfRef.tb__DOT__compute_enable = 0U;
    } else {
        if (VL_UNLIKELY(((((IData)(vlSelfRef.tb__DOT__prev_rx_busy) 
                           & (~ (IData)(vlSelfRef.tb__DOT__rx_busy))) 
                          & (8U > vlSelfRef.tb__DOT__rx_byte_index))))) {
            __VdlyVal__tb__DOT__received_bytes__v0 
                = vlSelfRef.tb__DOT__rx_data;
            __VdlyDim0__tb__DOT__received_bytes__v0 
                = (7U & vlSelfRef.tb__DOT__rx_byte_index);
            vlSelfRef.__VdlySet__tb__DOT__received_bytes__v0 = 1U;
            __Vdly__tb__DOT__byte_count = ((IData)(1U) 
                                           + vlSelfRef.tb__DOT__byte_count);
            __VdlyMask__tb__DOT__byte_count = 0xffffffffU;
            vlSelfRef.__Vdly__tb__DOT__rx_byte_index 
                = ((IData)(1U) + vlSelfRef.tb__DOT__rx_byte_index);
            VL_WRITEF_NX("  Received byte %0#: 0x%02x\n",0,
                         32,vlSelfRef.tb__DOT__rx_byte_index,
                         8,(IData)(vlSelfRef.tb__DOT__rx_data));
            if (VL_UNLIKELY(((7U == vlSelfRef.tb__DOT__rx_byte_index)))) {
                VL_WRITEF_NX("\n=== Telemetry Reconstructed ===\n",0);
                vlSelfRef.tb__DOT__cpu_freq_mhz = (
                                                   (vlSelfRef.tb__DOT__received_bytes
                                                    [1U] 
                                                    << 8U) 
                                                   | vlSelfRef.tb__DOT__received_bytes
                                                   [0U]);
                vlSelfRef.tb__DOT__compute_enable = 1U;
                vlSelfRef.tb__DOT__disk_speed_mbps 
                    = ((vlSelfRef.tb__DOT__received_bytes
                        [3U] << 8U) | vlSelfRef.tb__DOT__received_bytes
                       [2U]);
                vlSelfRef.tb__DOT__memory_usage = (
                                                   (vlSelfRef.tb__DOT__received_bytes
                                                    [5U] 
                                                    << 8U) 
                                                   | vlSelfRef.tb__DOT__received_bytes
                                                   [4U]);
                vlSelfRef.tb__DOT__temperature_c = 
                    ((vlSelfRef.tb__DOT__received_bytes
                      [7U] << 8U) | vlSelfRef.tb__DOT__received_bytes
                     [6U]);
            }
        } else {
            vlSelfRef.tb__DOT__compute_enable = 0U;
        }
        vlSelfRef.__Vdly__tb__DOT__prev_rx_busy = vlSelfRef.tb__DOT__rx_busy;
    }
    vlSelfRef.tb__DOT__rx_byte_index = vlSelfRef.__Vdly__tb__DOT__rx_byte_index;
    vlSelfRef.tb__DOT__prev_rx_busy = vlSelfRef.__Vdly__tb__DOT__prev_rx_busy;
    vlSelfRef.tb__DOT__byte_count = ((__Vdly__tb__DOT__byte_count 
                                      & __VdlyMask__tb__DOT__byte_count) 
                                     | (vlSelfRef.tb__DOT__byte_count 
                                        & (~ __VdlyMask__tb__DOT__byte_count)));
    __VdlyMask__tb__DOT__byte_count = 0U;
    if (vlSelfRef.__VdlySet__tb__DOT__received_bytes__v0) {
        vlSelfRef.tb__DOT__received_bytes[__VdlyDim0__tb__DOT__received_bytes__v0] 
            = __VdlyVal__tb__DOT__received_bytes__v0;
    }
    if (vlSelfRef.tb__DOT__rst) {
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter = 0U;
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index = 0U;
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__shift_reg = 0U;
        vlSelfRef.tb__DOT__u_receiver__DOT__parity_recv = 0U;
        vlSelfRef.tb__DOT__rx_data = 0U;
        vlSelfRef.tb__DOT__rx_busy = 0U;
    } else if ((4U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        if ((2U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter = 0U;
            vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index = 0U;
            vlSelfRef.tb__DOT__rx_busy = 0U;
        } else if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            vlSelfRef.tb__DOT__rx_data = vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg;
            vlSelfRef.tb__DOT__rx_busy = 0U;
        } else {
            vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter 
                = ((0x00001457U > vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)
                    ? ((IData)(1U) + vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)
                    : 0U);
            vlSelfRef.tb__DOT__rx_busy = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            vlSelfRef.tb__DOT__rx_busy = 1U;
            if ((0x00001457U > vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
                vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter 
                    = ((IData)(1U) + vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter);
            } else {
                vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter = 0U;
                vlSelfRef.tb__DOT__u_receiver__DOT__parity_recv 
                    = vlSelfRef.tb__DOT__tx_wire;
            }
        } else {
            vlSelfRef.tb__DOT__rx_busy = 1U;
            if ((0x00001457U > vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
                vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter 
                    = ((IData)(1U) + vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter);
            } else {
                vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter = 0U;
                vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__shift_reg 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index))) 
                        & (IData)(vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__shift_reg)) 
                       | (0x00ffU & ((IData)(vlSelfRef.tb__DOT__tx_wire) 
                                     << (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index))));
                if ((7U > (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index))) {
                    vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index)));
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter 
            = ((0x00000a2cU > vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)
                ? ((IData)(1U) + vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)
                : 0U);
        vlSelfRef.tb__DOT__rx_busy = 1U;
    } else {
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter = 0U;
        vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index = 0U;
        vlSelfRef.tb__DOT__rx_busy = 0U;
    }
    vlSelfRef.tb__DOT__u_receiver__DOT__shift_reg = vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__shift_reg;
    vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter 
        = vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__sample_counter;
    vlSelfRef.tb__DOT__u_receiver__DOT__bit_index = vlSelfRef.__Vdly__tb__DOT__u_receiver__DOT__bit_index;
    vlSelfRef.tb__DOT__tx_wire = ((IData)(vlSelfRef.tb__DOT__rst) 
                                  || ((1U & ((IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state) 
                                             >> 3U)) 
                                      || ((1U & ((IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state) 
                                                 >> 2U)) 
                                          || (1U & 
                                              ((2U 
                                                & (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))
                                                    ? 
                                                   VL_REDXOR_8(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg)
                                                    : 
                                                   ((IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg) 
                                                    >> (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index)))
                                                : (~ (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state)))))));
    if (vlSelfRef.tb__DOT__rst) {
        vlSelfRef.tb__DOT__u_receiver__DOT__current_state = 0U;
        vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg = 0U;
        vlSelfRef.tb__DOT__u_transmitter__DOT__current_state = 0U;
    } else {
        vlSelfRef.tb__DOT__u_receiver__DOT__current_state 
            = vlSelfRef.tb__DOT__u_receiver__DOT__next_state;
        if (vlSelfRef.tb__DOT__fifo_read) {
            vlSelfRef.tb__DOT__u_transmitter__DOT__trans_data_reg 
                = vlSelfRef.tb__DOT__fifo_data_out;
        }
        vlSelfRef.tb__DOT__u_transmitter__DOT__current_state 
            = vlSelfRef.tb__DOT__u_transmitter__DOT__next_state;
    }
    vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index 
        = vlSelfRef.__Vdly__tb__DOT__u_transmitter__DOT__bit_index;
    vlSelfRef.tb__DOT__u_receiver__DOT__next_state 
        = vlSelfRef.tb__DOT__u_receiver__DOT__current_state;
    if ((4U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        if ((2U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 0U;
        } else if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 0U;
        } else if ((0x00001457U == vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 5U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
            if ((0x00001457U == vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
                vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 4U;
            }
        } else if (((0x00001457U == vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter) 
                    & (7U == (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__bit_index)))) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 3U;
        } else if ((0x00001457U == vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 2U;
        }
    } else if ((1U & (IData)(vlSelfRef.tb__DOT__u_receiver__DOT__current_state))) {
        if ((0x00000a2cU == vlSelfRef.tb__DOT__u_receiver__DOT__sample_counter)) {
            vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 2U;
        }
    } else if (((IData)(vlSelfRef.tb__DOT__u_receiver__DOT__prev_data) 
                & (~ (IData)(vlSelfRef.tb__DOT__tx_wire)))) {
        vlSelfRef.tb__DOT__u_receiver__DOT__next_state = 1U;
    }
}

void Vtb___024root___nba_comb__TOP__1(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__1\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.tb__DOT__fifo_data_out = (VL_GTS_III(32, 8U, vlSelfRef.tb__DOT__packet_index)
                                         ? vlSelfRef.tb__DOT__telemetry_packet
                                        [(7U & vlSelfRef.tb__DOT__packet_index)]
                                         : 0U);
    __Vtableidx1 = ((VL_LTES_III(32, 8U, vlSelfRef.tb__DOT__packet_index) 
                     << 8U) | (((IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__bit_index) 
                                << 5U) | (((0x00001457U 
                                            == vlSelfRef.tb__DOT__u_transmitter__DOT__bit_counter) 
                                           << 4U) | (IData)(vlSelfRef.tb__DOT__u_transmitter__DOT__current_state))));
    vlSelfRef.tb__DOT__u_transmitter__DOT__next_state 
        = Vtb__ConstPool__TABLE_h12d1cb42_0[__Vtableidx1];
    vlSelfRef.tb__DOT__fifo_read = Vtb__ConstPool__TABLE_hb99346d6_0
        [__Vtableidx1];
}

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x000000000000001fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((0x000000000000001fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtb___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vtb___024root___timing_commit(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_commit\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (8ULL & vlSelfRef.__VactTriggered[0U]))) {
        vlSelfRef.__VtrigSched_h6935404c__0.commit(
                                                   "@( (32'sh8 == tb.byte_count))");
    }
    if ((! (0x0000000000000010ULL & vlSelfRef.__VactTriggered
            [0U]))) {
        vlSelfRef.__VtrigSched_hd68e30b0__0.commit(
                                                   "@( tb.u_scoring.valid_reg)");
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h6935404c__0.resume(
                                                   "@( (32'sh8 == tb.byte_count))");
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered
         [0U])) {
        vlSelfRef.__VtrigSched_hd68e30b0__0.resume(
                                                   "@( tb.u_scoring.valid_reg)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    Vtb___024root___timing_commit(vlSelf);
    Vtb___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        Vtb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("tb.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtb___024root___eval_phase__act(vlSelf));
    } while (Vtb___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
