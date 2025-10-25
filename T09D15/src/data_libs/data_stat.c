#include "data_stat.h"

#include <math.h>

double max(const double *data, int n) {
    double maxi = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > maxi) {
            maxi = data[i];
        }
    }
    return maxi;
}

double min(const double *data, int n) {
    double mini = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < mini) {
            mini = data[i];
        }
    }
    return mini;
}

double mean(const double *data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / (double)n;
}

double variance(const double *data, int n) {
    double val = 0;
    double mu = mean(data, n);
    for (int i = 0; i < n; i++) {
        val += pow(data[i] - mu, 2) / (double)n;
    }
    return val;
}