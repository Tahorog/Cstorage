#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocation(int* lignes, int* colonnes) {
    printf("Entrer le nombre de lignes : ");
    while (scanf("%d", lignes) != 1 || *lignes <= 0) {
        printf("Erreur.");
        while (getchar() != '\n');
    }

    printf("Entrer le nombre de colonnes : ");
    while (scanf("%d", colonnes) != 1 || *colonnes <= 0) {
        printf("Erreur.");
        while (getchar() != '\n');
    }

    int** matrice = malloc(*lignes * sizeof(int*));
    if (matrice == NULL) {
        return 1;
    }

    for (int i = 0; i < *lignes; i++) {
        matrice[i] = malloc(*colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    return matrice;
}

void remplissage(int** matrice, int lignes, int colonnes) {
    srand(time(NULL));
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = rand() % 256;
        }
    }
}

void affichage(int** matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%4d", matrice[i][j]);
        }
        printf("\n");
    }
}

void liberation(int** matrice, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

int main() {
    int lignes, colonnes;
    int** matrice = allocation(&lignes, &colonnes);

    if (matrice == NULL) {
        printf("Erreur.\n");
        return 1;
    }

    remplissage(matrice, lignes, colonnes);
    affichage(matrice, lignes, colonnes);

    liberation(matrice, lignes);
    return 0;
}
