#include <stdio.h>

int fi(int a);

int fi(int a) {
    if (a <= 1) return a;
    return fi(a - 1) + fi(a - 2);
}

int main(void) {
    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a\n");
        return 1;
    };
    if (a < 0) {
        printf("n/a\n");
        return 1;
    }
    printf("%d\n", fi(a));
    return 0;
};