#Makefile
VERILATE := verilator
VERILATE_FLAGS := --binary --trace-fst

#Source Files
SOURCE_FILES := transmitter.sv receiver.sv

#Testbench File
TESTBENCH_FILE := tb.sv

#Top_Module
TOP_MODULE := tb

#Executable
VERILATOR_EXE := V$(basename $(TOP_MODULE))

all: $(VERILATOR_EXE)
	./$(VERILATOR_EXE)

$(VERILATOR_EXE): $(SOURCE_FILES) $(TESTBENCH_FILE)
	$(VERILATE) $(VERILATE_FLAGS) --top-module $(basename $(TOP_MODULE)) $^
	cp obj_dir/$(VERILATOR_EXE) .

run: $(VERILATOR_EXE)
	./$(VERILATOR_EXE)
clean:
	rm -rf obj dir
	rm -f $(VERILATOR_EXE)
	rm -f waveform.fst
PHONY: all run clean
