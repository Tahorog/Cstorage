#include <stdio.h>

int main(void) {
    int val1;
    unsigned int val2;
    char lettre;

    int* pt1;
    unsigned int* pt2;
    char* pt3;

    int** ppt1;
    unsigned int** ppt2;
    char** ppt3;

    pt1 = &val1;
    pt2 = &val2;
    pt3 = &lettre;

    ppt1 = &pt1;
    ppt2 = &pt2;
    ppt3 = &pt3;

    val1 = 10;
    val2 = 20;
    lettre = 'A';

    printf("\nval1 = %d\n", val1);
    printf("val2 = %d\n", val2);
    printf("lettre = %c\n\n", lettre);

    *pt1 = 100;
    *pt2 = 200;
    *pt3 = 'B';

    printf("val1 = %d\n", *pt1);
    printf("val2 = %d\n", *pt2);
    printf("lettre = %c\n\n", *pt3);

    **ppt1 = 1000;
    **ppt2 = 2000;
    **ppt3 = 'C';

    printf("val1 = %d\n", **ppt1);
    printf("val2 = %d\n", **ppt2);
    printf("lettre = %c\n\n", **ppt3);


    return 0;
}
