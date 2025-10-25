#include <stdio.h>
#include <math.h>

double m(double x);

int main(void){
    double x;
    if (scanf("%lf", &x) != 1){
        printf("n/a\n");
        return 1;
    }
    printf("%.1f\n", m(x));
    return 0;
}

double m(double x){
    return (0.007 * pow(x, 4) + ((22.8 * pow(x, 1.0/3.0) - 1000) * x + 3) / (x * x / 2) - x * pow((10 + x),(2.0/x)) - 1.01);
}