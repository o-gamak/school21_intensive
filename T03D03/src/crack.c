#include <stdio.h>

int circ(double x, double y);

int main(void){
    double x, y;
    if (scanf("%lf %lf", &x, &y) !=2 ) {
        printf("n/a\n");
        return 1;
    } else{
        if (circ(x,y) != 0){
            printf("GOTCHA\n");
        } else{
            printf("MISS\n");
        }
    }
}


int circ(double x, double y){
    if (x * x + y * y < 25){
        return 1;
    } else {
        return 0;
    }
}