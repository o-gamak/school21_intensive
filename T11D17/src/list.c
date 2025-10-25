#include "list.h"

#include <stdio.h>

node *init(const struct door *door) {
    if (door == NULL) return NULL;
    node *new_node = (node *)malloc(sizeof(struct node));
    new_node->door = *door;
    new_node->next = NULL;
    return new_node;
}

node *add_door(node *elem, struct door *door) {
    if (elem == NULL || door == NULL) return NULL;
    node *new_node = init(door);
    new_node->next = NULL;
    new_node->door = *door;
    elem->next = new_node;
    return new_node;
}

node *find_door(int door_id, struct node *root) {
    node *c = root;
    while (c != NULL) {
        if (c->door.id == door_id) {
            return c;
        }
        c = c->next;
    }
    return NULL;
}

node *remove_door(struct node *elem, struct node *root) {
    if (elem == NULL || root == NULL) return NULL;

    if (elem == root) {
        node *new_root = root->next;
        free(root);
        return new_root;
    }

    node *current = root;
    while (current != NULL && current->next != elem) {
        current = current->next;
    }

    if (current != NULL) {
        current->next = elem->next;
        free(elem);
        return root;
    }

    return NULL;
}

void destroy(struct node *root) {
    while (root != NULL) {
        node *temp = root;
        root = root->next;
        free(temp);
    }
}