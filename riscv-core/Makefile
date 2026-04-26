# ============================================================
# BoseRV — Makefile (Verilator Edition)
# ============================================================

SRC     = src
SIM     = sim
TESTS   = tests

# Verilator simulation flags
# --binary: creates a C++ wrapper main() and builds an executable
# --timing: enables delay (#5) processing in Verilog testbenches (Verilator 5+)
# --trace: generate VCD waveforms
# -Wall: enables linting warnings
VFLAGS = --binary --timing --trace -Wall -Wno-fatal

# Source files
CORE_SRC = $(SRC)/imem.v $(SRC)/dmem.v $(SRC)/regfile.v \
           $(SRC)/alu.v  $(SRC)/decoder.v $(SRC)/fetch.v $(SRC)/top.v

.PHONY: all lint alu_sim fetch_sim top_sim if_id_sim id_ex_sim ex_mem_sim mem_wb_sim pipe_regs_sim py_pipe_top clean wave help

help:
	@echo "BoseRV — RISC-V Core Build System (Verilator)"
	@echo ""
	@echo "Targets:"
	@echo "  make lint          - Run Verilator lint on all core sources"
	@echo "  make alu_sim       - Simulate ALU using Verilator"
	@echo "  make decoder_sim   - Simulate Decoder using Verilator"
	@echo "  make fetch_sim     - Simulate Fetch stage using Verilator"
	@echo "  make top_sim       - Simulate full single-cycle core using Verilator"
	@echo "  make if_id_sim     - Simulate IF/ID pipeline register (Module 3 C1)"
	@echo "  make id_ex_sim     - Simulate ID/EX pipeline register (Module 3 C2)"
	@echo "  make ex_mem_sim    - Simulate EX/MEM pipeline register (Module 3 C3)"
	@echo "  make mem_wb_sim    - Simulate MEM/WB pipeline register (Module 3 C3)"
	@echo "  make pipe_regs_sim - Simulate all four pipeline registers"
	@echo "  make py_alu        - Simulate ALU using Python (Cocotb)"
	@echo "  make py_top        - Simulate full core using Python (Cocotb)"
	@echo "  make py_pipe_top   - Simulate pipelined core using Python (Cocotb)"
	@echo "  make wave          - Open VCD waveforms in GTKWave"
	@echo "  make clean         - Clean Verilator obj_dir and waveforms"

# ---- Linting ----
lint:
	verilator --lint-only -Wall -Wno-DECLFILENAME -Wno-MULTITOP -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -Wno-fatal $(CORE_SRC)

# ---- Simulation Targets ----
# Verilator generates the executable in obj_dir/V<top_module>

alu_sim: $(SRC)/alu.v $(SIM)/tb_alu.v
	verilator $(VFLAGS) --top-module tb_alu $^
	./obj_dir/Vtb_alu

decoder_sim: $(SRC)/decoder.v $(SIM)/tb_decoder.v
	verilator $(VFLAGS) --top-module tb_decoder $^
	./obj_dir/Vtb_decoder

fetch_sim: $(SRC)/imem.v $(SRC)/fetch.v $(SIM)/tb_fetch.v
	verilator $(VFLAGS) --top-module tb_fetch $^
	./obj_dir/Vtb_fetch

top_sim: $(CORE_SRC) $(SIM)/tb_top.v
	verilator $(VFLAGS) -Wno-DECLFILENAME --top-module tb_top $^
	./obj_dir/Vtb_top

if_id_sim: $(SRC)/if_id.v $(SIM)/tb_if_id.v
	verilator $(VFLAGS) --top-module tb_if_id $^
	./obj_dir/Vtb_if_id

id_ex_sim: $(SRC)/id_ex.v $(SIM)/tb_id_ex.v
	verilator $(VFLAGS) --top-module tb_id_ex $^
	./obj_dir/Vtb_id_ex

ex_mem_sim: $(SRC)/ex_mem.v $(SIM)/tb_ex_mem.v
	verilator $(VFLAGS) --top-module tb_ex_mem $^
	./obj_dir/Vtb_ex_mem

mem_wb_sim: $(SRC)/mem_wb.v $(SIM)/tb_mem_wb.v
	verilator $(VFLAGS) --top-module tb_mem_wb $^
	./obj_dir/Vtb_mem_wb

pipe_regs_sim: if_id_sim id_ex_sim ex_mem_sim mem_wb_sim

py_alu:
	../.venv/bin/pytest -v $(SIM)/test_alu.py -s

py_top:
	../.venv/bin/pytest -v $(SIM)/test_top.py -s

py_pipe_top:
	../.venv/bin/pytest -v $(SIM)/test_pipe_top.py -s

# ---- View Waveforms ----
wave:
	gtkwave *.vcd &

# ---- Cleanup ----
clean:
	rm -rf obj_dir *.vcd