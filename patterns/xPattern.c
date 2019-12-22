#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979
#define N 201

double f(double x, double alpha) {
    double y = tan(alpha) * x;

    return y;
}

void fill_x(double coord[N][N], double alpha) {
    unsigned short r, c;
    double x = -10;

    for (r = 0; r < 201; r++) {
        for (c = 0; c < 201; c++) {
            coord[r][c] = f(x, alpha);
            x += 0.1;
        }
        x = -10;
    }
}

void draw_x(double coord[N][N], unsigned short length) {
    unsigned short r, c, center = (N-1)/2;
    double y = length;
    y /= 10;

    for (r = center - length; r < center + length; r++) {
        for (c = center - length; c < center + length; c++) {
            //printf("%lf - %lf = %lf\n", y, coord[r][c], y - coord[r][c]);
            if ((y - coord[r][c]) < 0.1 && (y - coord[r][c]) > -0.1) {
                printf("*");
            }
            else if ((y - (-coord[r][c]) < 0.1) && (y - (-coord[r][c]) > -0.1)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        y -= 0.1;
        printf("\n");
    }
}

int main(void) {
    unsigned short length;
    double coord[N][N] = {0}, alpha;

    printf("Enter the length of X: ");
    scanf("%hu", &length);

    printf("Enter the horizontal axis angle (0-90): ");
    scanf("%lf", &alpha);

    alpha = alpha*(pi/180);

    fill_x(coord, alpha);

    draw_x(coord, length);
    
    return (0);
}
