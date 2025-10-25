#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void check_len(const char *str, size_t r, size_t c) {
    if (str == NULL) {
        printf("NULL %zu", r);
    } else {
        for (size_t i = 0; str[i] != '\0'; i++) {
            printf("%c", str[i]);
        }
        printf(" %zu", r);
    }
    if (r == c) {
        printf(" SUCCESS\n");
    } else {
        printf(" FAIL\n");
    }
}

void check_cmp(const char *str1, const char *str2, int r, int c) {
    if (str1 != NULL) {
        for (size_t i = 0; str1[i] != '\0'; i++) {
            printf("%c", str1[i]);
        }
    }
    printf(" ");
    if (str2 != NULL) {
        for (size_t i = 0; str2[i] != '\0'; i++) {
            printf("%c", str2[i]);
        }
    }
    printf(" %d", r);
    if (r == c) {
        printf(" SUCCESS\n");
    } else {
        printf(" FAIL\n");
    }
}

void check_cpy(const char *str1, const char *str2) {
    int r = 1;
    if (str1 == NULL || str2 == NULL) {
        r = 0;
    } else {
        for (size_t i = 0; str1[i] != '\0' && r != 0; i++) {
            if (str1[i] != str2[i]) {
                r = 0;
            }
        }
    }
    if (r == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void check_cpy_print(const char *src, const char *dst) {
    if (src != NULL) {
        for (size_t i = 0; src[i] != '\0'; i++) {
            printf("%c", src[i]);
        }
    }
    printf(" ");
    if (dst != NULL) {
        for (size_t i = 0; dst[i] != '\0'; i++) {
            printf("%c", dst[i]);
        }
    }
    printf(" ");
    check_cpy(src, dst);
}

void s21_strchr_test() {
    char *str1 = "Hello World";
    char ch1 = 'W';
    char *res1 = s21_strchr(str1, ch1);
    for (size_t i = 0; str1[i] != '\0'; i++) {
        printf("%c", str1[i]);
    }
    printf(" %c ", ch1);
    if (res1 != NULL && *res1 == 'W') {
        printf("%p SUCCESS\n", (void *)res1);
    } else {
        printf("%p FAIL\n", (void *)res1);
    }

    char *str2 = "Test";
    char ch2 = 'x';
    char *res2 = s21_strchr(str2, ch2);
    for (size_t i = 0; str2[i] != '\0'; i++) {
        printf("%c", str2[i]);
    }
    printf(" %c ", ch2);
    if (res2 == NULL) {
        printf("NULL SUCCESS\n");
    } else {
        printf("%p FAIL\n", (void *)res2);
    }

    char *str3 = "";
    char ch3 = 'a';
    char *res3 = s21_strchr(str3, ch3);
    printf(" %c ", ch3);
    if (res3 == NULL) {
        printf("NULL SUCCESS\n");
    } else {
        printf("%p FAIL\n", (void *)res3);
    }
}

void s21_strstr_test() {
    char *str1 = "Hello World";
    char *str2 = "World";
    char *res1 = s21_strstr(str1, str2);
    for (size_t i = 0; str1[i] != '\0'; i++) {
        printf("%c", str1[i]);
    }
    printf(" ");
    for (size_t i = 0; str2[i] != '\0'; i++) {
        printf("%c", str2[i]);
    }
    printf(" ");
    if (res1 != NULL && s21_strcmp(res1, "World") == 0) {
        for (size_t i = 0; res1[i] != '\0'; i++) {
            printf("%c", res1[i]);
        }
        printf(" SUCCESS\n");
    } else {
        printf("NULL FAIL\n");
    }

    char *str3 = "Hello World";
    char *str4 = "test";
    char *res2 = s21_strstr(str3, str4);
    for (size_t i = 0; str3[i] != '\0'; i++) {
        printf("%c", str3[i]);
    }
    printf(" ");
    for (size_t i = 0; str4[i] != '\0'; i++) {
        printf("%c", str4[i]);
    }
    printf(" ");
    if (res2 == NULL) {
        printf("NULL SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char *str5 = "";
    char *str6 = "abc";
    char *res3 = s21_strstr(str5, str6);
    printf(" ");
    for (size_t i = 0; str6[i] != '\0'; i++) {
        printf("%c", str6[i]);
    }
    printf(" ");
    if (res3 == NULL) {
        printf("NULL SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char str1_1[20] = "Hello ";
    char str2_1[] = "Bro";
    char *res_1 = s21_strcat(str1_1, str2_1);
    printf("Hello  Bro ");
    if (res_1 && s21_strcmp(res_1, "Hello Bro") == 0) {
        for (size_t i = 0; res_1[i] != '\0'; i++) {
            printf("%c", res_1[i]);
        }
        printf(" SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char str1_2[20] = "Hello";
    char str2_2[] = "";
    char *res_2 = s21_strcat(str1_2, str2_2);
    printf("Hello  ");
    if (res_2 && s21_strcmp(res_2, "Hello") == 0) {
        for (size_t i = 0; res_2[i] != '\0'; i++) {
            printf("%c", res_2[i]);
        }
        printf(" SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char str1_3[20] = "";
    char str2_3[] = "Test";
    char *res_3 = s21_strcat(str1_3, str2_3);
    printf(" Test ");
    if (res_3 && s21_strcmp(res_3, "Test") == 0) {
        for (size_t i = 0; res_3[i] != '\0'; i++) {
            printf("%c", res_3[i]);
        }
        printf(" SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strlen_test() {
    char *str1 = "";
    char *str2 = "ds";
    char *str3 = NULL;
    size_t res1 = s21_strlen(str1);
    size_t res2 = s21_strlen(str2);
    size_t res3 = s21_strlen(str3);
    check_len(str1, res1, 0);
    check_len(str2, res2, 2);
    check_len(str3, res3, 0);
}

void s21_strcmp_test() {
    char *str1 = "Hello Bro";
    char *str2 = "Hello Bro";
    char *str3 = "";
    char *str4 = "";
    char *str5 = "Hello";
    int res1 = s21_strcmp(str1, str2);
    int res2 = s21_strcmp(str3, str4);
    int res3 = s21_strcmp(str1, str5);
    check_cmp(str1, str2, res1, 0);
    check_cmp(str3, str4, res2, 0);
    check_cmp(str1, str5, res3, 'B');
}

void s21_strcpy_test() {
    char str1_1[20] = "";
    char str2_1[] = "Hello Bro";
    s21_strcpy(str1_1, str2_1);
    check_cpy_print(str2_1, str1_1);

    char str1_2[20] = "";
    char str2_2[] = "";
    s21_strcpy(str1_2, str2_2);
    check_cpy_print(str2_2, str1_2);

    char str1_3[50] = "";
    char str2_3[] = "longLONGlongavf";
    s21_strcpy(str1_3, str2_3);
    check_cpy_print(str2_3, str1_3);
}

int main() {
#ifdef SLEN
    s21_strlen_test();
#endif
#ifdef SCMP
    s21_strcmp_test();
#endif
#ifdef SCPY
    s21_strcpy_test();
#endif
#ifdef SCAT
    s21_strcat_test();
#endif
#ifdef SCHR
    s21_strchr_test();
#endif
#ifdef SSTR
    s21_strstr_test();
#endif
    return 0;
}