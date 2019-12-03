#include <stdio.h>

#define N       21
#define font    178

int evenOdd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}

void fillSys(int coordinate[N][N], int w, int h) {

    int i = ((N-1)/2) - (w/2);
    int j = ((N-1)/2) - (h/2);

    while(j <= ((N-1)/2) + (h/2) + evenOdd(h)) {
        while(i <= ((N-1)/2) + (w/2) + evenOdd(w)) {
            coordinate[j][i] = 1;
            i++;
        }
        i = ((N-1)/2) - (w/2);
        j++;
    }
}

void drawRectangle(int coordinate[N][N]) {

    int i, j;

    for(j = 0; j < N; j++) { 
        for(i = 0; i < N; i++) {
            if(coordinate[j][i] == 1) {
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

    int coordinate[N][N]= {0};
    int w, h;

    printf("Please enter width of your rectangle: ");
    scanf("%i", &w);

    printf("Please enter height of your rectangle: ");
    scanf("%i", &h);

    fillSys(coordinate, w, h);

    drawRectangle(coordinate);

    return 0;
}
