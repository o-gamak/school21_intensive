#include <math.h>
#include <stdio.h>

double an(double x);
double ber(double x);
double gip(double x);

double an(double x) { return (1 / (1 + x * x)); }

double ber(double x) {
  double y = sqrt(1 + 4 * x * x) - x * x - 1;
  if (y < 0)
    return -1.0;
  return sqrt(y);
};

double gip(double x) {
  if (x == 0) {
    return -1;
  } else
    return 1 / (x * x);
};

int main(void) {
  double max_p = M_PI;
  double min_p = -M_PI;
  double step = (max_p - min_p) / 41;
  for (int i = 0; i < 42; i++) {
    double x = min_p + i * step;
    printf("%.7f  |  ", x);
    printf("%.7f  |  ", an(x));
    if (ber(x) == -1.0) {
      printf("-  |  ");
    } else {
      printf("%.7f  |  ", ber(x));
    };
    if (gip(x) == -1.0) {
      printf("- \n");
    } else {
      printf("%.7f\n", gip(x));
    };
  }
};