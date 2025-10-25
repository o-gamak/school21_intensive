// list_test.c
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void test_result(const char *test_name, int result) {
    printf("%s: %s\n", test_name, result ? "SUCCESS" : "FAIL");
}

void test_add_door() {
    struct door door1 = {1, 0};
    node *root = init(&door1);
    node *result = add_door(root, &door1);
    test_result("Test add_door 1 (first element)", result != NULL && result->door.id == 1);
    destroy(root);

    struct door door2 = {2, 1};
    root = init(&door1);
    result = add_door(root, &door2);
    test_result("Test add_door 2 (second element)",
                result != NULL && result->door.id == 2 && root->next != NULL);
    destroy(root);

    result = add_door(NULL, &door1);
    test_result("Test add_door 3 (NULL parameters)", result == NULL);
}

void test_remove_door() {
    node *root;
    struct door door1 = {1, 0};
    root = init(&door1);
    node *new_root = remove_door(root, root);
    test_result("Test remove_door 1 (first element)", new_root == NULL);
    struct door door2 = {2, 1};
    root = init(&door1);
    add_door(root, &door2);
    node *middle = find_door(2, root);
    new_root = remove_door(middle, root);
    test_result("Test remove_door 2 (middle element)", find_door(2, new_root) == NULL);
    destroy(new_root);
    new_root = remove_door(NULL, root);
    test_result("Test remove_door 3 (NULL parameters)", new_root == NULL);
}

int main() {
    test_add_door();
    test_remove_door();

    return 0;
}
