#include <stdio.h>
#include <math.h>

#define N 201

double ellipse_f(double x, double y, double a, double b) {
    double z = (pow(x, 2)/pow(a, 2)) + (pow(y, 2)/pow(b, 2));

    return (z);
}

void fill_ellipse(double coord[N][N], unsigned short a, unsigned short b) {
    unsigned short r, c;
    double x = -20/2, y = 20/2;

    for (r = 0; r < 201; r++) {
        for (c = 0; c < 201; c++) {
            coord[r][c] = ellipse_f(x, y,(double) a/10,(double) b/10);
            x += 0.1;
        }
        x = -10;
        y -= 0.1;
    }
}

void draw_ellipse(double coord[N][N], unsigned short a, unsigned short b) {
    unsigned short r, c, center = (N-1)/2, s;

    if (a < b) {
        s = b+1;
    }
    else {
        s = a+1;
    }

    for (r = center - s; r <= center + s; r++) {
        for (c = center - s; c <= center + s; c++) {
            //printf("coord[%hu][%hu] = %lf\t", r, c, coord[r][c]);
            if (coord[r][c] < 1.1 && coord[r][c] > 0.8) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    unsigned short a, b;
    double coord[N][N];

    printf("Please enter a: ");
    scanf("%hu", &a);

    printf("Please enter b: ");
    scanf("%hu", &b);

    fill_ellipse(coord, a, b);
    draw_ellipse(coord, a, b);


    return (0);
}
