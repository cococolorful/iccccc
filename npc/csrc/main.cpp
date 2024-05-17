#include <stdio.h>

#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "Vexample.h"

vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Vexample *dut = new Vexample;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    int max_sim_time = 0;
    std::cout << "Enter max simulate times: ";
    std::cin >> max_sim_time;

    while (sim_time < max_sim_time) {
      dut->clock ^= 1;
      dut->io_in = sim_time;
      dut->reset = !(sim_time < 2); // 0:reset 1:normal
      std::cout << "sim_time: " << sim_time << std::endl;
      dut->eval();
      printf("a = %d, b = %d, f = %d\n", dut->io_out, dut->io_out, dut->io_out);

      sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}