#include <math.h>
#include <stdio.h>
void grafs(int zn, double y_max, double y_min);

double an(double x);
double ber(double x);
double gip(double x);

double an(double x) { return (1 / (1 + x * x)); }

double ber(double x) {
    double y = sqrt(1 + 4 * x * x) - x * x - 1;
    if (y < 0) return -1.0;
    return sqrt(y);
}

double gip(double x) {
    if (x == 0) {
        return -1;
    } else
        return 1 / (x * x);
}

void grafs(int zn, double y_max, double y_min) {
    double max_p = M_PI;
    double min_p = -M_PI;
    double step = (max_p - min_p) / 41;
    double y_pol;
    double steps_y = (y_max - y_min) / 21;
    double y_top = y_max;

    for (int j = 0; j <= 21; j++) {
        double top = y_top - j * steps_y;
        double nizz = y_top - (j + 1) * steps_y;
        for (int i = 0; i < 42; i++) {
            double x = min_p + i * step;

            if (zn == 1) {
                y_pol = an(x);
            }
            if (zn == 2) {
                y_pol = ber(x);
            }
            if (zn == 3) {
                y_pol = gip(x);
            }
            if (i == 21) {
                printf("|");
            }
            if ((nizz < y_pol) && (top > y_pol)) {
                printf("*");
            }
            if (j == 11) {
                printf("-");
            }
            if (j != 11 && !((nizz < y_pol) && (top > y_pol))) {
                printf(" ");
            }
        }
        printf("\n");
    }
    zn = 0;
}

int main(void) {
    double max_p = M_PI;
    double min_p = -M_PI;
    double step = (max_p - min_p) / 41;
    double max_a = -1e3, max_ber = -1e3, max_gip = -1e3;
    double min_a = 1e3, min_ber = 1e3, min_gip = 1e3;

    for (int i = 0; i < 42; i++) {
        double x = min_p + i * step;
        double y_a = an(x);
        double y_ber = ber(x);
        double y_gip = gip(x);

        if (y_a > max_a) max_a = y_a;
        if (y_ber > max_ber) max_ber = y_ber;
        if (y_gip < 150 && y_gip > max_gip) max_gip = y_gip;

        if (y_a < min_a) min_a = y_a;
        if (y_ber < min_ber) min_ber = y_ber;
        if (y_gip < min_gip) min_gip = y_gip;

        printf("%.7f  |  ", x);
        printf("%.7f  |  ", y_a);
        if (y_ber == -1.0) {
            printf("-  |  ");
        } else {
            printf("%.7f  |  ", y_ber);
        }
        if (y_gip == -1.0) {
            printf("- \n");
        } else {
            printf("%.7f\n", y_gip);
        }
    }
    grafs(1, max_a, min_a);
    printf("\n");
    grafs(2, max_ber, min_ber);
    printf("\n");
    grafs(3, max_gip, min_gip);
}