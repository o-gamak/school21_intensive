#include "bst.h"

struct t_btree *bstree_create_node(int item) {
    struct t_btree *new = malloc(sizeof(struct t_btree));
    if (new == NULL) {
        return NULL;
    }
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}