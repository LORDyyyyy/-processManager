CC = gcc
C_SO_FLAGS = -Wall -Werror -fpic
C_FLAGS = -Wall -Werror
LDFLAGS = -shared

SRC_DIR = core
SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
CLI_SRC = cli/*.c
HEADER = $(SRC_DIR)/core.h
TARGET_DIR = $(SRC_DIR)/library
TARGET_LIB = $(TARGET_DIR)/libprocessManger.so

core: $(TARGET_LIB)

$(TARGET_LIB): $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(C_SO_FLAGS) $(LDFLAGS) -o $@ $^

cli: $(CLI_SRC)
	$(CC) $(CFLAGS) $(SRC) $(CLI_SRC) -o cli.out

clean:
	rm -rf $(TARGET_DIR)
