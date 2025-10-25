#include <stdio.h>
#define MAX_L 10

int input(int *buffer, int *length, int *sdvig);
void calc(int *buffer, int length, int sdvig);
void output(int *buffer, int length);
int main() {
    int n, sdvig, data[MAX_L];
    int in = input(data, &n, &sdvig);
    if (in == 1) {
        printf("n/a\n");
        return 1;
    } else if (in == 2) {
        for (int i = 0; i < n; i++) {
            printf("%d", data[i]);
        }
        return 0;
    }
    calc(data, n, sdvig);
    output(data, n);
    return 0;
}

int input(int *buffer, int *length, int *sdvig) {
    char c;
    int res = 0;
    if ((scanf("%d%c", length, &c) != 2) || *length < 1 || *length > MAX_L || (c != '\n')) {
        res = 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &c) != 2 || (c != '\n' && c != ' ')) {
            res = 1;
        }
    }
    if ((scanf("%d%c", sdvig, &c) != 2) || *sdvig < 0 || (c != '\n')) {
        res = 1;
    }
    if (*sdvig % *length == 0) {
        res = 2;
    }
    *sdvig = *sdvig % *length;
    return res;
}

void calc(int *buffer, int length, int sdvig) {
    int temp[MAX_L];
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i + sdvig) % length];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}

void output(int *buffer, int length) {
    for (int *p = buffer; p < buffer + length; p++) {
        if (p == (buffer + length - 1)) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        };
    }
}
