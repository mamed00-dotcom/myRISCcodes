# Set the build directory (use `..` to move up to root project directory)
BUILD_DIR ?= ../../build
TARGET = $(BUILD_DIR)/addit  # Correct output path
SRC = addit.c
CC = riscv64-linux-gnu-gcc

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)  # Ensure build directory exists
	$(CC) -o $(TARGET) $(SRC) -static

clean:
	rm -f $(TARGET)

