#include <stdio.h>

int main(void) {

    //Exercice 902

    printf("\n");

    int val1;
    unsigned char val2;
    char lettre;
    int* pt1;
    unsigned char* pt2;
    char* pt3;

    pt1 = &val1;
    pt2 = &val2;
    pt3 = &lettre;

    int** ppt1;
    unsigned char** ppt2;
    char** ppt3;

    ppt1 = &pt1;
    ppt2 = &pt2;
    ppt3 = &pt3;


    val1 = 10;
    val2 = 'e';
    lettre = 'z';

    printf("val1 = %d\n", val1);
    printf("val2 = %c\n", val2);
    printf("lettre = %c\n", lettre);
    printf("\n");

    *pt1 = 11;
    *pt2 = 'o';
    *pt3 = 'c';

    printf("val1 = %d\n", *pt1);
    printf("val2 = %c\n", *pt2);
    printf("lettre = %c\n", *pt3);
    printf("\n");

    **ppt1 = 33;
    **ppt2 = 'g';
    **ppt3 = 'p';

    printf("val1 = %d\n", **ppt1);
    printf("val2 = %c\n", **ppt2);
    printf("lettre = %c\n", **ppt3);
    printf("\n");

    return 0;
}
