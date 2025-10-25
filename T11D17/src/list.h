#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

#include "door_struct.h"
typedef struct node {
    struct door door;
    struct node* next;

} node;
node* init(const struct door* door);
node* find_door(int door_id, struct node* root);
void destroy(struct node* root);
node* add_door(node* elem, struct door* door);
node* remove_door(struct node* elem, struct node* root);
#endif