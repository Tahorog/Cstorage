#include <stdio.h>
#include <stdlib.h>

float * get_tableau(int * taille) {
    printf("Entrez la taille du tableau : ");
    scanf("%d", taille);

    // Allocation dynamique du tableau
    float *tableau = (float*)malloc(*taille * sizeof(float));
    if (tableau == NULL) { // verifie que malloc a fonctionne
        printf("Erreur d'allocation memoire !\n");
    }

    for (int i = 0; i < *taille; i++) { // saisis les elements 
        printf("%d : ", i + 1);
        scanf("%f", &tableau[i]);
    }
    return tableau;
}

void print_tableau(float * tableau, int taille) { // Affich le tableau
    for (int i = 0; i < taille; i++) {
        printf("%.2f \n", tableau[i]);
    }
}

// Fonction de comparaison pour le tri
int comparer(const void *a, const void *b) {// meme que pour ex 1502 mais avec des floats
    float valA = *(float*)a;
    float valB = *(float*)b;

    if (valA < valB)
        return -1;
    if (valA > valB)
        return 1;
    return 0; // les valeures sont egalles
}

void trier_tableau(float *tableau, int taille) {
    qsort(tableau, taille, sizeof(float), comparer);
    printf("\nTableau Trie :\n");
}

int main(void) {
    int taille;
    float *tableau = get_tableau(&taille);

    printf("Tableau :\n");
    print_tableau(tableau, taille);
    trier_tableau(tableau, taille);
    print_tableau(tableau, taille);

    free(tableau);
    return 0;
}
