all:
	@echo "Write this Makefile by your self."

sim:
	@verilator-docker --trace --cc ./vsrc/example.v --exe ./csrc/main.cpp
	@make -C obj_dir -f Vexample.mk
	@./obj_dir/Vexample 

include ../Makefile
