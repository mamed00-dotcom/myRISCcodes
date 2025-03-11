# Root directory
ROOT_DIR := $(shell pwd)
SRC_DIR := $(ROOT_DIR)/src
BUILD_DIR := $(ROOT_DIR)/build

# Get all subdirectories inside src/
DIRS := $(wildcard $(SRC_DIR)/*)

# Default target: Build all programs
all:
	@mkdir -p $(BUILD_DIR)
	@for dir in $(DIRS); do \
		echo "Building in $$dir..."; \
		$(MAKE) -C $$dir BUILD_DIR=$(BUILD_DIR); \
	done

# Clean all programs
clean:
	@for dir in $(DIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
	rm -rf $(BUILD_DIR)

