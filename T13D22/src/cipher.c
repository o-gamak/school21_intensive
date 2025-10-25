#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "log_levels.h"
#include "logger.h"

int input_men();
int read_file(char *s);
int write_file(char *s);
int shifr();

int main() {
    FILE *log_file = NULL;
#ifdef BUG
    log_file = log_init("log_txt");
#endif
    char file_name[1000];
    int is_exit = 0;
    while (!is_exit) {
        int command;
        command = input_men();

        switch (command) {
            case 1:
                scanf("%999s", file_name);
                if (!read_file(file_name)) {
                    logcat(log_file, "n/a", WARNING);
                    printf("n/a\n");
                }
                logcat(log_file, "read txt file", INFO);
                break;
            case 2:
                if (file_name[0] != '\0') {
                    if (!write_file(file_name)) {
                        logcat(log_file, "n/a", WARNING);
                        printf("n/a\n");
                    }
                } else {
                    logcat(log_file, "n/a", WARNING);
                    printf("n/a\n");
                }
                logcat(log_file, "n/a", WARNING);
                break;
            case 3:
                int res = shifr();
                if (!res) {
                    logcat(log_file, "n/a", WARNING);
                    printf("n/a\n");
                }
                logcat(log_file, "Cesar complite", INFO);
                break;
            case -1:
                is_exit = 1;
                logcat(log_file, "closed file", INFO);
                break;
            case -2:
                printf("n/a\n");
                logcat(log_file, "n/a", WARNING);

                break;
        }
    }
#ifdef BUG
    log_close(log_file);
#endif
    return 0;
}

int input_men() {
    int key = 1;
    if (scanf("%d", &key) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        key = -2;
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    if ((key != 1) && (key != -1) && (key != 2) && (key != 3)) {
        key = -2;
    }
    return key;
}

int read_file(char *s) {
    int flag = 1;
    FILE *file;
    file = fopen(s, "r");
    if (file == NULL) {
        flag = 0;
    } else {
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0) {
            flag = 0;
            fclose(file);
        } else {
            fseek(file, 0, SEEK_SET);
            char ch;
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);
        }
    }

    return flag;
}

int write_file(char *s) {
    int flag = 1;
    FILE *file;
    file = fopen(s, "r");
    if (file == NULL) {
        flag = 0;
    } else {
        fclose(file);
        file = fopen(s, "a+");
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0) {
            flag = 0;
            fclose(file);
        } else {
            fseek(file, 0, SEEK_SET);
            int fl = 1;
            char ch;
            while (fl) {
                ch = fgetc(stdin);
                if ((ch == '\n') || (ch == '\0')) {
                    fl = 0;
                } else {
                    fputc(ch, file);
                }
            }
            fseek(file, 0, SEEK_SET);
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);
        }
    }
    return flag;
}

int shifr() {
    int shift;
    int flag = 1;
    if (scanf("%d", &shift) != 1) {
        flag = 0;
    } else {
        char direct[100];
        scanf("%99s", direct);
        DIR *d = opendir(direct);
        if (d == NULL) {
            flag = 0;
        } else {
            struct dirent *e;
            while ((e = readdir(d))) {
                if (!(strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)) {
                    char path[2000];
                    sprintf(path, "%s/%s", direct, e->d_name);

                    if (strstr(e->d_name, ".c")) {
                        FILE *f = fopen(path, "r+b");
                        if (f != NULL) {
                            int ch;
                            while ((ch = fgetc(f)) != EOF) {
                                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                                    fseek(f, -1, SEEK_CUR);
                                    char shifted = ch + shift;
                                    if (ch >= 'A' && ch <= 'Z') {
                                        shifted = 'A' + (shifted - 'A') % 26;
                                        if (shifted < 'A') shifted += 26;
                                    } else if (ch >= 'a' && ch <= 'z') {
                                        shifted = 'a' + (shifted - 'a') % 26;
                                        if (shifted < 'a') shifted += 26;
                                    }
                                    fputc(shifted, f);
                                    fseek(f, 0, SEEK_CUR);
                                }
                            }
                            fclose(f);
                        } else {
                            flag = 0;
                        }
                    } else if (strstr(e->d_name, ".h")) {
                        FILE *f = fopen(path, "w");
                        if (f != NULL) {
                            fclose(f);
                        } else {
                            flag = 0;
                        }
                    }
                }
            }
        }
        closedir(d);
    }
    return flag;
}