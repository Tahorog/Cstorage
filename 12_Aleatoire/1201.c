#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int getRand() {
    return (rand() % 200 + 1); // entre 1 et 200
}

int main(void) {
    srand(time(NULL));
    int retour=0;
    int essais=0;
    int nombre=getRand();
    do {
        printf("nombre : ");
        scanf("%d", &retour);
        essais++;
    } while (retour != nombre);
    printf("BRAVO\n\nReponce : %d\nEssais  : %d\n", nombre, essais);
    return 0;
}


