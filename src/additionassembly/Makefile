TARGET = $(BUILD_DIR)/addp
SRC = addp.s
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld

all: $(TARGET)

$(TARGET): $(SRC)
	$(AS) -o addp.o $(SRC)
	$(LD) -o $(TARGET) addp.o
	rm -f addp.o

clean:
	rm -f $(TARGET) addp.o

