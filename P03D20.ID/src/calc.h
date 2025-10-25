#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct new_el {
    double data;
    char znak[2];
    int priority;
    struct elem *next;
} elem;


#endif