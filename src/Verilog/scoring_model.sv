
module scoring_model #(
    parameter int SCALE = 100  // scale factor
)(
    input  logic        clk,
    input  logic        rst,
    input  logic        compute_enable,  // pulse high to trigger computation
    input  logic [15:0] cpu_freq_mhz,    // CPU frequency (MHz)
    input  logic [15:0] disk_speed_mbps, // Disk speed in (Mb/s)
    input  logic [15:0] memory_usage,    // Memory usage (MB)
    input  logic [15:0] temperature_c,   // Temperature in °C
    output logic [31:0] score,           // Computed benchmark score (multiplied by scale factor "SCALE")
    output logic        valid            // High when score is valid/ready
);

    // SCALE * Coefficients
    // 0.35 * 100 = 35
    // 0.30 * 100 = 30
    // 0.20 * 100 = 20
    // 0.15 * 100 = 15
    localparam int COEFF_F = 35;
    localparam int COEFF_D = 30;
    localparam int COEFF_M = 20;
    localparam int COEFF_T = 15;

    // Internal registers
    logic [31:0] term_f, term_d, term_m, term_t;
    logic [31:0] sum_intermediate;
    logic [31:0] score_reg;
    logic        valid_reg;
    logic        compute_done;

    // Score = (COEFF_F * f + COEFF_D * d + COEFF_M * m + COEFF_T * t)
    // Result is scaled by SCALE; to get raw score, divide by SCALE.

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            term_f <= 32'd0;
            term_d <= 32'd0;
            term_m <= 32'd0;
            term_t <= 32'd0;
            sum_intermediate <= 32'd0;
            score_reg <= 32'd0;
            valid_reg <= 1'b0;
            compute_done <= 1'b0;
        end else if (compute_enable && !compute_done) begin
            // First: Computes each indiviual term
            term_f <= COEFF_F * cpu_freq_mhz;
            term_d <= COEFF_D * disk_speed_mbps;
            term_m <= COEFF_M * memory_usage;
            term_t <= COEFF_T * temperature_c;
            compute_done <= 1'b1;
            valid_reg <= 1'b0;
        end else if (compute_done) begin
            // Second: sum all inidividual terms
            sum_intermediate <= term_f + term_d + term_m + term_t;
            score_reg <= term_f + term_d + term_m + term_t;
            valid_reg <= 1'b1;
        end
    end

    // Outputs
    assign score = score_reg;
    assign valid = valid_reg;

endmodule
