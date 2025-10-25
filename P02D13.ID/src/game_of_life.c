#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_X 80
#define MAX_Y 25

int **input(const char *filename);
int **memory();
int life_or_die(int **matrix, int x, int y);
void copy(int **matrix_old, int **matrix_new);
void game(int **matrix_old, int **matrix_new, int **matrix_start);
char visual(int el);
void output(int **matrix);
void free_matrix(int **matrix);
char *select_start(void);
int check_end_game(int **matrix_1, int **matrix_2);
void fill_zeros(int **matrix, int start_y);

int main() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);

    char *filename = select_start();

    int **matrix_old = input(filename);
    (void)freopen("/dev/tty", "r", stdin);
    int **matrix_new = memory();
    int **matrix_start = memory();
    copy(matrix_old, matrix_new);
    copy(matrix_old, matrix_start);
    game(matrix_old, matrix_new, matrix_start);
    endwin();
    free_matrix(matrix_old);
    free_matrix(matrix_new);
    free_matrix(matrix_start);

    return 0;
}

char *select_start() {
    char *result = NULL;
    printw("Start position\n");
    printw("1 - start_1\n");
    printw("2 - start_2\n");
    printw("3 - start_3\n");
    printw("4 - statrt_4\n");
    printw("5 - statrt_5\n");
    refresh();
    nodelay(stdscr, FALSE);
    echo();

    char key = getch();
    noecho();
    nodelay(stdscr, TRUE);
    if (key == '1')
        result = "start_1.txt";
    else if (key == '2')
        result = "start_2.txt";
    else if (key == '3')
        result = "start_3.txt";
    else if (key == '4')
        result = "start_4.txt";
    else if (key == '5')
        result = "start_5.txt";
    else
        result = "start_1.txt";

    clear();
    return result;
}

int life_or_die(int **matrix, int x, int y) {
    int sum = 0;
    int life = matrix[y][x];
    for (int xd = x - 1; xd <= x + 1; xd++) {
        for (int yd = y - 1; yd <= y + 1; yd++) {
            if (!(xd == x && yd == y)) {
                int xn = ((xd + MAX_X) % MAX_X);
                int yn = ((yd + MAX_Y) % MAX_Y);
                sum += matrix[yn][xn];
            }
        }
    }
    if (life == 1) {
        life = (sum == 2 || sum == 3) ? 1 : 0;
    } else {
        life = (sum == 3) ? 1 : 0;
    }
    return life;
}

void fill_zeros(int **matrix, int start_y) {
    for (int k = start_y; k < MAX_Y; k++) {
        for (int l = 0; l < MAX_X; l++) {
            matrix[k][l] = 0;
        }
    }
}

int **input(const char *filename) {
    (void)freopen(filename, "r", stdin);
    int **matrix = memory();
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            int ch;
            do {
                ch = getchar();
                if (ch == EOF) {
                    fill_zeros(matrix, i);
                    return matrix;
                }
            } while (ch == ' ' || ch == '\n');
            matrix[i][j] = (ch == '1') ? 1 : 0;
        }
    }
    (void)freclose(filename);
    return matrix;
}

int **memory() {
    int **matrix = malloc(MAX_Y * sizeof(int *));
    int *data = malloc(MAX_X * MAX_Y * sizeof(int));
    for (int i = 0; i < MAX_Y; i++) {
        matrix[i] = data + i * MAX_X;
    }
    return matrix;
}

void copy(int **matrix_old, int **matrix_new) {
    for (int j = 0; j < MAX_X; j++) {
        for (int i = 0; i < MAX_Y; i++) {
            matrix_new[i][j] = matrix_old[i][j];
        }
    }
}

void game(int **matrix_old, int **matrix_new, int **matrix_start) {
    int endgame = 1;
    int delay = 100;
    int speed_step = 20;

    while (endgame) {
        int sum_matrix = 0;
        int ch = getch();
        if (ch == ' ') {
            endgame = 0;
        } else if (ch == 'a' && delay > speed_step) {
            delay -= speed_step;
        } else if (ch == 'z' && delay < 800) {
            delay += speed_step;
        }

        for (int j = 0; j < MAX_X; j++) {
            for (int i = 0; i < MAX_Y; i++) {
                matrix_new[i][j] = life_or_die(matrix_old, j, i);
                sum_matrix += matrix_new[i][j];
            }
        }
        if ((sum_matrix == 0) || (check_end_game(matrix_old, matrix_new) == 1) ||
            (check_end_game(matrix_start, matrix_new) == 1)) {
            endgame = 0;
        }
        copy(matrix_new, matrix_old);
        clear();
        output(matrix_new);
        printw("Delay: %d (A - quickly, Z - slower, Space - exit)", delay);
        refresh();
        napms(delay);
    }
}

int check_end_game(int **matrix_1, int **matrix_2) {
    int red_flag = 1;
    for (int j = 0; j < MAX_X && red_flag; j++) {
        for (int i = 0; i < MAX_Y && red_flag; i++) {
            if ((matrix_2[i][j] != matrix_1[i][j])) {
                red_flag = 0;
            }
        }
    }
    return red_flag;
}

char visual(int el) {
    char res = '.';
    if (el == 1) {
        res = 'o';
    }
    return res;
}

void output(int **matrix) {
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            printw("%c", visual(matrix[i][j]));
        }
        printw("\n");
    }
}

void free_matrix(int **matrix) {
    if (!matrix) return;
    free(matrix[0]);
    free(matrix);
}
