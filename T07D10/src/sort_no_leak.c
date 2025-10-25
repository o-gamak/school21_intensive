#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void sorting(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
    }
    int *arr = (int *)(malloc(n * sizeof(int)));
    if (input(arr, n) == 1) {
        printf("n/a");
        free(arr);
        return 1;
    } else {
        sorting(arr, n);
        output(arr, n);
        free(arr);
        arr = NULL;
    }
    return 0;
}

int input(int *a, int n) {
    int re = 0;
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) {
            re = 1;
        }
    }
    return re;
}

void sorting(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if ((p - a) == (n - 1)) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}
