#include <stdio.h>

#define N       21
#define font    178

int even_odd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}    

void fill_h(int coord[N][N], int w, int h) {
    int i, j;

    int center      =   (N-1)/2;
    int leftEnd     =   center - (w/2);
    int rightEnd    =   center + (w/2) + even_odd(w);
    int bottom      =   center - (h/2);
    int top         =   center + (h/2) + even_odd(h);

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if((i == leftEnd || i == rightEnd) && (j <= top && j >= bottom)) {
                coord[i][j] = 1;
            }
            if((i <= rightEnd && i >= leftEnd) && j == center) {
                coord[i][j] = 1;
            }
        }
    }
}

void draw_h(int coord[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[i][j] == 1) {
                printf("%c", font);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int w, h;
    int coord[N][N] = {0};

    printf("Welcome to H drawer\n");
    printf("Please enter the width: ");
    scanf("%i", &w);

    printf("Please enter the height: ");
    scanf("%i", &h);

    fill_h(coord, w, h);

    draw_h(coord);
    
    return 0;
}
