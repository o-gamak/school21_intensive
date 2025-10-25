CC = gcc
CFLAG = -Werror -Wall -Wextra -std=c11
BUILDIR = ../build
TARGET = $(BUILDIR)/Quest_1
TARGET2 = $(BUILDIR)/Quest_2
TARGET3 = $(BUILDIR)/Quest_3


SOURSES1 = state_sort.c
SOURSES2 = state_search.c
SOURSES3 = clear_state.c


all: state_sort state_search clear_state

all_c: clang_format check cipher logging_cipher

state_sort: $(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES1) -o $(TARGET)

state_search:$(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES2) -o $(TARGET2)

clear_state:$(BUILDIR)
	$(CC) $(CFLAG) $(SOURSES3) -o $(TARGET3)

$(BUILDIR):
	mkdir -p $(BUILDIR)
git:
	git add $(SOURSES1) $(SOURSES2) $(SOURSES3)
	git commit -m "exx"
	git push

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clang_format:
	clang-format --assume-filename=/.clang-format -i *.c

leak:
	leaks -atExit -- $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all