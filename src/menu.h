#ifndef MENU_H
#define MENU_H

void menu(size_t *r, size_t *c, size_t *repeat) {
    printf("\n\tWelcome to Pattern Generator\n"
           "\t----------------------------\n"
           "\tFirst, enter how many rows and number of patterns per row.\n"
           "\tSecond, enter specific patterns you want to generate by using numbers from 1 to 9.\n\n"
           "\t1. Ellipse\n"
           "\t2. Rectangle\n"
           "\t3. Isosceles Triangle\n"
           "\t4. Ring\n"
           "\t5. Rectangular Frame\n"
           "\t6. +\n"
           "\t7. X\n"
           "\t8. T\n"
           "\t9. H\n\n"
           "Please enter the number of rows: ");
    scanf("%zu", r);
    printf("Please enter the number of patterns per row: ");
    scanf("%zu", c);
    printf("How many times do you want to repeat your pattern? (0 if no): ");
    scanf("%zu", repeat);
    printf("\n");
}

#endif