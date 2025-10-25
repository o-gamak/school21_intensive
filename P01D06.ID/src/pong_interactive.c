#include <math.h>
#include <ncurses.h>
#include <stdio.h>

void field(int y_ball, int x_ball, int l_racket, int r_racket, int l_p,
           int r_p) {
  const int max_print_x = 81;
  const int max_print_y = 25;

  clear();
  printw("                 ╔══════════════════════════════════════════════╗\n");
  printw("                 ║                  PONG GAME                   ║\n");
  printw(
      "                 ║                 Счет: %d : %d                  ║\n",
      l_p, r_p);
  printw("                 ╠══════════════════════════════════════════════╣\n");
  for (int i = 1; i <= max_print_y; i++) {
    for (int j = 0; j <= max_print_x; j++) {
      if ((i == y_ball) && (j == x_ball)) {
        printw("*");
      } else if ((i == max_print_y || i == 1) && (j <= max_print_x) &&
                 (j >= 1)) {
        printw("-");
      } else if (j == 40 && i > 1 && i < max_print_y) {
        printw("|");
      } else if ((j == 0 || j == (max_print_x)) && (i > 1) &&
                 (i < max_print_y)) {
        printw("|");
      } else if (j == 2 && (i >= l_racket) && (i < l_racket + 3)) {
        printw("|");
      } else if (j == max_print_x - 2 && (i >= r_racket) &&
                 (i < r_racket + 3)) {
        printw("|");
      } else {
        printw(" ");
      }
    }
    printw("\n");
  }
  refresh();
}

int ball_turn(int x_ball, int y_ball, int flag_y, int flag_x, int l_racket,
              int r_racket) {
  int res_vector;
  if (((x_ball + flag_x == 79) && (y_ball >= r_racket) &&
       (y_ball < r_racket + 3)) ||
      ((x_ball + flag_x == 2) && (y_ball >= l_racket) &&
       (y_ball < l_racket + 3))) {
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
  return res_vector;
}

int movement_l(char key, int last) {
  if (key == 'a' || key == 'A') {
    if (last > 2) {
      last = last - 1;
    }
  } else if (key == 'z' || key == 'Z') {
    if (last < 22) {
      last = last + 1;
    }
  }
  return last;
}

int movement_r(char key, int last) {
  if (key == 'k' || key == 'K') {
    if (last > 2) {
      last = last - 1;
    }
  } else if (key == 'm' || key == 'M') {
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
  clear();
  printw("\t\t╔════════════════════════════╗\n");
  printw("\t\t║        GAME OVER!          ║\n");
  printw("\t\t║      FINAL SCORE: %2d - %2d  ║\n", points_left, points_right);
  printw("\t\t║        Win: player_%d       ║\n", win);
  printw("\t\t╚════════════════════════════╝\n");
  refresh();
  getch();
}

int main() {
  int points_left = 0, points_right = 0, end_game = 0;
  int x_ball = 30, y_ball = 12, x_flag = 1, y_flag = 1, l_r = 12, r_r = 12;
  char key;

  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  scrollok(stdscr, TRUE);

  field(y_ball, x_ball, l_r, r_r, points_left, points_right);

  while (!end_game) {
    int return_ball = ball_turn(x_ball, y_ball, y_flag, x_flag, l_r, r_r);
    key = getch();

    if (key == 'a' || key == 'z' || key == 'A' || key == 'Z') {
      l_r = movement_l(key, l_r);
    }
    if (key == 'k' || key == 'm' || key == 'K' || key == 'M') {
      r_r = movement_r(key, r_r);
    }
    if (key == 'q' || key == 'Q') {
      end_game = 1;
    }

    if (return_ball == -1000 || return_ball == 1000) {
      (return_ball == 1000) ? points_left++ : points_right++;
      x_ball = 30;
      y_ball = 12;
      x_flag = (return_ball == 1000) ? -1 : 1;
    } else if (return_ball == -10) {
      x_ball += x_flag;
      y_ball += y_flag;
    } else if (return_ball == -666) {
      x_flag *= -1;
      x_ball += x_flag;
      y_ball += y_flag;
    } else if (return_ball == -555) {
      y_flag *= -1;
      x_ball += x_flag;
      y_ball += y_flag;
    }

    field(y_ball, x_ball, l_r, r_r, points_left, points_right);
    napms(50);

    if ((points_left == 21) || (points_right == 21))
      end_game = 1;
  }

  end_write(points_left, points_right);
  endwin();
  return 0;
}
