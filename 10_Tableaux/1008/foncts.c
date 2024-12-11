
#include "foncts.h"
#include "stdio.h"

#define LIGNES 4
#define COLONES 5
#define DECALAGE 32

void remplir(char tab[LIGNES][COLONES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            fflush(stdin);
            scanf("%c", &tab[i][j]);
        }
    }
}

void maj(char tab[LIGNES][COLONES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            if (tab[i][j] > 96 && tab[i][j] < 123)
                tab[i][j] = tab[i][j] - DECALAGE;
        }
    }
}

void show(char tab[LIGNES][COLONES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}

void invert(char tab[LIGNES][COLONES]) {
    for (int i = 0; i < LIGNES/2; i++) {
        for (int j = 0; j < COLONES; j++) {
            char cache = tab[i][j];
            tab[i][j] = tab[LIGNES - 1 - i][COLONES - 1 - j];
            tab[LIGNES - 1 - i][COLONES - 1 - j] = cache;
        }
    }
}
