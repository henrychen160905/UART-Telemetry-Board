# UART Telemetry Benchmark System

A hardware telemetry benchmark that transmits computer performance metrics over UART and computes a weighted score.

## Overview

```
Telemetry Data → Transmitter → UART Line → Receiver → Scoring Model → Score
```

This system captures telemetry (CPU freq, disk speed, memory, temperature), transmits it serially via UART, receives and reconstructs the data, then computes a benchmark score similar to a benchmark program like 3DMark or Cinebench.

## Program Modules

### Transmitter Module (`transmitter.sv`)

UART transmitter with FSM control and FIFO interface.

**Function**: Reads bytes from a FIFO and transmits them over UART (serially)

**Key Features**:
- UART frame: Start bit (0) + 8 data bits (LSB first) + Even parity + Stop bit (1)
- Configurable clock frequency and baud rate
- 5-state FSM: IDLE → START → DATA → PARITY → STOP
- Busy/idle status output

**Parameters**:
- `clock_freq` — System clock in Hz (defaults to 50 MHz)
- `baud` — UART baud rate (defaults to 9600)

**Ports**:
- `clk`, `rst` — Clock and reset
- `data_in[7:0]` — Byte to transmit from FIFO
- `fifo_empty` — FIFO empty flag (input)
- `fifo_read` — Pulse to read from FIFO (output)
- `transmit_wire` — UART TX line (output)
- `state_busy` — High when transmitting (output)

**Timing**: Each bit is held for `clock_freq / baud` clock cycles.

### Receiver Module (`receiver.sv`)

UART receiver with start detection and mid-bit sampling.

**Function**: Receives UART data, reconstructs bytes, and validates parity/stop bits.

**Key Features**:
- Falling edge start bit detection
- Mid-bit sampling at `cycles_per_bit / 2` for noise checking/immunity
- 6-state FSM: IDLE → START → DATA → PARITY → STOP → SEND
- Automatic byte reconstruction

**Parameters**:
- `clk_freq` — System clock in Hz (defaults to 50 MHz)
- `baud` — UART baud rate (defaults to 9600)

**Ports**:
- `clk`, `rst` — Clock and reset
- `data_trans` — UART RX line (input, connected to transmitter TX)
- `data_received[7:0]` — Reconstructed byte (output)
- `state_busy` — High when receiving (output)

**Timing**: Samples data at the middle of each bit period for reliability

### Scoring Module (`scoring_model.sv`)

Computes weighted benchmark score from telemetry inputs

**Scoring Equation**:
```
Score = 0.35 × f + 0.30 × d + 0.20 × m + 0.15 × t
```
Where:
- `f` = CPU clock frequency (MHz)
- `d` = Disk read/write speed (Mb/s)
- `m` = Memory usage (MB)
- `t` = Temperature (°C)

**Parameters**:
- `SCALE` — Fixed scale factor (defaults to 100)

**Ports**:
- `clk`, `rst` — Clock and reset
- `compute_enable` — Pulse high to trigger computation (input)
- `cpu_freq_mhz[15:0]` — CPU frequency in MHz (input)
- `disk_speed_mbps[15:0]` — Disk speed in Mb/s (input)
- `memory_usage[15:0]` — Memory usage in MB (input)
- `temperature_c[15:0]` — Temperature in °C (input)
- `score[31:0]` — Computed score, scaled by 100 (output)
- `valid` — High when score is ready (output)

**Usage**: Divide `score` by 100 to get the raw benchmark score.

**Implementation**: 2-phase pipeline (multiply coefficients, then sum all)

## Demo Guide

### Build and Run
```bash
cd src
make        # Build and run simulation using Verilator
make clean  # Clean artifacts from build
```

### View Waveforms
```bash
gtkwave waveform.fst
```

## Data Format

Telemetry is transmitted as **8 bytes** (4 × 16-bit values, little-endian) [means least significant byte first]:
- Bytes 0-1: CPU frequency (MHz)
- Bytes 2-3: Disk speed (Mb/s)
- Bytes 4-5: Memory usage (MB)
- Bytes 6-7: Temperature (°C)

## Example Output

```
=== UART Telemetry Benchmark Integration Test ===

Sending telemetry packet:
  CPU Freq: 4500 MHz
  Disk Speed: 2000 Mb/s
  Memory: 16384 MB
  Temperature: 70°C

=== Benchmark Score ===
Score: 5462.30
```

## Technical Details

- **UART Frame**: 1 start + 8 data + 1 parity + 1 stop = 10 bits per byte
- **Default Timing**: 50 MHz clock, 9600 baud → 5208 cycles per bit
- **Transmission**: 8 bytes @ 9600 baud ≈ 8.3 ms
- **Verification**: Complete testbench with FST waveform output
- "works outside of asicfab"
