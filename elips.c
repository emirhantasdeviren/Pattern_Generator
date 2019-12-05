#include <stdio.h>
#include <math.h>

#define N       21
#define font    178

void fillSys(int coor[N][N], int a, int b) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
           if(((pow(i-((N-1)/2),2)/pow(a,2))+(pow(j-((N-1)/2),2)/pow(b,2)))==1)
                coor[j][i] = 1;
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
    int a,b;

    printf("Please enter radius of big circle: ");
    scanf("%i", &a);

    printf("Please enter radius of small circle: ");
    scanf("%i", &b);

    fillSys(coordinate, a,b);

    drawRing(coordinate);

    return 0;
}
