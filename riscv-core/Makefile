fetch_sim:
	iverilog -o fetch_sim src/fetch.v src/imem.v sim/tb_fetch.v
	./fetch_sim

clean:
	rm -f fetch_sim *.vcd

.PHONY: fetch_sim clean