#include <stdio.h>
#define MAX_L 10

int input(int *a);
void sorting(int *a);
void output(int *a);

int main() {
    int data[MAX_L];
    if (input(data) == 1) {
        printf("n/a");
        return 1;
    } else {
        sorting(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    int re = 0;
    for (int *p = a; p - a < MAX_L; p++) {
        if (scanf("%d", p) != 1) {
            re = 1;
        }
    }
    return re;
}

void sorting(int *a) {
    for (int i = 0; i < MAX_L - 1; i++) {
        for (int j = 0; j < MAX_L - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < MAX_L; p++) {
        if (p - a == MAX_L - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}
