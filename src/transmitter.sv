module transmitter #(
    // Parameters
    parameter int clock_freq = 50_000_000,
    parameter int baud = 9600
)(

    input logic clk,  //Clock that is constant between all parts, drives FSM and cycles_per_bit
    input logic rst,  //Reset 
    input logic [7:0] data_in, //Data coming in from testbench thats placed into FIFO
    input  logic fifo_empty, //Check to see if there is a bit in the transmitter
    output logic fifo_read, //Pulse to read a bit from FIFO
    output logic transmit_wire, //UART TX line output
    output logic state_busy //Indicates transmitter is busy (not IDLE)
);

    // Calculate number of clock cycles that fit into 1 bit period
    localparam int cycles_per_bit = clock_freq / baud;

    // Assign States
    typedef enum logic [3:0] {
        IDLE = 4'b000, //Wait for data
        START = 4'b001, //Sending starts bit
        DATA = 4'b010, //Sending 8 bits
        PARITY = 4'b011, //Sending parity bit
        STOP = 4'b100 //Sending stop bit
    } uart_state_t;

    // State variables: current holds the present state, next is for computational FSM state
    uart_state_t current_state, next_state;
    logic [31:0] bit_counter;
    logic [2:0] bit_index;

    // FSM state sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            current_state <= IDLE; //Reset FSM to IDLE
        else 
            current_state <= next_state; //Update state on each clock edge
    end

    // Bit counter sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            bit_counter <= 0; //Reset counter on reset
        else if (current_state == START || current_state == DATA) begin
            if (bit_counter == cycles_per_bit)
                bit_counter <= 0; //Reset counter for next bit
            else
                bit_counter <= bit_counter + 1; //Increment counter
        end else
            bit_counter <= 0; //Reset counter when leaving START/DATA
    end

    // Transmit wire sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            transmit_wire <= 1; //Idle UART line is HIGH
        else if (current_state == STOP)
            transmit_wire <= 1; //Stop bit
        else if (current_state == START)
            transmit_wire <= 0; //Start bit
        else if (current_state == DATA)
            transmit_wire <= data_in[bit_index]; //Send current data bit
        else if (current_state == PARITY)
    end

    // FSM next state and bit_index combinational logic
    always_comb begin
        next_state = current_state; //Remain in current state
        fifo_read = 0; //Initialize FIFO
        case (current_state)
            IDLE: begin
                //If FIFO has data, start transmission
                if (!fifo_empty) begin
                    fifo_read = 1; //Read 1 byte from data in
                    next_state = START; //Move to START
                end
            end

            START: begin
                //Move to DATA after full start bit period
                if (bit_counter == cycles_per_bit) begin
                    next_state = DATA;
                    bit_index = 0; //Start sending data bits from LSB
                end
            end

            DATA: begin
                //Move to next data bit or PARITY after bit period
                if (bit_counter == cycles_per_bit) begin
                    if (bit_index == 7)
                        next_state = PARITY; //All 8 bits sent
                    else begin
                        bit_index = bit_index + 1; //Next bit
                        next_state = DATA;
                    end
                end
            end

            PARITY: begin
                //For now, move to STOP directly (parity not implemented yet)
                if (bit_counter == cycles_per_bit)
                    next_state = STOP;
            end

            STOP: begin
                //Return to IDLE after stop bit
                if (bit_counter == cycles_per_bit)
                    next_state = IDLE;
            end
        endcase
    end

    // Busy indicator
    assign state_busy = (current_state != IDLE);

endmodule
