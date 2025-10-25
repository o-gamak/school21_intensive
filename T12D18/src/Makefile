CC = gcc
CFLAG = -Werror -Wall -Wextra -std=c11
BUILDIR = ../build
TARGET = $(BUILDIR)/Quest_1
TARGET3 = $(BUILDIR)/Quest_3
SOURSES1 = print_module.c main_module_entry_point.c
SOURSES3 = bst.c bst_create_test.c

all: print_module bst_create_test

print_module: $(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES1) -o $(TARGET)

bst_create_test: $(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES3) -o $(TARGET3)

$(BUILDIR):
	mkdir -p $(BUILDIR)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

clang_format:
	clang-format --assume-filename=.clang-format -i *.c *.h

leak:
	leaks -atExit -- $(TARGET)
	leaks -atExit -- $(TARGET3)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all