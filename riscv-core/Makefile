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

.PHONY: all lint alu_sim fetch_sim top_sim clean wave help

help:
	@echo "BoseRV — RISC-V Core Build System (Verilator)"
	@echo ""
	@echo "Targets:"
	@echo "  make lint       - Run Verilator lint on all core sources"
	@echo "  make alu_sim    - Simulate ALU using Verilator"
	@echo "  make decoder_sim- Simulate Decoder using Verilator"
	@echo "  make fetch_sim  - Simulate Fetch stage using Verilator"
	@echo "  make top_sim    - Simulate full single-cycle core using Verilator"
	@echo "  make wave       - Open VCD waveforms in GTKWave"
	@echo "  make clean      - Clean Verilator obj_dir and waveforms"

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

# ---- View Waveforms ----
wave:
	gtkwave *.vcd &

# ---- Cleanup ----
clean:
	rm -rf obj_dir *.vcd