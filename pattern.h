#ifndef PATTERN_H
#define PATTERN_H

#define M_PI 3.14159265358979323846
#define MAX_W 640
#define MAX_H 360
#define CENTER_X 320
#define CENTER_Y 180

//Ellipse
//------------------------------------------------------------------------

void fill_ellipse(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    ssize_t r, c;
    size_t a, b;
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);

    printf("\nEnter a of your Ellipse: ");
    scanf("%zu", &a);
    printf("Enter b of your Ellipse: ");
    scanf("%zu", &b);

    for (r = 0; r < MAX_H; r++) {
        for (c = 0; c < MAX_W; c++) {
            if ((pow(r - CENTER_Y, 2) / pow(a, 2)) + (pow(c - CENTER_X, 2) / pow(b, 2)) <= 1) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
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

void fill_rectangle(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);
    size_t i, j, w, h;

    printf("\nEnter height of your Rectangle: ");
    scanf("%zu", &h);
    printf("Enter width of your Rectangle: ");
    scanf("%zu", &w);

    size_t left_end = CENTER_X - (w/2);
    size_t right_end= CENTER_X + (w/2) + even_odd(w);
    size_t top      = CENTER_Y - (h/2);
    size_t bottom   = CENTER_Y + (h/2) + even_odd(h);

    for (i = 0; i < MAX_H; i++) {
        for (j = 0; j < MAX_W; j++) {
            if ((j <= right_end && j >= left_end) && (i == top || i == bottom)) {
                *((main_arr+(main_arr_i*main_arr_size_j)) + main_arr_j) = true;
            }
            else if ((j == left_end || j == right_end) && (i <= bottom && i >= top)) {
                *((main_arr+(main_arr_i*main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
//Isosceles Triangle
//------------------------------------------------------------------------

void fill_triangle(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t main_arr_i = MAX_H * (column_number);
    size_t main_arr_j = MAX_W * (*pattern_number);
    size_t i, j, w = 0, h;
    bool print;

    printf("\nEnter height of your Isosceles Triangle: ");
    scanf("%zu", &h);

    size_t top     = CENTER_Y + (h/2) + even_odd(h);
    size_t bottom  = CENTER_Y - (h/2);

    for(i = 0; i < MAX_H; i++) {
        for(j = 0; j < MAX_W; j++) {
            if((i <= top && i >= bottom) && (j <= (CENTER_X + w) && j >= (CENTER_X - w))) {
                *((main_arr+(main_arr_i*main_arr_size_j)) + main_arr_j) = true;
                print = true;
            }
            main_arr_j++;
        }
        if(print == true) {
            w++;
            print = false;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
//Ring
//------------------------------------------------------------------------

void fill_ring(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);
    size_t r1, r2;
    ssize_t i, j;

    printf("\nEnter outer circle: ");
    scanf("%zu", &r1);
    printf("Enter inner circle: ");
    scanf("%zu", &r2);

    for (i = 0; i < MAX_H; i++) {
        for (j = 0; j < MAX_W; j++) {
            if (pow(i - CENTER_Y, 2) + pow(j - CENTER_X, 2) < pow(r1, 2) && !(pow(i - CENTER_Y, 2) + pow(j - CENTER_X, 2) < pow(r2, 2))) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
//Rectangular Frame
//------------------------------------------------------------------------
void fill_frame(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t w, h, t;
    size_t i, j;
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);

    printf("\nPlease enter height of your Rectangular Frame: ");
    scanf("%zu", &h);
    printf("Please enter width of your Rectangular Frame: ");
    scanf("%zu", &w);
    printf("Please enter thickness of your Rectangular Frame: ");
    scanf("%zu", &t);
    t--;

    size_t left_end =   CENTER_X - (w/2);
    size_t right_end=   CENTER_X + (w/2) + even_odd(w);
    size_t top      =   CENTER_Y - (h/2);
    size_t bottom   =   CENTER_Y + (h/2) + even_odd(h);

    for (i = 0; i < MAX_H; i++){
        for (j = 0; j < MAX_W; j++){
            if (((j >= left_end && j <= left_end+t) || (j <= right_end && j >= right_end-t)) && (i <= bottom && i >= top)){
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            else if (((i >= top && i <= top+t) || (i <= bottom && i >= bottom-t)) && ((j <= right_end-t) && (j >= left_end+t))){
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
//Plus Sign
//------------------------------------------------------------------------

void fill_plus(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t w, h;
    size_t i, j;
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);

    printf("\nEnter height of your plus: ");
    scanf("%zu", &h);
    printf("Enter width of your plus: ");
    scanf("%zu", &w);

    size_t left_end =   CENTER_X - (w/2);
    size_t right_end=   CENTER_X + (w/2) + even_odd(w);
    size_t top     =   CENTER_Y - (h/2);
    size_t bottom  =   CENTER_Y + (h/2) + even_odd(h);

    for (i = 0; i < MAX_H; i++) {
        for (j = 0; j < MAX_W; j++) {
            if (j == CENTER_X && (i <= bottom && i >= top)) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            else if(i == CENTER_Y && (j <= right_end && j >= left_end) ){
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
	    }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
// X
//------------------------------------------------------------------------

void fill_x(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t alpha, length;
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);

    printf("\nPlease enter degree of your X: ");
    scanf("%zu", &alpha);
    printf("Please enter the length of your X: ");
    scanf("%zu", &length);

    const ssize_t length_x = cos(alpha * M_PI / 180) * length;
    const ssize_t length_y = sin(alpha * M_PI / 180) * length;
    const ssize_t x2 = CENTER_X + length_x;
    const ssize_t y2 = CENTER_Y + length_y; 

    ssize_t x = CENTER_X - length_x;
    ssize_t y = CENTER_Y - length_y;
    const ssize_t dx = (x2 - x);
    const ssize_t dy = (y2 - y);
    int e = 0;

    while ((x <= x2) && (y <= y2)) {
        *((main_arr + ((main_arr_i + y) * main_arr_size_j)) + (main_arr_j + x)) = true;
        *((main_arr + ((main_arr_i + y) * main_arr_size_j)) + (main_arr_j + (2*CENTER_X - x))) = true;
        if (2*(e+dy) < dx) {
            x++;
            e += dy;
        }
        else if ((2*(e+dy) < 3*dx) && (2*(e+dy) >= dx)) {
            x++;
            y++;
            e = e + dy - dx;
        }
        else {
            y++;
            e -= dx;
        }
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
// T
//------------------------------------------------------------------------

void fill_t(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);
    size_t w, h;
    size_t i, j;

    printf("\nPlease enter height of your T: ");
    scanf("%zu", &h);
    printf("Please enter width of your T: ");
    scanf("%zu", &w);

    const size_t left_end    =   CENTER_X - (w/2);
    const size_t right_end   =   CENTER_X + (w/2) + even_odd(w);
    const size_t top         =   CENTER_Y - (h/2);
    const size_t bottom      =   CENTER_Y + (h/2) + even_odd(h);

    for(i = 0; i < MAX_H; i++) {
        for(j = 0; j < MAX_W; j++) {
            if((j <= right_end && j >= left_end) && i == top) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            if(j == CENTER_X && (i <= bottom && i >= top)) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------
// H
//------------------------------------------------------------------------

void fill_h(bool *main_arr, size_t main_arr_size_j, size_t *pattern_number, size_t column_number) {
    size_t main_arr_i = MAX_H * column_number;
    size_t main_arr_j = MAX_W * (*pattern_number);
    size_t w, h;
    size_t i, j;

    printf("\nPlease enter height of your H: ");
    scanf("%zu", &h);
    printf("Please enter width of your H: ");
    scanf("%zu", &w);

    int left_end    =   CENTER_X - (w/2);
    int right_end   =   CENTER_X + (w/2) + even_odd(w);
    int bottom      =   CENTER_Y - (h/2);
    int top         =   CENTER_Y + (h/2) + even_odd(h);

    for (i = 0; i < MAX_H; i++) {
        for(j = 0; j < MAX_W; j++) {
            if((j == left_end || j == right_end) && (i <= top && i >= bottom)) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            if((j <= right_end && j >= left_end) && i == CENTER_Y) {
                *((main_arr + (main_arr_i * main_arr_size_j)) + main_arr_j) = true;
            }
            main_arr_j++;
        }
        main_arr_j = MAX_W * (*pattern_number);
        main_arr_i++;
    }
    (*pattern_number)++;
}

//------------------------------------------------------------------------

#endif