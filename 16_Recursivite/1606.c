#include <stdio.h>
#include <stdlib.h>

void remplir(int taille,float tableau[taille], int n) {
    if (taille == n) {
        return;
    }
    printf("%d)",n+1);
    scanf("%f",&tableau[n]);
    fflush(stdin);
    n+=1;
    remplir(taille,tableau,n);
}

void affiche(int taille,float tableau[taille], int n) {
    if (taille == n) {
        return;
    }
    printf("%d) %.2f\n",n+1,tableau[n]);
    n+=1;
    affiche(taille,tableau,n);
}


void tri(int debut, int taille, float tableau[taille]) {
    if (taille == 1) {
        return;
    }

    // === separer ===
    tri(debut, taille/2,tableau);
    tri(debut+taille/2,taille-taille/2,tableau);

    // === trier ===
    float * tmp = malloc(sizeof(float) * taille);
    int nG = debut; // debut a gauche
    int nD = debut+taille/2; // debut a droite

    for (int i = 0; i < taille; i++) { //comparer
        if (nG-debut<taille/2 && (nD-debut==taille || tableau[nG] <= tableau[nD])) {
            tmp[i] = tableau[nG];
            nG+=1;
        } else {
            tmp[i] = tableau[nD];
            nD+=1;
        }
    }
    // mettre dans le tableau
    for (int i = 0; i < taille; i++) {
        tableau[i+debut] = tmp[i];
    }
    free(tmp);
}

int main(void) {
    int sum = 0;
    int taille = 0;
    printf("Taille du tableau ?\n");
    scanf("%d", &taille);
    float * tableau = malloc(sizeof(float) * taille);
    printf("Remplir le tableau\n");
    remplir(taille,tableau,0);
    printf("===== Tableau =====\n");
    affiche(taille,tableau,0);
    printf("===================\n\n\n");
    printf("Tri par fusion du tableau...\n\n");
    tri(0,taille,tableau);
    printf("===== Tableau =====\n");
    affiche(taille,tableau,0);
    printf("===================\n\n\n");
    free(tableau);
    return 0;
}

