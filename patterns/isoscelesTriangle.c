#include <stdio.h>
#include <stdbool.h>

#define N 21

int even_odd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}

void fill_triangle(int coord[N][N], int h) {
    int i, j, w = 0;
    bool print;

    int center  = (N-1) / 2;
    int top     = center + (h/2) + even_odd(h);
    int bottom  = center - (h/2);

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if((j <= top && j >= bottom) && (i <= (center + w) && i >= (center - w))) {
                coord[j][i] = 1;
                print = true;
            }
        }
        if(print == true) {
            w++;
            print = false;
        }
    }
}

void draw_triangle(int coord[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[j][i] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int h;
    int coord[N][N] = {0};

    printf("Please enter height of your triangle:");
    scanf("%i", &h);

    fill_triangle(coord, h);

    draw_triangle(coord);

    return 0;
}
