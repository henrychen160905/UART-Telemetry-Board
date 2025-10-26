module tb;
    logic clk;
    logic tx;
    logic valid;

    transmitter t0(.clk(clk), .tx(tx));
    receiver r0(.rx(tx), .valid(valid));

    initial begin
        clk = 0;
        repeat (10) begin
            #5 clk = ~clk;
        end
        $finish;
    end
endmodule
