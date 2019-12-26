#define K 201
#define N 21
#define font '*'

//Ellipse
//------------------------------------------------------------------------

double ellipse_f(double x, double y, double a, double b) {
    double z = (pow(x, 2)/pow(a, 2)) + (pow(y, 2)/pow(b, 2));

    return (z);
}

void fill_ellipse(double coord[K][K]) {
    unsigned short r, c;
    unsigned short a, b;
    double x = -20/2, y = 20/2;

    printf("Enter a: ");
    scanf("%hu", &a);
    printf("Enter b: ");
    scanf("%hu", &b);

    for (r = 0; r < K; r++) {
        for (c = 0; c < K; c++) {
            coord[r][c] = ellipse_f(x, y,(double) a/10,(double) b/10);
            x += 0.1;
        }
        x = -10;
        y -= 0.1;
    }
}

void draw_ellipse(double coord[K][K], bool *main_arr, unsigned short main_arr_size_j, unsigned short *pattern_number, unsigned short column_number) {
    unsigned short r, c, center = (K-1)/2;
    unsigned short main_arr_j = N*(*pattern_number);
    unsigned short main_arr_i = N*(column_number);

    for (r = center - 10; r <= center + 10; r++) {
        for (c = center - 10; c <= center + 10; c++) {
            if (coord[r][c] < 1.3 && coord[r][c] > 0.7) {
                *((main_arr+(main_arr_i*main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = N*(*pattern_number);
        main_arr_i++;
    }

    (*pattern_number)++;
}

//------------------------------------------------------------------------
// Rectangle
//------------------------------------------------------------------------

int even_odd(int x) {
    if(x % 2 == 0) {
        return -1;
    }

    else {
        return 0;
    }
}

void fill_rectangle(int coordinate[N][N], int w, int h) {

    int i = ((N-1)/2) - (w/2);
    int j = ((N-1)/2) - (h/2);

    while(j <= ((N-1)/2) + (h/2) + even_odd(h)) {
        while(i <= ((N-1)/2) + (w/2) + even_odd(w)) {
            coordinate[j][i] = 1;
            i++;
        }
        i = ((N-1)/2) - (w/2);
        j++;
    }
}

void draw_rectangle(int coordinate[N][N]) {

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

//------------------------------------------------------------------------
//Isosceles Triangle
//------------------------------------------------------------------------

void fill_triangle(int coord[N][N], int h) {
    int i, j, w = 0;
    bool print;

    int center  = (N-1) / 2;
    int top     = center + (h/2) + even_odd(h);
    int bottom  = center - (h/2);

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if((j <= top && j >= bottom) && (i <= (center + w) && i >= (center - w))) {
                coord[j][i] = 1;
                print = true;
            }
        }
        if(print == true) {
            w++;
            print = false;
        }
    }
}

void draw_triangle(int coord[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[j][i] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//------------------------------------------------------------------------
//Ring
//------------------------------------------------------------------------

void fill_ring(int coor[N][N], int r1, int r2) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(pow(i-((N-1)/2), 2) + pow(j-((N-1)/2), 2) < pow(r1, 2) && !(pow(i-((N-1)/2), 2) + pow(j-((N-1)/2), 2) < pow(r2, 2))) {
                coor[j][i] = 1;
            }
        }
    }
}

void draw_ring(int coor[N][N]) {
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

//------------------------------------------------------------------------
//Rectangular Frame
//------------------------------------------------------------------------





//------------------------------------------------------------------------
//Plus Sign
//------------------------------------------------------------------------

void fill_plus(int coord[N][N], int w, int h) {
    int i,j;

    int center  =   (N-1)/2;
    int leftEnd =   center - (w/2);
    int rightEnd=   center + (w/2) + even_odd(w);
    int top     =   center - (h/2);
    int bottom  =   center + (h/2) + even_odd(h);

    for(j = 0; j < N; j++){
        for(i = 0; i < N; i++){
            if(i == center && (j<=bottom && j>=top)){
                coord[j][i]=1;
            }
            else if(j == center && (i<=rightEnd && i>=leftEnd) ){
            	coord[j][i]=1;
            }
	    }
    }
}

void draw_plus(int coord[N][N]) {

    int i, j;

    for(j = 0; j < N; j++) { 
        for(i = 0; i < N; i++) {
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

//------------------------------------------------------------------------
// X
//------------------------------------------------------------------------

double f(double x, double alpha) {
    double y = tan(alpha) * x;

    return y;
}

void fill_x(double coord[K][K], double alpha) {
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

void draw_x(double coord[K][K], unsigned short length) {
    unsigned short r, c, center = (K-1)/2;
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

//------------------------------------------------------------------------
// T
//------------------------------------------------------------------------

void fill_t(int coord[N][N], int w, int h) {
    int i, j;
    int center  =   (N-1)/2;
    int leftEnd =   center - (w/2);
    int rightEnd=   center + (w/2) + even_odd(w);
    int top     =   center - (h/2);
    int bottom  =   center + (h/2) + even_odd(h);

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

void draw_t(int coord[N][N]) {
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

//------------------------------------------------------------------------
// H
//------------------------------------------------------------------------

void fill_h(int coord[N][N], int w, int h) {
    int i, j;

    int center      =   (N-1)/2;
    int leftEnd     =   center - (w/2);
    int rightEnd    =   center + (w/2) + even_odd(w);
    int bottom      =   center - (h/2);
    int top         =   center + (h/2) + even_odd(h);

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

void draw_h(int coord[N][N]) {
    int i, j;

    for(j = 0; j <= N-1; j++) {
        for(i = 0; i <= N-1; i++) {
            if(coord[i][j] == 1) {
                printf("%c", font);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//------------------------------------------------------------------------
