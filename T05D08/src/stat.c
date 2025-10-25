#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

        return 0;
    }
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max_v) {
            max_v = *p;
        }
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min_v) {
            min_v = *p;
        }
    }
    return min_v;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    double mean_v = sum / n;
    return mean_v;
}

double variance(int *a, int n) {
    int min_v = min(a, n);
    int max_v = max(a, n);
    double variance_v = ((max_v - min_v + 1) * (max_v - min_v + 1) - 1) / 12.0;
    return variance_v;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
