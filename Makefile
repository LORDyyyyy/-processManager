CC = gcc
CFLAGS = -Wall -Werror -fpic
LDFLAGS = -shared

SRC_DIR = core
SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
HEADER = $(SRC_DIR)/core.h
TARGET_DIR = $(SRC_DIR)/library
TARGET_LIB = $(TARGET_DIR)/libprocessManger.so

.PHONY: core clean

core: $(TARGET_LIB)

$(TARGET_LIB): $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET_DIR)
