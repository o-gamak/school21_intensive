#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void check_result(int result, int expected) {
    if (result == expected) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void test1() {
    printf("Тест 1: Базовый функционал\n");
    stack* stack1 = init(2);
    printf("Создание стека размером 2: ");
    check_result(stack1 != NULL, 1);
    int value1;
    printf("Push 10: ");
    check_result(push(stack1, 10), 1);
    printf("Push 20: ");
    check_result(push(stack1, 20), 1);
    printf("Pop (ожидается 20): ");
    pop(stack1, &value1);
    check_result(value1, 20);
    printf("Pop (ожидается 10): ");
    pop(stack1, &value1);
    check_result(value1, 10);

    destroy(stack1);
}

void test2() {
    printf("\nТест 2: Расширение стека\n");
    stack* stack2 = init(1);
    printf("Создание стека размером 1: ");
    check_result(stack2 != NULL, 1);
    int value2;
    printf("Push 1: ");
    check_result(push(stack2, 1), 1);
    printf("Push 2: ");
    check_result(push(stack2, 2), 1);
    printf("Push 3: ");
    check_result(push(stack2, 3), 1);
    printf("Pop (ожидается 3): ");
    pop(stack2, &value2);
    check_result(value2, 3);
    printf("Pop (ожидается 2): ");
    pop(stack2, &value2);
    check_result(value2, 2);
    printf("Pop (ожидается 1): ");
    pop(stack2, &value2);
    check_result(value2, 1);
    destroy(stack2);
}
void test3() {
    stack* stack3 = NULL;
    int value3;
    printf("Push в NULL-стек: ");
    check_result(push(stack3, 5), 0);
    printf("Pop из NULL-стека: ");
    check_result(pop(stack3, &value3), 0);
    stack* empty_stack = init(1);
    printf("Pop из пустого стека: ");
    check_result(pop(empty_stack, &value3), 0);

    destroy(empty_stack);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
