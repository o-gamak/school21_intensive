#ifndef LOGGER
#define LOGGER
#include <stdio.h>

#include "log_levels.h"

FILE *log_init(char *filename);
int logcat(FILE *log_file, char *message, log_level level);
int log_close(FILE *log_file);
char *get_level_string(log_level level);

#endif