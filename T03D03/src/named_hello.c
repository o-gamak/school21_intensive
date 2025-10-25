#include <stdio.h>

int main(void){
    int name;
    if (scanf("%d", & name) != 1){
        printf("Ошибка ввода\n");
        return 1;
    }
    printf("Hello, %d!\n", name);
    return 0;
}