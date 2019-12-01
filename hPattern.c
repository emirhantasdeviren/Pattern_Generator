#include <stdio.h>

#define N 21

int evenOdd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}    

void fillH(int coord[N][N], int w, int h) {
    int i, j;

    int center      =   (N-1)/2;
    int leftEnd     =   center - (w/2);
    int rightEnd    =   center + (w/2) + evenOdd(w);
    int bottom      =   center - (h/2);
    int top         =   center + (h/2) + evenOdd(h);

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

void drawH(int coord[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[i][j] == 1) {
                printf("\u2592");
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

    fillH(coord, w, h);

    drawH(coord);
    
    return 0;
}
