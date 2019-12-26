#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "pattern.h"
#include "menu.h"

#define N 21
#define K 201

int main(void) {
    unsigned short r, c;

    menu(&r, &c);
    
    unsigned short menu_assign[r][c], pattern_number = 0, column_number = 0;
    unsigned short main_arr_size_i = N*r, main_arr_size_j = N*c;
    unsigned short i, j;
    bool main_arr[main_arr_size_i][main_arr_size_j];

    for (i = 0; i < main_arr_size_i; i++) {
        for (j = 0; j < main_arr_size_j; j++) {
            main_arr[i][j] = false;
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%hu. row, %hu. column: ", i+1, j+1);
            scanf("%hu", &menu_assign[i][j]);
        }
    }

    double coord[K][K] = {0};

    for(i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (menu_assign[i][j] == 1) {
                fill_ellipse(coord);
                draw_ellipse(coord, (bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
        }
        column_number++;
        pattern_number = 0;
    }

    for (i = 0; i < main_arr_size_i; i++) {
        for (j = 0; j < main_arr_size_j; j++) {
            if (main_arr[i][j]) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
