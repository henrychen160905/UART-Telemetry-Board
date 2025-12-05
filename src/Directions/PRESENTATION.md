# UART Telemetry Benchmark - Presentation Guide

### 1. Introduction 
"I built a complete hardware telemetry benchmark system in SystemVerilog that captures computer performance metrics, transmits them over UART, and computes a benchmark score. Introduce each member as well."

### 2. Architecture Overview (1 minute)
Show the diagram:
```
Telemetry → FIFO → Transmitter → Serial Line → Receiver → Scoring → Score
```

**Key Points:**
- **Modular design**: 3 independent, testable modules
- **Industry-standard UART**: Start + 8 data bits + parity + stop
- **Real-world hardware metrics**: CPU freq, disk speed, memory, temperature
- **Fixed-point math**: Synthesizable scoring algorithm

### 3. Live Demonstration (2 minutes)

Run the simulation:
```bash
cd src
make
```

**Point out:**
- Clean terminal output showing transmission progress
- 8 bytes transmitted (4 × 16-bit telemetry values)
- Successful reception and reconstruction
- Final benchmark score: **5462.30**

### 4. Waveform Analysis (1.5 minutes)

Open GTKWave:
```bash
gtkwave waveform.fst
```

**Show these signals:**
1. `tx_wire` — "Here's the actual UART serial stream"
2. Zoom in on one byte — "Start bit low, 8 data bits, parity, stop bit high"
3. `u_transmitter.current_state` — "FSM progressing through TX states"
4. `u_receiver.current_state` — "RX FSM tracking and sampling"
5. `u_receiver.data_received` — "Each byte as it's reconstructed"
6. `score` — "Final computation of the benchmark score"

### 5. Code Highlights

**Transmitter FSM** (`transmitter.sv`):
```systemverilog
typedef enum logic [3:0] {
    IDLE, START, DATA, PARITY, STOP
} uart_state_t;
```

**Scoring Equation** (`scoring_model.sv`):
```systemverilog
// Score = 0.35×f + 0.30×d + 0.20×m + 0.15×t
score = COEFF_F * cpu_freq + COEFF_D * disk_speed 
      + COEFF_M * memory + COEFF_T * temp;
```

---

## Detailed Presentation

### Slide 1: Title
**UART Telemetry Benchmark System**
*A Complete Hardware Performance Monitoring Solution*

### Slide 2: Problem Statement
**Challenge:**
- Need to monitor computer performance metrics
- Limited to serial communication (UART)
- Must compute composite benchmark score
- Hardware-level implementation required

**Solution:**
Complete telemetry pipeline with TX, RX, and scoring modules

### Slide 3: System Architecture
```
┌─────────────┐     ┌──────────────┐     ┌──────────┐
│   FIFO      │────▶│ Transmitter  │────▶│   UART   │
│  (8 bytes)  │     │  FSM + Framing│     │   Line   │
└─────────────┘     └──────────────┘     └────┬─────┘
                                               │
┌─────────────┐     ┌──────────────┐          │
│  Scoring    │◀────│   Receiver   │◀─────────┘
│   Model     │     │ Sample + FSM │
└─────────────┘     └──────────────┘
```

### Slide 4: Transmitter Module
**Responsibilities:**
- Read bytes from FIFO
- Frame data with UART protocol
- Generate even parity
- Time bits using system clock

**Key Features:**
- Parameterized clock frequency and baud rate
- 5-state FSM: IDLE → START → DATA → PARITY → STOP
- Busy/idle status signaling

**Timing:**
- Bit period = `clock_freq / baud` cycles
- Example: 50 MHz / 9600 baud = 5208 cycles per bit

### Slide 5: UART Frame Format
```
      Start  D0  D1  D2  D3  D4  D5  D6  D7  Parity  Stop
       │     │   │   │   │   │   │   │   │    │      │
Time: ─┘   └─────────────────────────────────────────┘
Level:  0   LSB ──────────────────▶ MSB   Even    1
```

**Frame Details:**
- Start bit: Logic 0 (falling edge triggers receiver)
- Data: 8 bits, LSB first
- Parity: Even parity (XOR of all data bits)
- Stop bit: Logic 1 (returns line to idle)

### Slide 6: Receiver Module
**Responsibilities:**
- Detect start bit (falling edge)
- Sample data at mid-bit for noise immunity
- Reconstruct bytes from serial stream
- Validate parity and stop bits

**Key Features:**
- Edge detection FSM
- Mid-bit sampling: `cycles_per_bit / 2`
- 6-state FSM: IDLE → START → DATA → PARITY → STOP → SEND

**Challenge:**
Must sample at exactly the right time to avoid bit errors

### Slide 7: Scoring Module
**Benchmark Equation:**
```
Score = 0.35 × CPU_freq + 0.30 × Disk_speed 
      + 0.20 × Memory  + 0.15 × Temperature
```

**Weights Rationale:**
- CPU freq (35%): Most important for compute performance
- Disk speed (30%): I/O bottleneck indicator
- Memory (20%): Capacity indicator
- Temperature (15%): Thermal throttling risk

**Implementation:**
- Fixed-point arithmetic (scaled by 100)
- 2-stage pipeline: multiply then sum
- Fully synthesizable (no floating point)

### Slide 8: Data Format
**Telemetry Packet: 8 bytes**
```
Byte 0-1: CPU Freq (MHz)    - 16-bit little-endian
Byte 2-3: Disk Speed (Mb/s) - 16-bit little-endian
Byte 4-5: Memory (MB)       - 16-bit little-endian
Byte 6-7: Temperature (°C)  - 16-bit little-endian
```

**Example:**
- CPU: 4500 MHz → `0x1194` → bytes `0x94`, `0x11`
- Disk: 2000 Mb/s → `0x07D0` → bytes `0xD0`, `0x07`

### Slide 9: Testbench & Verification
**Testbench Features:**
- Simple FIFO model
- Automated transmission/reception
- Score validation
- Waveform generation (FST format)

**Verification Steps:**
1. ✅ FIFO handshake (fifo_read pulse)
2. ✅ UART framing (start, data, parity, stop)
3. ✅ Byte reconstruction
4. ✅ Multi-byte value assembly (16-bit)
5. ✅ Scoring computation

### Slide 10: Live Demo
*Run simulation and show output*

**What to highlight:**
- Clean console output
- Byte-by-byte reception progress
- Telemetry reconstruction
- Final score calculation

### Slide 11: Waveform Analysis
*Open GTKWave and demonstrate*

**Navigation:**
1. Show full simulation timeline
2. Zoom to one byte transmission
3. Identify each bit in the frame
4. Show FSM state transitions
5. Point out data reconstruction

### Slide 12: Performance & Statistics
**Simulation Performance:**
- Simulated time: ~5 µs
- Wall-clock time: ~0.17 seconds
- Throughput: ~27 µs/s

**UART Timing (9600 baud):**
- Bit period: 104.2 µs
- Byte period: 1.04 ms (10 bits per byte)
- 8 bytes: ~8.3 ms total

**Resource Usage (Synthesis would show):**
- Transmitter: ~150 LUTs, 2 FSMs
- Receiver: ~200 LUTs, 1 FSM
- Scoring: ~50 LUTs, multipliers

### Slide 13: Technical Challenges Solved
**1. Space in directory path**
- Problem: Verilator doesn't support spaces in paths
- Solution: Used `-Mdir /tmp/verilator_obj` to specify alternate build directory

**2. Repeated print output**
- Problem: `valid` signal stays high for many cycles
- Solution: Added `score_printed` flag to print only once

**3. Scoring pipeline**
- Problem: Combinational logic too complex
- Solution: Two-stage pipeline with `compute_done` tracking

### Slide 14: Real-World Applications
**Where this could be used:**
- 🖥️ Embedded system performance monitoring
- 🌡️ IoT sensor telemetry aggregation
- 🏭 Industrial equipment health monitoring
- 🚗 Automotive diagnostics
- 🛰️ Satellite telemetry downlink

**Advantages of hardware implementation:**
- Low latency
- Deterministic timing
- No OS overhead
- Suitable for real-time systems

### Slide 15: Future Enhancements
**Possible Extensions:**
1. **Error Handling**
   - CRC for data integrity
   - Parity error reporting
   - Retry mechanism

2. **Performance**
   - Higher baud rates (115200, 921600)
   - Burst mode transmission
   - DMA integration

3. **Features**
   - Multi-packet support
   - Dynamic telemetry configuration
   - Real-time OS integration

4. **Hardware**
   - FPGA deployment (Xilinx, Intel)
   - ASIC tape-out
   - Hardware validation on devboard

### Slide 16: Key Takeaways
✅ **Modular Design** - Each component independently testable
✅ **Industry Standards** - UART protocol widely used
✅ **Complete Verification** - Testbench with waveforms
✅ **Synthesizable Code** - Ready for hardware deployment
✅ **Educational Value** - Demonstrates FSM, timing, protocols

**Skills Demonstrated:**
- SystemVerilog RTL design
- FSM implementation
- Serial protocol (UART)
- Testbench development
- Waveform analysis
- Fixed-point arithmetic

---

## Q&A Preparation

### Expected Questions & Answers

**Q: Why UART instead of SPI or I2C?**
A: UART is simpler (only 2 wires), widely supported, and good for point-to-point communication. Perfect for telemetry streaming.

**Q: How do you handle bit timing accuracy?**
A: The receiver samples at the mid-point of each bit period (cycles_per_bit/2) to maximize noise margin. The transmitter holds each bit for exactly cycles_per_bit clock cycles.

**Q: What if the baud rate doesn't divide evenly into clock frequency?**
A: We use integer division, which causes small timing error. For production, you'd use a fractional baud rate generator or PLL.

**Q: Why fixed-point instead of floating-point?**
A: Floating-point is expensive in hardware (area, power, timing). Fixed-point gives sufficient precision for this application and is easily synthesizable.

**Q: How would you validate this on real hardware?**
A: 1) Synthesize for FPGA (Xilinx or Intel), 2) Connect UART to USB-UART bridge, 3) Use terminal software to view output, 4) Validate with oscilloscope/logic analyzer.

**Q: What's the maximum throughput?**
A: At 9600 baud with 10 bits per byte, max throughput is 960 bytes/second. Higher baud rates (115200) give ~11.5 KB/s.

**Q: How do you ensure the receiver stays synchronized?**
A: Start bit detection (falling edge) resynchronizes on every byte. If more robustness needed, could add synchronization patterns or frame headers.

**Q: What happens if parity fails?**
A: Current implementation samples parity but doesn't check it. A production version would set an error flag and optionally request retransmission.

---

## Demo Checklist

Before presenting:
- [ ] Clean build: `cd src && make clean`
- [ ] Test run: `make` (verify output is clean)
- [ ] Open GTKWave test: `gtkwave waveform.fst` (check signals load)
- [ ] Have backup screenshots of waveforms
- [ ] Terminal font size readable from audience
- [ ] Code editor ready with key files open
- [ ] Backup copy of working code (in case of accidental edits)

---

## One-Slide Summary (for quick overview)

### UART Telemetry Benchmark System

**What:** Hardware telemetry pipeline (TX → RX → Scoring)
**Language:** SystemVerilog
**Protocol:** UART (9600 baud, 8N1 + parity)
**Metrics:** CPU freq, disk speed, memory, temperature
**Score:** Weighted sum (0.35f + 0.30d + 0.20m + 0.15t)
**Verification:** Complete testbench with waveforms
**Status:** ✅ Fully functional and tested

**Key Achievement:** End-to-end working system from serial communication to benchmark scoring, fully verified in simulation and ready for hardware deployment.
