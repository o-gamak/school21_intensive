#include "s21_string.h"

#include <stdlib.h>

size_t s21_strlen(const char *str) {
    size_t len = 0;
    char c;
    if (str == NULL) {
        len = (size_t)-1;
    }
    while (str != NULL && (c = *str++) != '\0') {
        len++;
        
    }
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    int result = 0;
    if (str1 == NULL || str2 == NULL) {
        result = -1;
    }
    while (result == 0 && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (result == 0) {
        result = (*str1 - *str2 != 0);
    }
    return result;
}

char *s21_strcpy(char *restrict dest, const char *restrict src) {
    char *ptr = dest;
    while (dest != NULL && src != NULL && (*ptr++ = *src++) != '\0');
    return dest;
}

char *s21_strcat(char *restrict dest, const char *restrict src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char *ptr = dest + s21_strlen(dest);
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

char *s21_strchr(const char *str, int c) {
    const char *result = NULL;
    const char *p = str;
    while (str != NULL && (char)*p != '\0' && result == NULL) {
        if (*p++ == (char)c) {
            result = p;
        }
    }
    return (char *)result;
}

char *s21_strstr(const char *str1, const char *str2) {
    char *result = NULL;
    for (char *p = (char *)str1; str1 != NULL && str2 != NULL && *p && result == NULL; p++) {
        char *h = p;
        const char *n = str2;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (!*n) {
            result = p;
        }
    }
    return result;
}

char *s21_strtok(char *str, const char *delim) {
    static char *prev = NULL;
    char *result = NULL;
    if (str != NULL) {
        prev = str;
    }
    if (prev != NULL && *prev != '\0') {
        while (*prev != '\0' && s21_strchr(delim, *prev) != NULL) {
            prev++;
        }
        if (*prev != '\0') {
            result = prev;

            while (*prev != '\0' && s21_strchr(delim, *prev) == NULL) {
                prev++;
            }
            if (*prev != '\0') {
                *prev = '\0';
                prev++;
            }
        }
    }
    return result;
}
