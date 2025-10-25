#include <stdio.h>

#define LEN 100
int input(int *buff1, int *len1, int *buff2, int *len2);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int check(int *buff1, int len1, int *buff2, int len2);
void output(int *result, int sum_len, int f);
void re(int *arr, int len);

int main() {
    int len1 = 0, len2 = 0;
    int buff1[LEN], buff2[LEN];
    int sum_result[LEN + 1], sum_len = 0;
    int sub_result[LEN], sub_len = 0;

    if (input(buff1, &len1, buff2, &len2) == -1) {
        printf("n/a");
        return 1;
    }
    re(buff1, len1);
    re(buff2, len2);
    if (check(buff1, len1, buff2, len2) == -1) {
        printf("n/a");
        return 1;
    }
    sum(buff1, len1, buff2, len2, sum_result, &sum_len);
    sub(buff1, len1, buff2, len2, sub_result, &sub_len);
    re(sum_result, sum_len);
    re(sub_result, sub_len);
    output(sum_result, sum_len, 0);
    output(sub_result, sub_len, 1);
    return 0;
}

void re(int *arr, int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

int input(int *buff1, int *len1, int *buff2, int *len2) {
    char c;
    int res = 0;
    int flag = 0;
    while (flag == 0 && *len1 < LEN) {
        if (scanf("%d%c", &buff1[*len1], &c) == 2) {
            if (buff1[*len1] < 0 || buff1[*len1] > 9) {
                res = -1;
                flag = 1;
            }
            (*len1)++;
            if (c == '\n' || *len1 >= LEN) {
                flag = 1;
            }
        } else {
            res = -1;
            flag = 1;
        }
    }
    flag = 0;
    while (flag == 0 && *len2 < LEN) {
        if (scanf("%d%c", &buff2[*len2], &c) == 2) {
            if (buff2[*len2] < 0 || buff2[*len2] > 9) {
                res = -1;
                flag = 1;
            }
            (*len2)++;
            if (c == '\n' || *len2 >= LEN) {
                flag = 1;
            }
        } else {
            res = -1;
            flag = 1;
        }
    }
    return res;
}

void output(int *result, int result_len, int f) {
    int start_index = 0;
    while (start_index < result_len - 1 && result[start_index] == 0) {
        start_index++;
    }

    for (int i = start_index; i < result_len; i++) {
        printf("%d", result[i]);
        if (i < result_len - 1) printf(" ");
    }
    if (f == 0) {
        printf("\n");
    }
}

int check(int *buff1, int len1, int *buff2, int len2) {
    int result = 0;
    if (len1 < len2) {
        result = -1;
    } else if (len1 == len2) {
        int i = len1 - 1;
        int found = 0;
        while (i >= 0 && found == 0) {
            if (buff1[i] < buff2[i]) {
                result = -1;
                found = 1;
            } else if (buff1[i] > buff2[i]) {
                found = 1;
            }
            i--;
        }
    }
    return result;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int max_len = len1;

    if (len2 > len1) {
        max_len = len2;
    }

    for (int i = 0; i < max_len; i++) {
        int n1 = 0;
        int n2 = 0;

        if (i < len1) n1 = buff1[i];
        if (i < len2) n2 = buff2[i];

        int total = n1 + n2 + carry;
        result[i] = total % 10;
        carry = total / 10;
    }

    if (carry > 0) {
        result[max_len] = carry;
        *result_length = max_len + 1;
    } else {
        *result_length = max_len;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int borrow = 0;

    for (int i = 0; i < len1; i++) {
        int n1 = buff1[i];
        int n2 = (i < len2) ? buff2[i] : 0;
        int diff = n1 - n2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }
    int new_len = len1;
    while (new_len > 1 && result[new_len - 1] == 0) {
        new_len--;
    }
    *result_length = new_len;
}