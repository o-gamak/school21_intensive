#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void sorting(int *a, int n);
int *transp(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);
int input_matrix_elements(int **matrix, int n, int m);

int main() {
    int **matrix;
    int n, m;
    int **result;
    int return_code = 0;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return_code = 1;
    } else {
        result = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            result[i] = malloc(m * sizeof(int));
        }

        sort_vertical(matrix, n, m, result);
        output(result, n, m);
        printf("\n");
        printf("\n");
        sort_horizontal(matrix, n, m, result);
        output(result, n, m);

        free_matrix(matrix, n);
        free_matrix(result, n);
    }

    return return_code;
}

void sorting(int *a, int n) {
    int i = 0;
    int j;
    int x;

    while (i < n - 1) {
        j = 0;
        while (j < n - 1 - i) {
            if (a[j] > a[j + 1]) {
                x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
            j++;
        }
        i++;
    }
}

int input(int ***matrix, int *n, int *m) {
    int re_mal = 0;

    if (scanf("%d %d", n, m) != 2 || *n == 0 || *m == 0) {
        re_mal = 1;
    } else {
        *matrix = malloc(*n * sizeof(int *));
        if (*matrix == NULL) {
            re_mal = 1;
        } else {
            re_mal = input_matrix_elements(*matrix, *n, *m);
        }
    }

    return re_mal;
}

int input_matrix_elements(int **matrix, int n, int m) {
    int re_mal = 0;
    int i = 0;
    int j;

    while (i < n && re_mal == 0) {
        matrix[i] = malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            re_mal = 1;
        } else {
            j = 0;
            while (j < m && re_mal == 0) {
                if (scanf("%d", &matrix[i][j]) != 1) {
                    re_mal = 1;
                }
                j++;
            }
        }
        i++;
    }

    if (re_mal == 1) {
        free_matrix(matrix, i);
    }

    return re_mal;
}

void output(int **matrix, int n, int m) {
    int i = 0;
    int j;

    while (i < n) {
        j = 0;
        while (j < m) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
            j++;
        }
        if (i < n - 1) {
            printf("\n");
        }
        i++;
    }
}

int *transp(int **matrix, int n, int m) {
    int *elements = malloc(n * m * sizeof(int));
    int k = 0;
    int i = 0;
    int j;

    while (i < n) {
        j = 0;
        while (j < m) {
            elements[k] = matrix[i][j];
            k++;
            j++;
        }
        i++;
    }
    sorting(elements, n * m);
    return elements;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *el = transp(matrix, n, m);
    int k_el = 0;
    int j = 0;
    int i;

    while (j < m) {
        if (j % 2 == 0) {
            i = 0;
            while (i < n) {
                result_matrix[i][j] = el[k_el];
                k_el++;
                i++;
            }
        } else {
            i = n - 1;
            while (i >= 0) {
                result_matrix[i][j] = el[k_el];
                k_el++;
                i--;
            }
        }
        j++;
    }
    free(el);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *el = transp(matrix, n, m);
    int k_el = 0;
    int i = 0;
    int j;

    while (i < n) {
        if (i % 2 == 0) {
            j = 0;
            while (j < m) {
                result_matrix[i][j] = el[k_el];
                k_el++;
                j++;
            }
        } else {
            j = m - 1;
            while (j >= 0) {
                result_matrix[i][j] = el[k_el];
                k_el++;
                j--;
            }
        }
        i++;
    }
    free(el);
}

void free_matrix(int **matrix, int n) {
    int i = 0;
    while (i < n) {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}