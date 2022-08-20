#include <math.h>
#include <stdio.h>
int count1 = 0;
int count2 = 0;

void field_display(int racket_left, int racket_right, int move_ball_x, int move_ball_y);

int main() {
    char button;
    int racket_left;
    int racket_right;
    int flagY, flagX;
    int move_ball_x, move_ball_y;

    racket_left = 0;
    racket_right = 0;
    move_ball_x = 12;
    move_ball_y = 20;

    field_display(racket_left, racket_right, move_ball_x, move_ball_y);

    while (1) {
        scanf("%c", &button);
        if (button == 'a') {
            racket_left = racket_left - 1;
            if (move_ball_x == 78) {
                flagX = 1;
            }
            if (move_ball_x < 3) {
                flagX = 0;
            }
            if (flagX == 0) {
                move_ball_x++;
            } else {
                move_ball_x--;
            }

            if (move_ball_y > 23) {
                flagY = 1;
            }
            if (move_ball_y < 3) {
                flagY = 0;
            }
            if (flagY == 0) {
                move_ball_y++;
            } else {
                move_ball_y--;
            }
            //
        } else if (button == 'z') {
            racket_left = racket_left + 1;
            if (move_ball_x > 78) {
                flagX = 1;
            }
            if (move_ball_x < 3) {
                flagX = 0;
            }
            if (flagX == 0) {
                move_ball_x++;
            } else {
                move_ball_x--;
            }
            if (move_ball_y > 23) {
                flagY = 1;
            }
            if (move_ball_y < 2) {
                flagY = 0;
            }
            if (flagY == 0) {
                move_ball_y++;
            } else {
                move_ball_y--;
            }
            //
        } else if (button == 'k') {
            racket_right = racket_right - 1;
            if (move_ball_x > 78) {
                flagX = 1;
            }
            if (move_ball_x < 3) {
                flagX = 0;
            }
            if (flagX == 0) {
                move_ball_x++;
            } else {
                move_ball_x--;
            }
            if (move_ball_y > 23) {
                flagY = 1;
            }
            if (move_ball_y < 2) {
                flagY = 0;
            }
            if (flagY == 0) {
                move_ball_y++;
            } else {
                move_ball_y--;
            }
            //
        } else if (button == 'm') {
            racket_right = racket_right + 1;
            if (move_ball_x > 78) {
                flagX = 1;
            }
            if (move_ball_x < 3) {
                flagX = 0;
            }
            if (flagX == 0) {
                move_ball_x++;
            } else {
                move_ball_x--;
            }
            if (move_ball_y > 23) {
                flagY = 1;
            }
            if (move_ball_y < 2) {
                flagY = 0;
            }
            if (flagY == 0) {
                move_ball_y++;
            } else {
                move_ball_y--;
            }
            //
        } else if (button == ' ') {
            if (move_ball_x > 78) {
                flagX = 1;
            }
            if (move_ball_x < 3) {
                flagX = 0;
            }
            if (flagX == 0) {
                move_ball_x++;
            } else {
                move_ball_x--;
            }
            if (move_ball_y > 23) {
                flagY = 1;
            }
            if (move_ball_y < 2) {
                flagY = 0;
            }
            if (flagY == 0) {
                move_ball_y++;
            } else {
                move_ball_y--;
            }
            //
        } else {
            if (button == 'q') break;
        }
        printf("\33c\e[3j");
        field_display(racket_left, racket_right, move_ball_x, move_ball_y);
    }

    return 0;
}

void field_display(int racket_left, int racket_right, int move_ball_x, int move_ball_y) {
    int length = 80;
    int width = 25;
    char symbol1 = '=';
    int ball_x = 0;
    int ball_y = 0;
    ball_x = ball_x + move_ball_x;
    ball_y = ball_y + move_ball_y;

    int a = 10 + racket_left;
    int b = 20 + racket_right;

    // верхняя гориз граница поля
    for (int i = 0; i <= (length - 3); i++) {
        if (i == 25) {
            printf(" %d", count1);
        } else if (i == 50) {
            printf(" %d", count2);
        } else {
            printf("%c", symbol1);
        }
    }
    printf("\n");
    //

    // Средняя часть поля
    for (int j = 1; j < width; j++) {
        for (int i = 1; i <= length; i++) {
            if ((i == 1) || (i == 40) || (i == 80)) {
                printf("|");
            } else if ((i == ball_x) && (j == ball_y)) {
                if (ball_x == 2 && ball_y != a && ball_y != (a + 1) && ball_y != (a + 2)) {
                    count2++;
                    continue;
                } else if (ball_x == 79 && ball_y != a && ball_y != (a + 1) && ball_y != (a + 2)) {
                    count1++;
                    continue;
                } else {
                    printf("*"); }
            } else if (i == 2 && (j == a || j == (a + 1) || j == (a + 2))) {  // отрисовка левой
                printf("]");

            } else if (i == 79 && (j == b || j == (b + 1) || j == (b + 2))) {  // отрисовка правой ракетки
                printf("[");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Нижняя часть гориз поля
    for (int i = 0; (length - 1) >= i; i++) {
        printf("%c", symbol1);
    }

    printf("\n");

    //
    if (count1 >= 21) {
        printf("Пoбедил 2й игрок!!!!");
    } else if (count2 >= 21) {
        printf("Пoбедил 1й игрок!!!!");
    }
    //
}
