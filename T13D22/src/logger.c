#include "logger.h"

#include <time.h>

#include "log_levels.h"

FILE *log_init(char *filename) {
    FILE *log_file = fopen(filename, "a");
    if (log_file == NULL) {
        return NULL;
    }
    return log_file;
}

char *get_level_string(log_level level) {
    char *text;
    switch (level) {
        case DEBUG:
            text = "DEBUG";
            break;
        case INFO:
            text = "INFO";
            break;
        case WARNING:
            text = "WARNING";
            break;
        case ERROR:
            text = "ERROR";
            break;
        default:
            text = "UNKNOWN";
    }
    return text;
}

int logcat(FILE *log_file, char *message, log_level level) {
    if (log_file == NULL) {
        return 0;
    }
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);
    fprintf(log_file, "[%s] %s: %s\n", get_level_string(level), time_str, message);
    fflush(log_file);
    return 1;
}

int log_close(FILE *log_file) {
    if (log_file != NULL) {
        fclose(log_file);
        return 1;
    }
    return 0;
}