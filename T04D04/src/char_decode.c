#include <stdio.h>

int decoder(char a) {
    if (a >= '0' && a <= '9') return a - '0';
    if (a >= 'A' && a <= 'F') return a - 'A' + 10;
    if (a >= 'a' && a <= 'f') return a - 'a' + 10;
    return -1;
}
int main(int argc, char *argv[]) {
    char ar = argv[1][0];
    int fl = 0;
    char a, b, c;
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    if ((ar != '0') && (ar != '1')) {
        printf("n/a\n");
        return 1;
    }
    while (1) {
        (a = getchar());
        (b = getchar());
        if (ar == '0') {
            if ((b == ' ') && (a != ' ')) {
                printf("%02X ", a);
            }
            if ((a != ' ') && ((b == '\n') || (b == EOF))) {
                printf("%02X\n", a);
                break;
            }
            if ((b == '\n') || (b == EOF)) break;
            if (b != ' ') {
                printf("n/a\n");
                break;
            }
        } else {
            (c = getchar());
            if ((c != ' ') && (c != '\n')) {
                printf("n/a\n");
                fl = 1;
            }
            int x1 = decoder(a);
            int x2 = decoder(b);
            char value = (char)(x1 * 16 + x2);
            printf("%c ", value);
            if (c == '\n' || c == EOF) {
                printf("\n");
                break;
            }
            if (fl == 1) break;
        }
    }
    return 0;
}
