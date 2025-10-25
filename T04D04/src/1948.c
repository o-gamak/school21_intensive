#include <stdio.h>

int calc(int a);
int prime(int a);
int del(int a, int b);

int calc(int a) {
    int n = 0;
    for (int i = a; i >= 2; i--) {
        if (del(a, i) == 1) {
            if (prime(i) == 1) {
                int n = i;
                return n;
            };
        };
    };
    return n;
}

int del(int a, int b) {
    if (b == 0) return 0;
    while (a >= b) {
        a = a - b;
    };
    return (a == 0);
};

int prime(int a) {
    if (a <= 1) return 0;
    if (a == 2) return 1;
    if (del(a, 2) == 1) return 0;
    for (int i = 3; i * i <= a; i += 2) {
        if (del(a, i) == 1) {
            return 0;
        };
    };
    return 1;
};

int main(void) {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a\n");
        return 1;
    };
    if (a < 0) {
        a = -a;
    }
    if (calc(a) == 0) {
        printf("n/a\n");
    } else {
        printf("%d\n", calc(a));
    }
    return 0;
};