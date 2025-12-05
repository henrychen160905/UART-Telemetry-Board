// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__rst;
    CData/*7:0*/ tb__DOT__fifo_data_out;
    CData/*0:0*/ tb__DOT__fifo_read;
    CData/*0:0*/ tb__DOT__tx_wire;
    CData/*7:0*/ tb__DOT__rx_data;
    CData/*0:0*/ tb__DOT__rx_busy;
    CData/*0:0*/ tb__DOT__compute_enable;
    CData/*0:0*/ tb__DOT__prev_rx_busy;
    CData/*0:0*/ tb__DOT__u_transmitter__DOT__fifo_empty;
    CData/*3:0*/ tb__DOT__u_transmitter__DOT__current_state;
    CData/*3:0*/ tb__DOT__u_transmitter__DOT__next_state;
    CData/*2:0*/ tb__DOT__u_transmitter__DOT__bit_index;
    CData/*7:0*/ tb__DOT__u_transmitter__DOT__trans_data_reg;
    CData/*2:0*/ tb__DOT__u_receiver__DOT__current_state;
    CData/*2:0*/ tb__DOT__u_receiver__DOT__next_state;
    CData/*2:0*/ tb__DOT__u_receiver__DOT__bit_index;
    CData/*7:0*/ tb__DOT__u_receiver__DOT__shift_reg;
    CData/*0:0*/ tb__DOT__u_receiver__DOT__parity_recv;
    CData/*0:0*/ tb__DOT__u_receiver__DOT__prev_data;
    CData/*0:0*/ tb__DOT__u_scoring__DOT__valid_reg;
    CData/*0:0*/ __Vdly__tb__DOT__prev_rx_busy;
    CData/*2:0*/ __Vdly__tb__DOT__u_transmitter__DOT__bit_index;
    CData/*2:0*/ __Vdly__tb__DOT__u_receiver__DOT__bit_index;
    CData/*7:0*/ __Vdly__tb__DOT__u_receiver__DOT__shift_reg;
    CData/*0:0*/ __VdlySet__tb__DOT__received_bytes__v0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__rst__0;
    CData/*0:0*/ __Vtrigprevexpr_hfd828878__1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__u_scoring__DOT__valid_reg__0;
    CData/*0:0*/ __VactDidInit;
    SData/*15:0*/ tb__DOT__cpu_freq_mhz;
    SData/*15:0*/ tb__DOT__disk_speed_mbps;
    SData/*15:0*/ tb__DOT__memory_usage;
    SData/*15:0*/ tb__DOT__temperature_c;
    IData/*31:0*/ tb__DOT__packet_index;
    IData/*31:0*/ tb__DOT__byte_count;
    IData/*31:0*/ tb__DOT__rx_byte_index;
    IData/*31:0*/ tb__DOT__u_transmitter__DOT__bit_counter;
    IData/*31:0*/ tb__DOT__u_receiver__DOT__sample_counter;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__term_f;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__term_d;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__term_m;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__term_t;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__sum_intermediate;
    IData/*31:0*/ tb__DOT__u_scoring__DOT__score_reg;
    IData/*31:0*/ __Vdly__tb__DOT__rx_byte_index;
    IData/*31:0*/ __Vdly__tb__DOT__u_receiver__DOT__sample_counter;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> tb__DOT__telemetry_packet;
    VlUnpacked<CData/*7:0*/, 8> tb__DOT__received_bytes;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h6935404c__0;
    VlTriggerScheduler __VtrigSched_hd68e30b0__0;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
