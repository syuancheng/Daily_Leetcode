BUILD_DIR := build
TARGET := $(BUILD_DIR)/bthread_example

.PHONY: all configure build run clean

all: build

configure:
	cmake -S . -B $(BUILD_DIR)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
