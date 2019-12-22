#include <stdio.h>

#define N       21
#define font    178

short even_odd(unsigned short x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}

void fill_frame(unsigned short coord[N][N], unsigned short w, unsigned short h) {
    unsigned short i,j;

    unsigned short center   =   (N-1)/2;
    unsigned short left_end =   center - (w/2);
    unsigned short right_end=   center + (w/2) + even_odd(w);
    unsigned short top      =   center - (h/2);
    unsigned short bottom   =   center + (h/2) + even_odd(h);

    for (j = 0; j < N; j++){
        for (i = 0; i < N; i++){
            if ((i == left_end || i == right_end) && (j <= bottom && j >= top)){
                coord[j][i] = 1;
            }
            else if ((j == top || j == bottom) && (i <= right_end && i >= left_end)){
                coord[j][i] = 1;
            }
        }
    }
}

void draw_frame(unsigned short coord[N][N]) {

    unsigned short i, j;

    for (j = 0; j < N; j++) { 
        for (i = 0; i < N; i++) {
            if (coord[j][i] == 1) {
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

    unsigned short coord[N][N]= {0};
    unsigned short w, h;

    printf("Please enter width of your rectangle: ");
    scanf("%hu", &w);

    printf("Please enter height of your rectangle: ");
    scanf("%hu", &h);

    fill_frame(coord, w, h);

    draw_frame(coord);

    return 0;
}
