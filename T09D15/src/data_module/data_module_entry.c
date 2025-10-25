#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "./data_process.h"

int main(void) {
    double *data;
    int n;
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("ERROR");
        return 0;
    }
    data = malloc(n * sizeof(double));
    if (!input(data, n)) {
        printf("ERROR");
        return 0;
    }
    normalization(data, n);
    output(data, n);
    free(data);
    return 0;
}
