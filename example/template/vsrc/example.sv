// Generated by CIRCT firtool-1.62.0
module RegisterModule(
  input         clock,
                reset,
  input  [11:0] io_in,
  output [11:0] io_out
);

  reg [11:0] register;
  always @(posedge clock)
    register <= io_in + 12'h1;
  assign io_out = register;
endmodule

