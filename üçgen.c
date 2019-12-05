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

void fillSys(int coordinate[N][N], int h) {
	int i,j,w=0;
    int center  =   (N-1)/2;
    int top = center + (h/2);
    int bottom = center - (h/2)+ evenOdd(h);
    int leftEnd =   center ;
    int rightEnd=   center ;

 for(j = 0; j < N; j++) { 
        for(i = 0; i < N; i++) {
    if((j>=bottom && j<top) && (i<=(rightEnd+w) && i>=(leftEnd-w)))
    	coordinate[j][i]=1;
    	
	    }
          w++;
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
    int h;

    printf("Please enter height of your rectangle: ");
    scanf("%i", &h);

    fillSys(coordinate,h);

    drawRectangle(coordinate);

    return 0;
}
