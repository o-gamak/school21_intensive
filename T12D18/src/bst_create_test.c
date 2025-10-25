#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_create_node(int value) {
    struct t_btree *node = bstree_create_node(value);

    if (node) {
        printf("Тест создания узла с значением %d:\n", value);
        printf("  Значение узла: %d\n", node->data);
        printf("  Левый дочерний узел: %p\n", node->left);
        printf("  Правый дочерний узел: %p\n", node->right);
        if (node->data == value && node->left == NULL && node->right == NULL) {
            printf("  Тест пройден!\n");
        } else {
            printf("  Тест не пройден!\n");
        }

        free(node);
    } else {
        printf("Ошибка создания узла с значением %d\n", value);
    }
}

int main() {
    test_create_node(4);
    test_create_node(10);
    test_create_node(0);
    test_create_node(10);

    return 0;
}
