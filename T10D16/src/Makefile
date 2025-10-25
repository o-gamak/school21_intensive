CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRC_DIR = .
BUILD_DIR = ../build

TARGET_2 = $(BUILD_DIR)/Quest_2

SRCS_LIST = $(SRC_DIR)/list.c $(SRC_DIR)/list_test.c

.PHONY: all clean list_test

all: list_test

list_test: $(TARGET_2)

$(TARGET_2): $(SRCS_LIST)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS_LIST) -DLIST -o $(TARGET_2)

clean:
	rm -rf $(BUILD_DIR)
	@echo "🧹 Build directory cleaned"