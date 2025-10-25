#include "calc.h"

elem *new_element(char *str) {
    elem *start = NULL;
    if (str != NULL) {
        elem *now_element = NULL;
        char *final = str + strlen(str);
        for (char *p = str ; p <= final; p++) {
            if (*p != ' ' && *p != '\n' && *p != '\0') {
                elem *tmp = create_node();
                if (tmp != NULL) {
                    if (p == str) {
                        start = tmp;
                    }
                    if (num_char(*p)) {
                        tmp->data = num_from_string(*p);
                    } else if (znak_char(*p)) {
                        if ();
                    }
                }
            }
        }
    }
}


elem *create_node() {
    elem *new = malloc(sizeof(elem));
    if (new != NULL) {
        new->znak[0] = '0';
        new->znak[1] = '0';
        new->data = -1;
        new->priority = 0;
        new->next = NULL;
    }
    return new;
}

int num_char(char *n) {
    int res = NULL;
    if (((int)(n) >= 48) && ((int)(n) <= 57) || (n == '.')) {
        res = n;
    }
    return res;
}

int num_char(char *n) 