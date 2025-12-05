module receiver #(
        parameter int clk_freq = 50_000_000,
        parameter int baud = 9600
)(
        input  logic clk,
        input  logic rst,
        input  logic data_trans, // serial RX line (connect to transmitter.transmit_wire)
        output logic [7:0] data_received,
        output logic state_busy
);

        // Derived timing
        localparam int cycles_per_bit = clk_freq / baud;
        localparam int half_cycle = cycles_per_bit / 2;

        // Receiver FSM states
        typedef enum logic [2:0] {
                IDLE  = 3'b000,
                START = 3'b001,
                DATA  = 3'b010,
                PARITY= 3'b011,
                STOP  = 3'b100,
                SEND  = 3'b101
        } rx_state_t;

        rx_state_t current_state, next_state;

        // Internal registers
        logic [31:0] sample_counter; // counts clock cycles for bit timing
        logic [2:0]  bit_index;      // 0..7 for data bits
        logic [7:0]  shift_reg;      // shift in received bits LSB first
        logic        parity_recv;    // received parity bit
        logic        prev_data;      // previous sampled data line (for start detection)

        // Compute parity of received byte (even parity)
        wire parity_calc = ^shift_reg;

        // Sequential block: state/register updates
        always_ff @(posedge clk or posedge rst) begin
                if (rst) begin
                        current_state   <= IDLE;
                        sample_counter  <= 32'd0;
                        bit_index       <= 3'd0;
                        shift_reg       <= 8'd0;
                        parity_recv     <= 1'b0;
                        data_received   <= 8'd0;
                        state_busy      <= 1'b0;
                        prev_data       <= 1'b1;
                end else begin
                        current_state <= next_state;
                        prev_data <= data_trans;

                        case (current_state)
                                IDLE: begin
                                        sample_counter <= 32'd0;
                                        bit_index <= 3'd0;
                                        state_busy <= 1'b0;
                                end

                                START: begin
                                        state_busy <= 1'b1;
                                        // count up to half cycle to reach middle of first data bit
                                        if (sample_counter < half_cycle)
                                                sample_counter <= sample_counter + 1;
                                        else
                                                sample_counter <= 32'd0;
                                end

                                DATA: begin
                                        state_busy <= 1'b1;
                                        if (sample_counter < cycles_per_bit - 1)
                                                sample_counter <= sample_counter + 1;
                                        else begin
                                                sample_counter <= 32'd0;
                                                // sample data bit on each full bit period
                                                shift_reg[bit_index] <= data_trans;
                                                if (bit_index < 3'd7)
                                                        bit_index <= bit_index + 1;
                                        end
                                end

                                PARITY: begin
                                        state_busy <= 1'b1;
                                        if (sample_counter < cycles_per_bit - 1)
                                                sample_counter <= sample_counter + 1;
                                        else begin
                                                sample_counter <= 32'd0;
                                                parity_recv <= data_trans;
                                        end
                                end

                                STOP: begin
                                        state_busy <= 1'b1;
                                        if (sample_counter < cycles_per_bit - 1)
                                                sample_counter <= sample_counter + 1;
                                        else
                                                sample_counter <= 32'd0;
                                end

                                SEND: begin
                                        // Latch out the received byte
                                        data_received <= shift_reg;
                                        state_busy <= 1'b0;
                                end

                                default: begin
                                        // safety defaults
                                        sample_counter <= 32'd0;
                                        bit_index <= 3'd0;
                                        state_busy <= 1'b0;
                                end
                        endcase
                end
        end

        // Combinational logic
        always_comb begin
                next_state = current_state;

                case (current_state)
                        IDLE: begin
                                // Detect falling edge (idle is high -> start bit is low)
                                if (prev_data == 1'b1 && data_trans == 1'b0)
                                        next_state = START;
                        end

                        START: begin
                                // after half bit period, move to DATA to sample first data bit
                                if (sample_counter == half_cycle)
                                        next_state = DATA;
                        end

                        DATA: begin
                                // After sampling 8 bits, go to parity
                                if (sample_counter == cycles_per_bit - 1 && bit_index == 3'd7)
                                        next_state = PARITY;
                                else if (sample_counter == cycles_per_bit - 1)
                                        next_state = DATA;
                        end

                        PARITY: begin
                                if (sample_counter == cycles_per_bit - 1)
                                        next_state = STOP;
                        end

                        STOP: begin
                                if (sample_counter == cycles_per_bit - 1)
                                        next_state = SEND;
                        end

                        SEND: begin
                                next_state = IDLE;
                        end

                        default: next_state = IDLE;
                endcase
        end


endmodule


