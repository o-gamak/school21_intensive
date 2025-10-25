#include "data_io.h"

#include <stdio.h>

int input(double *data, int n) {
    int f = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            f = 0;
        }
    }
    return f;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", data[i]);
    }
}