#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include "pattern.h"
#include "menu.h"

#define MAX_W 640
#define MAX_H 360

int main(void) {
    size_t r, c, repeat;
    FILE *fptr;

    menu(&r, &c, &repeat);
    repeat++;
    
    size_t pattern_assign[r][c], pattern_number = 0, column_number = 0;
    size_t main_arr_size_i = MAX_H * r, main_arr_size_j = MAX_W * c * repeat;
    size_t i, j;
    bool *main_arr = (bool *)malloc(main_arr_size_i * main_arr_size_j * sizeof(bool));

    for (i = 0; i < main_arr_size_i; i++) {
        for (j = 0; j < main_arr_size_j; j++) {
            *(main_arr + (main_arr_size_j * i) + j) = false;
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%zu. row, %zu. column: ", i+1, j+1);
            scanf("%zu", &pattern_assign[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (pattern_assign[i][j] == 1) {
                fill_ellipse((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 2) {
                fill_rectangle((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 3) {
                fill_triangle((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 4) {
                fill_ring((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 5) {
                fill_frame((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 6) {
                fill_plus((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 7) {
                fill_x((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 8) {
                fill_t((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
            else if (pattern_assign[i][j] == 9) {
                fill_h((bool *)main_arr, main_arr_size_j, &pattern_number, column_number);
            }
        }
        column_number++;
        pattern_number = 0;
    }

    if (repeat > 1) {
        for (size_t count = 1; count < repeat; count++) {
            for (i = 0; i < main_arr_size_i; i++) {
                for (j = 0; j < main_arr_size_j / repeat; j++) {
                    *(main_arr + ((main_arr_size_j * i) + (main_arr_size_j / repeat) * count) + j) = *(main_arr + (main_arr_size_j * i) + j);
                }
            }
        }
    }

    fptr = fopen("output.pbm", "w");
    fprintf(fptr, "P1\n");
    fprintf(fptr, "%zu %zu\n", main_arr_size_j, main_arr_size_i);

    for (i = 0; i < main_arr_size_i; i++) {
        for (j = 0; j < main_arr_size_j; j++) {
            if (*(main_arr + (main_arr_size_j * i) + j)) {
                fprintf(fptr, "1");
            }
            else {
                fprintf(fptr, "0");
            }
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
    free(main_arr);

    return 0;
}
