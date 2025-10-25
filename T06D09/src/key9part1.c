#include <stdio.h>
#define MAX_L 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[MAX_L];
    int res[MAX_L] = {0};
    if (input(data, &n)) {
        printf("n/a\n");
        return 1;
    }
    int summa = sum_numbers(data, n);
    if (find_numbers(data, n, summa, res) == 0) {
        printf("n/a\n");
        return 1;
    }
    printf("%d\n", summa);
    output(res, MAX_L);
}

int input(int *buffer, int *length) {
    char c;
    if ((scanf("%d%c", length, &c) != 2) || *length < 1 || *length > MAX_L || (c != '\n')) {
        return 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &c) != 2 || (c != '\n' && c != ' ')) {
            return 1;
        }
    }
    return 0;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            printf("%d ", buffer[i]);
        }
    }
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if ((buffer[i] % 2 == 0) && (buffer[i] != 0)) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/* ------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
  -------------------------------------  */
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int k = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[k] = buffer[i];
            k++;
        }
    }
    return k;
}
