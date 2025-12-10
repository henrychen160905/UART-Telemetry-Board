#Makefile
VERILATE := verilator
VERILATE_FLAGS := --binary --trace-fst -Mdir /tmp/verilator_obj

#Source Files
SOURCE_FILES := Verilog/transmitter.sv Verilog/receiver.sv Verilog/scoring_model.sv

#Testbench File
TESTBENCH_FILE := Verilog/tb/tb.sv

#Top_Module
TOP_MODULE := tb

#Executable
VERILATOR_EXE := V$(TOP_MODULE)

all: $(VERILATOR_EXE)
	./$(VERILATOR_EXE)

$(VERILATOR_EXE): $(SOURCE_FILES) $(TESTBENCH_FILE)
	$(VERILATE) $(VERILATE_FLAGS) --top-module $(TOP_MODULE) $^
	cp /tmp/verilator_obj/$(VERILATOR_EXE) .

run: $(VERILATOR_EXE)
	./$(VERILATOR_EXE)

clean:
	rm -rf /tmp/verilator_obj
	rm -f $(VERILATOR_EXE)
	rm -f waveform.fst

.PHONY: all run clean
