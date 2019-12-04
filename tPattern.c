#include <stdio.h>

#define N 21
#define font 178

int evenOdd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}

void fillT(int coord[N][N], int w, int h) {
    int i, j;
    int center  =   (N-1)/2;
    int leftEnd =   center - (w/2);
    int rightEnd=   center + (w/2) + evenOdd(w);
    int top     =   center - (h/2);
    int bottom  =   center + (h/2) + evenOdd(h);

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if((i <= rightEnd && i >= leftEnd) && j == top) {
                coord[j][i] = 1;
            }
            if(i == center && (j <= bottom && j >= top)) {
                coord[j][i] = 1;
            }
        }
    }
}

void drawT(int coord[N][N]) {
    int i, j;

    for(j = 0; j<= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[j][i] == 1) {
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
    int coord[N][N]= {0};
    int w, h;

    printf("Welcome to T drawer\n\n");
    printf("Please enter width: ");
    scanf("%i", &w);

    printf("Please enter height: ");
    scanf("%i", &h);

    fillT(coord, w, h);

    drawT(coord);

    return 0;
}
