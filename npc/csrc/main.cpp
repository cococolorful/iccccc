#include <stdio.h>

#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "Vexample.h"

#define MAX_SIM_TIME 20
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
        // dut->eval();
        // m_trace->dump(sim_time);
        sim_time++;

          int a = rand() & 1;
      int b = rand() & 1;
      dut->a = a;
      dut->b = b;
      dut->eval();
      printf("a = %d, b = %d, f = %d\n", a, b, dut->f);
      assert(dut->f == (a ^ b));
      
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}