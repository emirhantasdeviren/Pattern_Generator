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
int i,j;
int center  =   (N-1)/2;
    int leftEnd =   center - (w/2);
    int rightEnd=   center + (w/2) + evenOdd(w);
    int top     =   center - (h/2);
    int bottom  =   center + (h/2) + evenOdd(h);

   for(j=0;j<N;j++){
	for(i=0;i<N;i++){
            if((i == leftEnd || i == rightEnd) && (j <= bottom && j >= top)){
            	coordinate[j][i]=1;
			}
			else if((j == top || j == bottom) && (i <= rightEnd && i >= leftEnd)){
            	coordinate[j][i]=1;
			}
	
	}
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
