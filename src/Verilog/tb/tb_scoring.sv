// Simple testbench for scoring_model.sv
// Demonstrates computing benchmark scores with sample telemetry inputs
module tb_scoring;
    logic        clk;
    logic        rst;
    logic        compute_enable;
    logic [15:0] cpu_freq_mhz;
    logic [15:0] disk_speed_mbps;
    logic [15:0] memory_usage;
    logic [15:0] temperature_c;
    logic [31:0] score;
    logic        valid;

    // Instantiation
    scoring_model #(
        .SCALE(100)
    ) dut (
        .clk(clk),
        .rst(rst),
        .compute_enable(compute_enable),
        .cpu_freq_mhz(cpu_freq_mhz),
        .disk_speed_mbps(disk_speed_mbps),
        .memory_usage(memory_usage),
        .temperature_c(temperature_c),
        .score(score),
        .valid(valid)
    );

    // Clock gen
    initial begin
        clk = 0;
        forever #5 clk = ~clk;  // 10ns period (100 MHz clock)
    end

    // Test sequence
    initial begin
        $display("=== Scoring Model Testbench ===");
        
        // Reset
        rst = 1;
        compute_enable = 0;
        cpu_freq_mhz = 0;
        disk_speed_mbps = 0;
        memory_usage = 0;
        temperature_c = 0;
        #20;
        rst = 0;
        #10;

        // Test case 1: Typical desktop PC
        $display("\nTest 1: Desktop PC");
        cpu_freq_mhz = 3000;    // 3 GHz
        disk_speed_mbps = 500;  // 500 Mb/s SSD
        memory_usage = 8192;    // 8 GB
        temperature_c = 65;     // 65°C
        compute_enable = 1;
        #10;
        compute_enable = 0;
        #30;
        if (valid) begin
            $display("  Inputs: f=%0d MHz, d=%0d Mb/s, m=%0d MB, t=%0d °C", 
                     cpu_freq_mhz, disk_speed_mbps, memory_usage, temperature_c);
            $display("  Score (scaled): %0d", score);
            $display("  Score (actual): %0d.%02d", score/100, score%100);
        end

        // Test case 2: High-end workstation
        $display("\nTest 2: High-end Workstation");
        cpu_freq_mhz = 5000;    // 5 GHz
        disk_speed_mbps = 3500; // NVMe 3.5 GB/s
        memory_usage = 32768;   // 32 GB
        temperature_c = 75;     // 75°C
        compute_enable = 1;
        #10;
        compute_enable = 0;
        #30;
        if (valid) begin
            $display("  Inputs: f=%0d MHz, d=%0d Mb/s, m=%0d MB, t=%0d °C", 
                     cpu_freq_mhz, disk_speed_mbps, memory_usage, temperature_c);
            $display("  Score (scaled): %0d", score);
            $display("  Score (actual): %0d.%02d", score/100, score%100);
        end

        // Test case 3: Low-power device
        $display("\nTest 3: Low-power Device");
        cpu_freq_mhz = 1200;    // 1.2 GHz
        disk_speed_mbps = 100;  // eMMC
        memory_usage = 2048;    // 2 GB
        temperature_c = 45;     // 45°C
        compute_enable = 1;
        #10;
        compute_enable = 0;
        #30;
        if (valid) begin
            $display("  Inputs: f=%0d MHz, d=%0d Mb/s, m=%0d MB, t=%0d °C", 
                     cpu_freq_mhz, disk_speed_mbps, memory_usage, temperature_c);
            $display("  Score (scaled): %0d", score);
            $display("  Score (actual): %0d.%02d", score/100, score%100);
        end

        #50;
        $display("\n=== Test Complete ===");
        $finish;
    end

    // Waveform dump
    initial begin
        $dumpfile("scoring_waveform.fst");
        $dumpvars(0, tb_scoring);
    end

endmodule
