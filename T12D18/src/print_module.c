#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char *message) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char *s = Log_prefix;
    while (*s != '\0') {
        print(*s);
        s++;
    }
    print(' ');
    char my_time[9];
    strftime(my_time, sizeof(my_time), "%H:%M:%S", current_time);
    s = my_time;
    while (*s != '\0') {
        print(*s);
        s++;
    }
    print(' ');
    s = message;
    while (*s != '\0') {
        print(*s);
        s++;
    }
}