CC = gcc
CFLAG = -Werror -Wall -Wextra -std=c11
BUILDIR = ../build
TARGET = $(BUILDIR)/cipher

SOURSES1 = cipher.c logger.c

all: logging_cipher

all_c: clang_format check cipher logging_cipher

cipher: $(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES1) -o $(TARGET)

logging_cipher: $(BUILDIR)
	$(CC) $(CFLAG) -DBUG $(SOURSES1) -o $(TARGET)

$(BUILDIR):
	mkdir -p $(BUILDIR)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

clang_format:
	clang-format --assume-filename=/.clang-format -i *.c *.h

leak:
	leaks -atExit -- $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all