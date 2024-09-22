#include <stdio.h>

int main(void) {
    int nombre, somme = 0, i = 0;
    float moyenne;

    printf("Enter positive integers (enter a negative number to stop) :\n");

    while (1) {
        scanf("%d", &nombre);
        if (nombre < 0) {
            break;
        }
        somme += nombre;
        i++;
    }

    if (i > 0) {
        moyenne = (float)somme / i;
        printf("The average of the numbers entered is : %.2f\n", moyenne);
    } else {
        printf("No positive numbers were entered.\n");
    }

    return 0;
}
