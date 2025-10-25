#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EPS 1e-12

double** allocate_matrix(int n);
void free_matrix(double** matrix, int n);
double** input_matrix(int* n, int* m);
void change(double* a, double* b);
int det(double** matrix, int n, double* de);

int main() {
    int n, m;
    double de;
    double** matrix;

    matrix = input_matrix(&n, &m);
    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }

    if (det(matrix, n, &de)) {
        printf("%.6lf", de);
    } else {
        printf("n/a");
    }
    free_matrix(matrix, n);
    return 0;
}

double** allocate_matrix(int n) {
    double** matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(double));
    }
    return matrix;
}

void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double** input_matrix(int* n, int* m) {
    if (scanf("%d %d", n, m) != 2 || *n != *m || *n <= 0) {
        return NULL;
    }
    double** matrix = allocate_matrix(*n);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                free_matrix(matrix, *n);
                return NULL;
            }
        }
    }
    return matrix;
}

void change(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int det(double** matrix, int n, double* de) {
    *de = 1.0;
    int sign = 1;
    double** temp = allocate_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(temp[k][i]) > fabs(temp[max_row][i])) max_row = k;
        }
        if (fabs(temp[max_row][i]) < EPS) {
            *de = 0.0;
            free_matrix(temp, n);
            return 1;
        }

        if (max_row != i) {
            for (int j = 0; j < n; j++) {
                change(&temp[i][j], &temp[max_row][j]);
            }
            sign = -sign;
        }
        for (int k = i + 1; k < n; k++) {
            double f = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++) {
                temp[k][j] -= f * temp[i][j];
            }
        }
        *de *= temp[i][i];
    }

    *de *= sign;
    free_matrix(temp, n);
    return 1;
}