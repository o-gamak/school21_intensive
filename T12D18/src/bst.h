#ifndef BST_H
#define BST_H
#include <stdlib.h>

struct t_btree {
    int data;
    struct t_btree *left;
    struct t_btree *right;
};

struct t_btree *bstree_create_node(int item);

#endif