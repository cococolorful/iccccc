#include <stdio.h>

#include "Vexample.h"
#include "verilated.h"
#include <iostream>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

vluint64_t sim_time = 0;

void dut_reset(Vexample *dut, const int &sim_time, int begin_time) {
  dut->reset = 0;
  if (sim_time < begin_time) {
    dut->reset = 1;
  }
}
void set_input(Vexample *dut, const int &sim_time) {
  dut->io_in = sim_time;
  std::cout << "sim_time: " << sim_time << std::endl;
}

void set_output(Vexample *dut, const int &sim_time) {
  std::cout << "io_out: " << int(dut->io_out) << std::endl;
}

int main(int argc, char **argv, char **env) {
  Vexample *dut = new Vexample;

  Verilated::traceEverOn(true);
  VerilatedVcdC *m_trace = new VerilatedVcdC;
  dut->trace(m_trace, 5);
  m_trace->open("/tmp/Vexample.vcd");

  int max_sim_time = 0;
  std::cout << "Enter max simulate times: ";
  std::cin >> max_sim_time;

  while (sim_time < max_sim_time) {
    dut_reset(dut, sim_time, 1);

    dut->clock ^= 1;

    set_input(dut, sim_time);

    dut->eval();

    set_output(dut, sim_time);

    m_trace->dump(sim_time);
    sim_time++;
  }

  m_trace->close();
  delete dut;
  exit(EXIT_SUCCESS);
}