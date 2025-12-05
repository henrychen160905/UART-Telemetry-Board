// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vtb___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"IDLE", "START", "DATA", "PARITY", "STOP", 
                                "SEND"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(1, "receiver.rx_state_t", 6, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IDLE", "START", "DATA", "PARITY", "STOP"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100"};
        tracep->declDTypeEnum(2, "transmitter.uart_state_t", 5, 4, __VenumItemNames, __VenumItemValues);
    }
}

void Vtb___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtb___024root__traceDeclTypesSub0(tracep);
}
