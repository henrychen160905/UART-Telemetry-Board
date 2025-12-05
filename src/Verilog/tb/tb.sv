// FIFO → Transmitter → Receiver → Scoring Model
module tb;
    // Clock and reset
    logic clk;
    logic rst;

    // FIFO signals
    logic [7:0] fifo_data_out;
    logic       fifo_empty;
    logic       fifo_read;

    // Transmitter signals
    logic       tx_wire;
    logic       tx_busy;

    // Receiver signals
    logic [7:0] rx_data;
    logic       rx_busy;

    // Scoring model signals
    logic        compute_enable;
    logic [15:0] cpu_freq_mhz;
    logic [15:0] disk_speed_mbps;
    logic [15:0] memory_usage;
    logic [15:0] temperature_c;
    logic [31:0] score;
    logic        score_valid;

    // Telemetry packet 
    logic [7:0] telemetry_packet [0:7];
    int packet_index;
    int byte_count;

    // FIFO model
    always_comb begin
        if (packet_index < 8) begin
            fifo_empty = 1'b0;
            fifo_data_out = telemetry_packet[packet_index];
        end else begin
            fifo_empty = 1'b1;
            fifo_data_out = 8'h00;
        end
    end

    // FIFO read 
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            packet_index <= 0;
        end else if (fifo_read && !fifo_empty) begin
            packet_index <= packet_index + 1;
        end
    end

    // Instantiate transmitter
    transmitter #(
        .clock_freq(50_000_000),
        .baud(9600)
    ) u_transmitter (
        .clk(clk),
        .rst(rst),
        .data_in(fifo_data_out),
        .fifo_empty(fifo_empty),
        .fifo_read(fifo_read),
        .transmit_wire(tx_wire),
        .state_busy(tx_busy)
    );

    // Instantiate receiver
    receiver #(
        .clk_freq(50_000_000),
        .baud(9600)
    ) u_receiver (
        .clk(clk),
        .rst(rst),
        .data_trans(tx_wire),
        .data_received(rx_data),
        .state_busy(rx_busy)
    );

    // Reconstruct telemetry from received bytes
    logic [7:0] received_bytes [0:7];
    logic [31:0] rx_byte_index;  // 32 to avoid width warning
    logic       prev_rx_busy;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            rx_byte_index <= 0;
            prev_rx_busy <= 1'b0;
            byte_count <= 0;
            compute_enable <= 1'b0;
        end else begin
            prev_rx_busy <= rx_busy;
            
            // Detect falling edge for byte received
            if (prev_rx_busy && !rx_busy && rx_byte_index < 8) begin
                received_bytes[rx_byte_index] <= rx_data;
                rx_byte_index <= rx_byte_index + 1;
                byte_count <= byte_count + 1;
                
                $display("  Received byte %0d: 0x%02h", rx_byte_index, rx_data);
                
                // After receiving all 8 bytes, reconstruct telemetry values
                if (rx_byte_index == 7) begin
                    cpu_freq_mhz    <= {received_bytes[1], received_bytes[0]};
                    disk_speed_mbps <= {received_bytes[3], received_bytes[2]};
                    memory_usage    <= {received_bytes[5], received_bytes[4]};
                    temperature_c   <= {received_bytes[7], received_bytes[6]};
                    compute_enable  <= 1'b1;
                    $display("\n=== Telemetry Reconstructed ===");
                end
            end else begin
                compute_enable <= 1'b0;
            end
        end
    end

    // Instantiate scoring model
    scoring_model #(
        .SCALE(100)
    ) u_scoring (
        .clk(clk),
        .rst(rst),
        .compute_enable(compute_enable),
        .cpu_freq_mhz(cpu_freq_mhz),
        .disk_speed_mbps(disk_speed_mbps),
        .memory_usage(memory_usage),
        .temperature_c(temperature_c),
        .score(score),
        .valid(score_valid)
    );

    // Monitor scoring output
    logic score_printed;
    
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            score_printed <= 1'b0;
        end else if (score_valid && !score_printed) begin
            $display("\n=== Telemetry Results ===");
            $display("CPU Freq:    %0d MHz", cpu_freq_mhz);
            $display("Disk Speed:  %0d Mb/s", disk_speed_mbps);
            $display("Memory:      %0d MB", memory_usage);
            $display("Temperature: %0d °C", temperature_c);
            $display("\n=== Benchmark Score ===");
            $display("Score (scaled): %0d", score);
            $display("Score (actual): %0d.%02d", score/100, score%100);
            $display("========================\n");
            score_printed <= 1'b1;
        end
    end

    // Clock generation (100 MHz)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Test sequence
    initial begin
        $display("\n=== UART Telemetry Benchmark Integration Test ===\n");
        
        // Initialize telemetry packet (Test case: High-performance system)
        // CPU: 4500 MHz (0x1194)
        telemetry_packet[0] = 8'h94;  // CPU freq LSB
        telemetry_packet[1] = 8'h11;  // CPU freq MSB
        // Disk: 2000 Mb/s (0x07D0)
        telemetry_packet[2] = 8'hD0;  // Disk speed LSB
        telemetry_packet[3] = 8'h07;  // Disk speed MSB
        // Memory: 16384 MB (0x4000)
        telemetry_packet[4] = 8'h00;  // Memory LSB
        telemetry_packet[5] = 8'h40;  // Memory MSB
        // Temp: 70°C (0x0046)
        telemetry_packet[6] = 8'h46;  // Temp LSB
        telemetry_packet[7] = 8'h00;  // Temp MSB

        $display("Sending telemetry packet:");
        $display("  CPU Freq: 4500 MHz");
        $display("  Disk Speed: 2000 Mb/s");
        $display("  Memory: 16384 MB");
        $display("  Temperature: 70°C\n");

        // Reset
        rst = 1;
        packet_index = 0;
        byte_count = 0;
        #100;
        rst = 0;
        #50;

        $display("Starting transmission...\n");

        // Wait for all bytes to be transmitted and received
        wait (byte_count == 8);
        #1000;

        $display("All bytes transmitted and received successfully.\n");

        // Wait for score completion
        wait (score_valid);
        #500;

        $display("\n===== Simulation Complete =====");
        $finish;
    end

    // Waveform dump
    initial begin
        $dumpfile("waveform.fst");
        $dumpvars(0, tb);
    end

    // Timeout case
    initial begin
        #50_000_000;  // 50ms timeout
        $display("ERROR: Test timeout!");
        $finish;
    end

endmodule
