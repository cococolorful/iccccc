all:
	@echo "Write this Makefile by your self."

sim:
	@scala-cli ./vsrc/example.scala
	@verilator-docker --trace --cc ./vsrc/example.sv --exe ./csrc/main.cpp
	@make -C obj_dir -f Vexample.mk
	@./obj_dir/Vexample 

include ../Makefile
