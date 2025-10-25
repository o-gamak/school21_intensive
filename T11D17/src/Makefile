CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD_DIR = ../build
TARGET_1 = $(BUILD_DIR)/Quest_1
TARGET_2 = $(BUILD_DIR)/Quest_2
TARGET_3 = $(BUILD_DIR)/Quest_3

all: door_struct list_test stack_test 

all_ch: clean clang_format check door_struct list_test stack_test leak

door_struct: $(TARGET_1)

list_test: $(TARGET_2)

stack_test: $(TARGET_3)

$(TARGET_1): $(BUILD_DIR)
	$(CC) $(CFLAGS) dmanager_module.c -o $(TARGET_1)

$(TARGET_2): $(BUILD_DIR)
	$(CC) $(CFLAGS) list_test.c list.c -o $(TARGET_2)

$(TARGET_3): $(BUILD_DIR)
	$(CC) $(CFLAGS) stack_test.c stack.c -o $(TARGET_3)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

clang_format:
	clang-format --assume-filename=.clang-format -i *.c *.h

leak:
	leaks -atExit -- $(TARGET_1)
	leaks -atExit -- $(TARGET_2)
	leaks -atExit -- $(TARGET_3)

clean:
	rm -rf $(BUILD_DIR)/

rebuild: clean all

.PHONY: all door_struct list_test stack_test check clang_format clean rebuild