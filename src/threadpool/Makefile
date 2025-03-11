TARGET = $(BUILD_DIR)/thread_pool
SRC = thread_pool.c
CC = riscv64-linux-gnu-gcc

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(TARGET) $(SRC) -lpthread -static

clean:
	rm -f $(TARGET)

