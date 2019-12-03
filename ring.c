#include <stdio.h>
#include <math.h>

#define N       21
#define font    178

void fillSys(int coor[N][N], int r1, int r2) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(pow(i-((N-1)/2), 2) + pow(j-((N-1)/2), 2) < pow(r1, 2) && !(pow(i-((N-1)/2), 2) + pow(j-((N-1)/2), 2) < pow(r2, 2))) {
                coor[j][i] = 1;
            }
        }
    }
}

void drawRing(int coor[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coor[j][i] == 1) {
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
    int coordinate[N][N] = {0};
    int r1, r2;

    printf("Please enter radius of big circle: ");
    scanf("%i", &r1);

    printf("Please enter radius of small circle: ");
    scanf("%i", &r2);

    fillSys(coordinate, r1, r2);

    drawRing(coordinate);

    return 0;
}
