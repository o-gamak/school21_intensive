#include <stdio.h>

int sum(int a, int b);

int main()
{
    int a, b;
    if (scanf("%d %d", &a, &b) !=2 ) {
        printf("n/a\n");
        return 1;
    }
    printf("%d ", sum(a,b));
    printf("%d ", a - b);
    printf("%d ", a * b);
    if (b == 0){
        printf("n/a\n");
        return 1;
    } else {
        printf("%d\n", a / b);
    }
    return 0;
}

int sum(int a, int b){
    return a+b;
}