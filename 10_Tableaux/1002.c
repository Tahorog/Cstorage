#include <stdio.h>

#define LIGNES 7
#define COLONNES 4

int main(void) {
    float tab[LIGNES][COLONNES];

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
            scanf("%f",&tab[i][j]);
    }

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++)
            printf("%f  ",tab[i][j]);
        printf("\n");
    }

    return 0;
}
