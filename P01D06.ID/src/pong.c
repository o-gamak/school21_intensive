#include <math.h>
#include <stdio.h>

void field(int y_ball, int x_ball, int l_racket, int r_racket, int l_p,
           int r_p) {
  const int max_print_x = 81;
  const int max_print_y = 25;
  printf("\033[1;36m");
  printf("                 ╔══════════════════════════════════════════════╗\n");
  printf("                 ║                  PONG GAME                   ║\n");
  printf(
      "                 ║                 Счет: %d : %d                  ║\n",
      l_p, r_p);
  printf("                 ╠══════════════════════════════════════════════╣\n");
  for (int i = 1; i <= max_print_y; i++) {
    for (int j = 0; j <= max_print_x; j++) {
      if ((i == y_ball) && (j == x_ball)) {
        printf("\033[1;37m*\033[1;36m");
      } else if ((i == max_print_y || i == 1) && (j <= max_print_x) &&
                 (j >= 1)) {
        printf("-");
      } else if (j == 40 && i > 1 && i < max_print_y) {
        printf("\033[1;37m|\033[1;36m");
      } else if ((j == 0 || j == (max_print_x)) && (i > 1) &&
                 (i < max_print_y)) {
        printf("|");
      } else if (j == 2 && (i >= l_racket) && (i < l_racket + 3)) {
        printf("|");
      } else if (j == max_print_x - 2 && (i >= r_racket) &&
                 (i < r_racket + 3)) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// -1 - вектор ++, -2 - вектор -+, -3 - вестор --, -4 вектор +-
int ball_turn(int x_ball, int y_ball, int flag_y, int flag_x, int l_racket,
              int r_racket) {
  int res_vector;
  if (((x_ball + flag_x == 78) && (y_ball + flag_y >= r_racket) &&
       (y_ball + flag_y < r_racket + 3)) ||
      ((x_ball + flag_x == 3) && (y_ball + flag_y >= l_racket) &&
       (y_ball + flag_y < l_racket + 3))) {
    res_vector = -666;
  } else if ((y_ball + flag_y == 25) || (y_ball + flag_y == 1)) {
    res_vector = -555;
  } else if (x_ball == 1) {
    res_vector = -1000;
  } else if (x_ball == 80) {
    res_vector = 1000;
  } else {
    res_vector = -10;
  }
  return res_vector; // общий рет
}

int movement_l(char key, int last) {
  if (key == 'a' || key == 'A') { // right up
    if (last > 2) {
      last = last - 1;
    }
  } else if (key == 'z' || key == 'Z') { // right down
    if (last < 22) {
      last = last + 1;
    }
  }
  return last;
}

int movement_r(char key, int last) {
  if (key == 'k' || key == 'K') { // left up
    if (last > 2) {
      last = last - 1;
    }
  } else if (key == 'm' || key == 'M') { // left up
    if (last < 22) {
      last = last + 1;
    }
  }
  return last;
}

void end_write(int points_left, int points_right) {
  int win;
  if (points_left > points_right) {
    win = 1;
  } else {
    win = 2;
  }
  printf("\e[1;1H\e[2J");
  printf("\033[1;32m"); // Зеленый цвет
  printf("\t\t╔════════════════════════════╗\n");
  printf("\t\t║        GAME OVER!          ║\n");
  printf("\t\t║      FINAL SCORE: %2d - %2d  ║\n", points_left, points_right);
  printf("\t\t║        Win: player_%d       ║\n", win);
  printf("\t\t╚════════════════════════════╝\n");
  printf("\033[0m");
}

int main() {
  int points_left = 0, points_right = 0, movment = 0, end_game = 0;
  int x_ball = 30, y_ball = 12, x_flag = -1, y_flag = 1, l_r = 12, r_r = 12;
  char key;
  printf("\e[1;1H\e[2J");
  field(y_ball, x_ball, l_r, r_r, points_left, points_right);
  while (!end_game) {
    int return_ball = ball_turn(x_ball, y_ball, y_flag, x_flag, l_r, r_r);
    scanf("%c", &key);
    while (getchar() != '\n')
      ;
    if (key == 'a' || key == 'z') {
      l_r = movement_l(key, l_r);
      movment = 1;
    }
    if (key == 'k' || key == 'm') {
      r_r = movement_r(key, r_r);
      movment = 1;
    }
    if (key == ' ')
      movment = 1;
    if (return_ball == -1000 || return_ball == 1000) {
      (return_ball == 1000) ? points_left++ : points_right++;
      x_ball = 30;
      y_ball = 12;
    } else if (return_ball == -10) {
      x_ball += x_flag;
      y_ball += y_flag;
    } else if (return_ball == -666) {
      x_flag *= -1;
    } else if (return_ball == -555)
      y_flag *= -1;
    if (movment == 1) {
      printf("\e[1;1H\e[2J");
      field(y_ball, x_ball, l_r, r_r, points_left, points_right);
      movment = 0;
    }
    if ((points_left == 21) || (points_right == 21))
      end_game = 1;
  }
  end_write(points_left, points_right);
  return 0;
}
