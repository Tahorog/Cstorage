#include <stdio.h>
#include "Cour4.h"

//Exercice 1


int main(void)
{
    int entier_1, entier_2;
    printf("Enter 2 numbers: ");
    scanf("%d%d", &entier_1, &entier_2);

    printf("Max is %d\n", getMax(entier_1, entier_2));


    return 0;
}
