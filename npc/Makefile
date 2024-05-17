# 函数定义：print_color
define print_color
	printf $(1)$(2)$(RESET) 
endef

# 颜色定义
YELLOW := "\033[1;33m"
CYAN := "\033[1;36m"
RESET := "\033[0m\n"

sim:
	$(call print_color,$(CYAN),"Compiling Chisel...")
	scala-cli ./vsrc/example.scala

	mv example.sv ./vsrc/example.sv 
	$(call print_color,$(CYAN),"Compiling Verilog...")
	verilator-docker --trace --cc ./vsrc/example.sv --exe ./csrc/main.cpp

	$(call print_color,$(CYAN),"Building simulation...")
	make -C obj_dir -f Vexample.mk

	$(call print_color,$(CYAN),"Running simulation...")
	./obj_dir/Vexample 