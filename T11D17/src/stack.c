#include "stack.h"

#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1

stack* init(int len) {
    if (len <= 0) return NULL;
    stack* st = malloc(sizeof(stack));
    if (!st) return NULL;
    st->data = malloc(sizeof(int) * len);
    if (!st->data) {
        free(st);
        return NULL;
    }

    st->top = -1;
    st->len = len;
    return st;
}

void destroy(stack* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

int push(stack* stack, int val) {
    if (stack == NULL) return FAIL;
    if (stack->top + 1 >= stack->len) {
        int new_size = stack->len * 2;
        int* ndata = realloc(stack->data, new_size * (sizeof(int)));
        if (ndata == NULL) return FAIL;
        stack->data = ndata;
        stack->len = new_size;
    }
    stack->top++;
    stack->data[stack->top] = val;
    return SUCCESS;
}

int pop(stack* stack, int* val) {
    if (val == NULL || stack == NULL || stack->top < 0) return FAIL;
    *val = stack->data[stack->top];
    stack->top--;
    return SUCCESS;
}
