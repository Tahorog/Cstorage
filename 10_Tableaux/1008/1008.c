#include <stdio.h>
#include "foncts.h"

#define LIGNES 4
#define COLONES 5

int main(void) {
    char tab[LIGNES][COLONES];

    remplir(tab);
    printf("\nMatrice saisie :\n");
    show(tab);

    maj(tab);
    printf("\nMatrice transformee :\n");
    show(tab);

    invert(tab);
    printf("\nMatrice inversee :\n");
    show(tab);
}
