module receiver
#(
parameter int clk_freq = 50000000,
parameter int baud = 9600,
parameter int num = 0
)
(
input logic clk,
input int   clk_freq,
input int   baud,
input logic rst,
input logic data_trans,
output logic [7:0] data_received,
output logic state_busy
);

typedef enum logic[2:0]
{
        IDLE: 3'b000,
        READ: 3'b001,
        CHECK:3'b010,
        CONVERT: 3'b011,
        STOP: 3'b100
        SEND: 3'b101
}
state;

//Define Dummy bitstring to temporarily store received data
logic [7:0] data_col;

//Define clock
localparam bit_cycle = clk_feq/baud;
logic [31:0] bit_counter;


//Define FSM state's
state state_c , state_n;

//Sequential Logic Block
always_ff @(posedge clk or posedge rst)
begin

state_n = state_c;

        //State Transition Logic
        case(state_c)
                IDLE:  state_n = !data_trans ? READ  : IDLE  ;
                READ:  state_n = (num < 8) ? CHECK : READ    ;
                CHECK: state_n = data_trans ? STOP : IDLE    ;
                STOP:  state_n = data_trans ? SEND : READ    ;
                SEND:  state_n = !state_busy ? IDLE : READ   ;

                default state_n = IDLE;
        endcase

        //In IDLE state, the 
        //receiver will reset
        //the num, state_busy,
        //and data_col params.
        if (state_c == IDLE)
        begin
                num = 0;
                state_busy = 0;
                data_col <= 0;
        end

        //In READ state, the
        //reveiver will set
        //state_busy to high
        //and start collecting
        //the transfered data,
        //incrementing num every
        //time a new bit comes 
        //through. 
        if (state_c == READ)
        begin
                state_busy = 1;
                data_col[num] <= data_trans;
                num += 1;
        end

        //In CHECK state, the 
        //receiver will check
        //the parity bit.
        if (state_c == CHECK)
        begin
                if (data_trans)
                begin
                        num = 0;
                end
        end

        //IN STOP state, the
        //reveiver will check
        //for the stop bit.
        if (state_c == STOP)
        begin
                if (data_trans)
                begin
                        state_busy = 0;
                end
        end


        //In SEND state, the 
        //reveiver will send 
        //date collected.
        if (state_c == SEND)
        begin
                data_received <= data_col;
        end
end

endmodule


