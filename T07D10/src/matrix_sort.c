#include <stdio.h>
#include <stdlib.h>

void output(int **a, int x, int y);
int stat(int x, int y);
int **one_buff(int x, int y);
int **sec_array(int x, int y);
int **to_arr(int x, int y);
int input(int **a, int x, int y);
void sorted(int **mat, int x, int y);

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

    switch (n) {
        case 1:
            stat(x, y);
            break;
        case 2:
            one_buff(x, y);
            break;
        case 3:
            sec_array(x, y);
            break;
        case 4:
            to_arr(x, y);
            break;
    }
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

int stat(int x, int y) {
    int *data[x];
    int arr[x][y];
    for (int i = 0; i < x; i++) {
        data[i] = arr[i];
    }

    if (input(data, x, y) != 0) {
        printf("n/a");
    } else {
        output(data, x, y);
    }
    return 0;
}

int **one_buff(int x, int y) {
    int **map = malloc(x * sizeof(int *) + x * y * sizeof(int));
    int *arr = (int *)(map + x);
    for (int i = 0; i < x; i++) {
        map[i] = arr + y * i;
    }

    if (input(map, x, y) != 0) {
        printf("n/a");
    } else {
        output(map, x, y);
    }

    free(map);
    return 0;
}

int **sec_array(int x, int y) {
    int **map = malloc(x * sizeof(int *));
    int *val = malloc(x * y * sizeof(int));

    for (int i = 0; i < x; i++) {
        map[i] = val + y * i;
    }

    if (input(map, x, y) != 0) {
        printf("n/a");
    } else {
        output(map, x, y);
    }

    free(val);
    free(map);
    return 0;
}

int **to_arr(int x, int y) {
    int **a = malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++) {
        a[i] = malloc(y * sizeof(int));
    }

    if (input(a, x, y) != 0) {
        printf("n/a");
    } else {
        output(a, x, y);
    }

    for (int i = 0; i < x; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}

void output(int **a, int x, int y) {
    sorted(a, x, y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", a[i][j]);
            if (j < y - 1) {
                printf(" ");
            }
        }
        if (i < x - 1) {
            printf("\n");
        }
    }
}

void sorted(int **mat, int x, int y) {
    int sum1, sum2;
    int *buf;
    for (int i = 0; i < x - 1; i++) {
        for (int n = 0; n < x - i - 1; n++) {
            sum1 = 0;
            sum2 = 0;
            for (int m = 0; m < y; m++) {
                sum1 += mat[n][m];
                sum2 += mat[n + 1][m];
                // printf("s1 - %d s2 - %d", sum1, sum2);
            }
            if (sum1 > sum2) {
                buf = mat[n + 1];
                mat[n + 1] = mat[n];
                mat[n] = buf;
            }
        }
    }
}