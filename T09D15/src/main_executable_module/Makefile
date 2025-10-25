CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra 
LDFLAGS = -lm
DATA_LIBS_DIR = ../data_libs
DATA_MODULE_DIR = ../data_module
DECISION_MODULE_DIR = ../yet_another_decision_module
SOURCES =  $(DATA_LIBS_DIR)/data_stat.c $(DATA_LIBS_DIR)/data_io.c\
$(DECISION_MODULE_DIR)/decision.c $(DATA_MODULE_DIR)/data_process.c main_executable_module.c
CLANG_PATH = ../.clang-format
BUILDDIR = ../../build

DATA_STAT_SRC = $(DATA_LIBS_DIR)/data_stat.c
DATA_STAT_O = $(BUILDDIR)/data_stat.o
DATA_STAT_LIB = $(BUILDDIR)/data_stat.a

DATA_PROC_O = $(BUILDDIR)/data_process.o
DATA_PROC_C = $(DATA_MODULE_DIR)/data_process.c
DATA_PROC_LIB = $(BUILDDIR)/libdata_process.so

TARGET = $(BUILDDIR)/Quest_3

all: quest3 build_with_static build_with_dynamic

quest3: check format
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)

data_stat.a: $(DATA_STAT_O)
	@mkdir -p $(BUILDDIR)
	ar rcs $(DATA_STAT_LIB) $(DATA_STAT_O)
	ranlib $(DATA_STAT_LIB)

$(DATA_STAT_O): $(DATA_STAT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

build_with_static: check format data_stat.a
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) main_executable_module.c \
	$(DATA_LIBS_DIR)/data_io.c \
	$(DECISION_MODULE_DIR)/decision.c \
	$(DATA_MODULE_DIR)/data_process.c \
	$(DATA_STAT_LIB) -o $(BUILDDIR)/Quest_5

$(DATA_PROC_O) : $(DATA_PROC_C) $(DATA_STAT_SRC)
	$(CC) $(CFLAGS) -fPIC -c $(DATA_PROC_C) -o $@

data_process.so: $(DATA_PROC_O) $(DATA_STAT_O)
	$(CC) -shared $(DATA_PROC_O) $(DATA_STAT_O) -o $(DATA_PROC_LIB)

build_with_dynamic: check format data_process.so
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) main_executable_module.c \
	$(DATA_LIBS_DIR)/data_io.c \
	$(DECISION_MODULE_DIR)/decision.c \
	$(DATA_STAT_SRC) -L$(BUILDDIR) -ldata_process \
	-Wl,-rpath,$(BUILDDIR) -o $(BUILDDIR)/Quest_6

check-format:
	clang-format --assume-filename=$(CLANG_PATH) -n $(SOURCES)

format:
	clang-format --assume-filename=$(CLANG_PATH) -i $(SOURCES)

clean:
	rm -rf $(BUILDDIR)

rebuild: clean all

run:
	./$(TARGET)

leaks:
	leaks --atExit -- ./$(TARGET) | grep -i "leaks:"