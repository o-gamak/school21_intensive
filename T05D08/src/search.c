#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    } else {
        double mo = variance(data, n);
        double me = mean(data, n);
        double sco = sqrt(mo);
        int flag = 0;
        for (int *p = data; p - data < n; p++) {
            if ((*p % 2 == 0) && (*p >= me) && (*p != 0) && (*p <= (me + 3 * sco))) {
                flag = *p;
                break;
            }
        }
        printf("%d", flag);
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

int max(int *a, int n) {
    int max_v = *a;
    {
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
