TARGET = $(BUILD_DIR)/program
SRC = program.s
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld

all: $(TARGET)

$(TARGET): $(SRC)
	$(AS) -o program.o $(SRC)
	$(LD) -o $(TARGET) program.o
	rm -f program.o

clean:
	rm -f $(TARGET) program.o

