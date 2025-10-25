#include <stdio.h>
#include <stdlib.h>

void output(int **a, int x, int y);
int stat(int x, int y, int *max_rows, int *min_cols);
int **one_buff(int x, int y, int *max_rows, int *min_cols);
int **sec_array(int x, int y, int *max_rows, int *min_cols);
int **to_arr(int x, int y, int *max_rows, int *min_cols);
int input(int **a, int x, int y);
void r_max(int **matrix, int x, int y, int *max_array);
void c_min(int **matrix, int x, int y, int *min_array);
void output_res(int *min_array, int *max_array, int x, int y);

int main() {
    int n = 0, x = 0, y = 0;
    if (scanf("%d", &n) != 1 || (n < 1 || n > 4)) {
        printf("n/a");
        return 0;
    }
    if (scanf("%d %d", &x, &y) != 2 || x > 100 || y > 100) {
        printf("n/a");
        return 0;
    }
    int *max_rows = malloc(x * sizeof(int));
    int *min_cols = malloc(y * sizeof(int));
    switch (n) {
        case 1:
            stat(x, y, max_rows, min_cols);
            break;
        case 2:
            one_buff(x, y, max_rows, min_cols);
            break;
        case 3:
            sec_array(x, y, max_rows, min_cols);
            break;
        case 4:
            to_arr(x, y, max_rows, min_cols);
            break;
    }
    output_res(min_cols, max_rows, x, y);
    return 0;
}

int input(int **a, int x, int y) {
    int re_mal = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                re_mal = 1;
            }
        }
    }
    return re_mal;
}

int stat(int x, int y, int *max_rows, int *min_cols) {
    int *data[x];
    int arr[x][y];
    for (int i = 0; i < x; i++) {
        data[i] = arr[i];
    }

    if (input(data, x, y) != 0) {
        printf("n/a");
    } else {
        output(data, x, y);
        r_max(data, x, y, max_rows);
        c_min(data, x, y, min_cols);
    }
    return 0;
}

int **one_buff(int x, int y, int *max_rows, int *min_cols) {
    int **map = malloc(x * sizeof(int *) + x * y * sizeof(int));
    int *arr = (int *)(map + x);
    for (int i = 0; i < x; i++) {
        map[i] = arr + y * i;
    }

    if (input(map, x, y) != 0) {
        printf("n/a");
    } else {
        output(map, x, y);
        r_max(map, x, y, max_rows);
        c_min(map, x, y, min_cols);
    }

    free(map);
    return 0;
}

int **sec_array(int x, int y, int *max_rows, int *min_cols) {
    int **map = malloc(x * sizeof(int *));
    int *val = malloc(x * y * sizeof(int));

    for (int i = 0; i < x; i++) {
        map[i] = val + y * i;
    }

    if (input(map, x, y) != 0) {
        printf("n/a");
    } else {
        output(map, x, y);
        r_max(map, x, y, max_rows);
        c_min(map, x, y, min_cols);
    }

    free(val);
    free(map);
    return 0;
}

int **to_arr(int x, int y, int *max_rows, int *min_cols) {
    int **a = malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++) {
        a[i] = malloc(y * sizeof(int));
    }

    if (input(a, x, y) != 0) {
        printf("n/a");
    } else {
        output(a, x, y);
        r_max(a, x, y, max_rows);
        c_min(a, x, y, min_cols);
    }

    for (int i = 0; i < x; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}

void output(int **a, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", a[i][j]);
            if (j < y - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void r_max(int **matrix, int x, int y, int *max_array) {
    for (int i = 0; i < x; i++) {
        int max_r = matrix[i][0];
        for (int j = 0; j < y; j++) {
            if (matrix[i][j] > max_r) {
                max_r = matrix[i][j];
            }
        }
        max_array[i] = max_r;
    }
}

void c_min(int **matrix, int x, int y, int *min_array) {
    for (int j = 0; j < y; j++) {
        int min_c = matrix[0][j];
        for (int i = 1; i < x; i++) {
            if (matrix[i][j] < min_c) {
                min_c = matrix[i][j];
            }
        }
        min_array[j] = min_c;
    }
}

void output_res(int *min_array, int *max_array, int x, int y) {
    for (int i = 0; i < x; i++) {
        printf("%d", max_array[i]);
        if (i < x - 1) {
            printf(" ");
        }
    }
    if (y > 0) {
        printf("\n");
    }
    for (int j = 0; j < y; j++) {
        printf("%d", min_array[j]);
        if (j < y - 1) {
            printf(" ");
        }
    }
}