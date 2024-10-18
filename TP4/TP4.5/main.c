#include <stdio.h>
#include "fonction_scanf.h"
#include "fonction_moyenne.h"

int main(void) {

int note1, note2, note3, moyenne;
    printf("Entrez trois notes : ");
    note1 = saisirEntier(note1);
    note2 = saisirEntier(note2);
    note3 = saisirEntier(note3);

    moyenne = affichageMoyenne(note1, note2, note3);

    return 0;
}
