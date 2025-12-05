// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__rst__0 
        = vlSelfRef.tb__DOT__rst;
    vlSelfRef.__Vtrigprevexpr_hfd828878__1 = (8U == vlSelfRef.tb__DOT__byte_count);
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__u_scoring__DOT__valid_reg__0 
        = vlSelfRef.tb__DOT__u_scoring__DOT__valid_reg;
}

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("waveform.fst"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vtb___024root___eval_final(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_final\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_settle(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_settle\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb.sv", 5, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtb___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_triggers__stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__0\n"); );
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

VL_ATTR_COLD void Vtb___024root____Vm_traceActivitySetAll(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb___024root___stl_sequent__TOP__0(vlSelf);
        Vtb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__stl\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( (32'sh8 == tb.byte_count))\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( tb.u_scoring.valid_reg)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root____Vm_traceActivitySetAll(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root____Vm_traceActivitySetAll\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
}

VL_ATTR_COLD void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset\n"); );
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6743979137201610926ull);
    vlSelf->tb__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1156696098083290880ull);
    vlSelf->tb__DOT__fifo_data_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6474497620539580434ull);
    vlSelf->tb__DOT__fifo_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16337270600962257125ull);
    vlSelf->tb__DOT__tx_wire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11326962178246528029ull);
    vlSelf->tb__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1183013025202763192ull);
    vlSelf->tb__DOT__rx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11363319133021663357ull);
    vlSelf->tb__DOT__compute_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4838052327536806515ull);
    vlSelf->tb__DOT__cpu_freq_mhz = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8745852916801519259ull);
    vlSelf->tb__DOT__disk_speed_mbps = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12653560920917673311ull);
    vlSelf->tb__DOT__memory_usage = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16318773788111845027ull);
    vlSelf->tb__DOT__temperature_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18041491251179756101ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb__DOT__telemetry_packet[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17119941802352585328ull);
    }
    vlSelf->tb__DOT__packet_index = 0;
    vlSelf->tb__DOT__byte_count = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb__DOT__received_bytes[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3674438733873507052ull);
    }
    vlSelf->tb__DOT__rx_byte_index = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13805321868832558116ull);
    vlSelf->tb__DOT__prev_rx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2534676307893056716ull);
    vlSelf->tb__DOT__u_transmitter__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10068300817005254060ull);
    vlSelf->tb__DOT__u_transmitter__DOT__current_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17911324677470739093ull);
    vlSelf->tb__DOT__u_transmitter__DOT__next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1633523393479566504ull);
    vlSelf->tb__DOT__u_transmitter__DOT__bit_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 684164527576271907ull);
    vlSelf->tb__DOT__u_transmitter__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7041888818021036719ull);
    vlSelf->tb__DOT__u_transmitter__DOT__trans_data_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3310574546945472695ull);
    vlSelf->tb__DOT__u_receiver__DOT__current_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 216892687294864264ull);
    vlSelf->tb__DOT__u_receiver__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4381025959061692170ull);
    vlSelf->tb__DOT__u_receiver__DOT__sample_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3254382192604360220ull);
    vlSelf->tb__DOT__u_receiver__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15479191538267571822ull);
    vlSelf->tb__DOT__u_receiver__DOT__shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8313231214831712213ull);
    vlSelf->tb__DOT__u_receiver__DOT__parity_recv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2102317009052873096ull);
    vlSelf->tb__DOT__u_receiver__DOT__prev_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4601946345078438333ull);
    vlSelf->tb__DOT__u_scoring__DOT__term_f = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 539539831359069445ull);
    vlSelf->tb__DOT__u_scoring__DOT__term_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4723611720581323990ull);
    vlSelf->tb__DOT__u_scoring__DOT__term_m = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10677794705455063516ull);
    vlSelf->tb__DOT__u_scoring__DOT__term_t = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8285014361152290397ull);
    vlSelf->tb__DOT__u_scoring__DOT__sum_intermediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16446649265370034354ull);
    vlSelf->tb__DOT__u_scoring__DOT__score_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14624319291280757443ull);
    vlSelf->tb__DOT__u_scoring__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12156713842303674343ull);
    vlSelf->__Vdly__tb__DOT__rx_byte_index = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13787048407712230265ull);
    vlSelf->__Vdly__tb__DOT__prev_rx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9723866186314989162ull);
    vlSelf->__Vdly__tb__DOT__u_transmitter__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8703075583398294285ull);
    vlSelf->__Vdly__tb__DOT__u_receiver__DOT__sample_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12544705277562783633ull);
    vlSelf->__Vdly__tb__DOT__u_receiver__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16084691429890513859ull);
    vlSelf->__Vdly__tb__DOT__u_receiver__DOT__shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 735322043392632673ull);
    vlSelf->__VdlySet__tb__DOT__received_bytes__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3935217543338555246ull);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15235130861835199399ull);
    vlSelf->__Vtrigprevexpr_hfd828878__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2872333735634871392ull);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__u_scoring__DOT__valid_reg__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1779039879508331838ull);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
