#ifndef STACK_H
#define STACK_H
#include "door_struct.h"
typedef struct stack {
    int* data;
    int top;
    int len;
} stack;

stack* init(int len);
int push(stack* stack, int val);
int pop(stack* stack, int* val);
void destroy(stack* stack);

#endif
