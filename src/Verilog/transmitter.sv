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

    //Data/Parity registers
    logic [7:0] trans_data_reg; //A register to hold the byte being transmitted
    logic parity_bit; //Calculates parity bit

    //Parity Calc (even parity)
    assign parity_bit = ^trans_data_reg; //^ is XOR

    // Bit period complete signal
    wire bit_period_complete = (bit_counter == cycles_per_bit-1);

    // FSM state sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            current_state <= IDLE; //Reset FSM to IDLE
        else 
            current_state <= next_state; //Update state on each clock edge
    end

    //Data register sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            trans_data_reg <= 8'b0; //Resets data registor
        else if (fifo_read)
            trans_data_reg <= data_in; //Load data when getting signal to read from FIFO
    end 

    //Bit index sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            bit_index <= 3'b0; //Reset bit index
        else if (current_state == IDLE)
            bit_index <= 3'b0; //Reset bit index
        else if (current_state == DATA && bit_counter == cycles_per_bit -1) begin
            bit_index <= bit_index + 1; //Increment bit index after each bit sent
        end 
    end 

    // Bit counter sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst || current_state == IDLE)
            bit_counter <= 0; //Reset counter on reset or IDLE
        else if (current_state != IDLE) begin
            if (bit_counter == cycles_per_bit-1)
                bit_counter <= 0; //Reset counter for next bit
            else
                bit_counter <= bit_counter + 1; //Increment counter
        end
    end

    // Transmit wire sequential block
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            transmit_wire <= 1'b1; //Idle UART line is HIGH
        else begin
            case (current_state)
            IDLE:
                transmit_wire <= 1'b1; //Stop bit
            START:
                transmit_wire <= 1'b0; //Start bit
            DATA:
                transmit_wire <= trans_data_reg[bit_index]; //Send current data bit
            PARITY:
                transmit_wire <= parity_bit; // Send parity bit
            STOP: 
                transmit_wire <= 1'b1; // Stop bit
            default:
                transmit_wire <= 1'b1; //Default to IDLE
            endcase
        end
    end

    // FSM next state and bit_index combinational logic
    always_comb begin
        next_state = current_state; //Remain in current state
        fifo_read = 1'b0; //Initialize FIFO 

        case (current_state)
            IDLE: begin
                //If FIFO has data, start transmission
                if (!fifo_empty) begin
                    fifo_read = 1'b1; //Read 1 byte from data in
                    next_state = START; //Move to START
                end
            end

            START: begin
                //Move to DATA after full start bit period
                if (bit_period_complete) begin
                    next_state = DATA;
                end
            end

            DATA: begin
                //Move to next data bit or PARITY after bit period
                if (bit_period_complete) begin
                    if (bit_index == 7) //All 8 bits sent
                        next_state = PARITY; 
                    else
                        next_state = DATA;
                end
            end

            PARITY: begin
                if (bit_period_complete)
                    next_state = STOP;
            end

            STOP: begin
                //Return to IDLE after stop bit
                if (bit_period_complete)
                    next_state = IDLE;
            end

            default: begin
                next_state = IDLE;
            end
        endcase
    end

    // Busy indicator
    assign state_busy = (current_state != IDLE);

endmodule
