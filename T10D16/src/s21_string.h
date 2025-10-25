#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>

size_t s21_strlen(const char *str);
char *s21_strcpy(char *restrict dest, const char *restrict src);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcat(char *restrict dest, const char *restrict src);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *str1, const char *str2);
size_t s21_strnlen(const char *str, size_t maxlen);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strtok(char *str, const char *delim);

#endif
