#include <stdio.h>
#include "fonction_scanf.h"
#include "fonction_rectangle.h"


int main(void) {

    //Exercice 3
    int largeur, longueur, aire, perimetre;

    largeur = saisirEntier(largeur);
    longueur = saisirEntier(longueur);
    aire = calculAire(largeur, longueur);
    perimetre = calculAire(largeur, longueur);
    printf("La perimetre est: %d\n", perimetre);
    printf("La aire est: %d\n", aire);
  return 0;
}
