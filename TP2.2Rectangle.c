//Exercice 2
#include <stdio.h>
int main(void){

    float largeur, longueur, perimetre, aire;
    printf("Entrez la largeur et la longueur du rectangle : \n");
    scanf("%f %f", &largeur, &longueur);
    perimetre = (largeur + longueur) * 2;
    aire = largeur * longueur;
    printf("La perimetre est : %f\n", perimetre);
    printf("L'aire est : %f\n", aire);
return 0;
}
