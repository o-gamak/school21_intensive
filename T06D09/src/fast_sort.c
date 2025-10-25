#include <stdio.h>
#define NMAX 10

void change(int *a, int *b);
int partition(int *arr, int left, int right);
void quick_sort(int *arr, int left, int right);
void output(int *arr, int size);
int input(int *arr);
void piramid(int *arr, int n, int i);
void piramid_sort(int *arr, int n);
void copy_array(int *arr1, int *arr2);

int main(void) {
    int arr[NMAX];
    int for_quick[NMAX], for_heap[NMAX];
    int n = sizeof(arr) / sizeof(arr[0]);

    if (!input(arr)) {
        printf("n/a");
        return 1;
    }

    copy_array(arr, for_quick);
    copy_array(arr, for_heap);
    quick_sort(for_quick, 0, n - 1);
    piramid_sort(for_heap, n);
    output(for_quick, n);
    output(for_heap, n);
    return 0;
}

void change(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right) {
    int p = arr[left];
    int i = left;
    int j = right;

    while (i < j) {
        while (arr[i] <= p && i < right) i++;
        while (arr[j] > p && j > left) j--;

        if (i < j) {
            change(&arr[i], &arr[j]);
        }
    }
    change(&arr[left], &arr[j]);
    return j;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}
void output(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (i != size - 1)
            printf("%d ", arr[i]);

        else
            printf("%d", arr[i]);
    }
    printf("\n");
}

int input(int *arr) {
    char c;
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d%c", &arr[i], &c) != 2 || (c != ' ' && c != '\n')) return 0;
    }

    return 1;
}

void piramid(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        change(&arr[i], &arr[largest]);
        piramid(arr, n, largest);
    }
}

void piramid_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        piramid(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        change(&arr[0], &arr[i]);
        piramid(arr, i, 0);
    }
}

void copy_array(int *arr1, int *arr2) {
    for (int i = 0; i < NMAX; i++) {
        arr2[i] = arr1[i];
    }
}