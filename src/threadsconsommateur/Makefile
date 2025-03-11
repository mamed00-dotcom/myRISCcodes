TARGET = $(BUILD_DIR)/cond_example
SRC = cond_example.c
CC = riscv64-linux-gnu-gcc

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(TARGET) $(SRC) -lpthread -static

clean:
	rm -f $(TARGET)

