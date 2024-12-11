#include <stdio.h>
#include <stdlib.h>

#define LIGNES 15
#define COLONES 20

void afficher(char tab[LIGNES][COLONES],int occurences[26]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 26; i++)
        printf("| %c ", i+97);
    printf("\n");
    for (int i = 0; i < 26; i++)
        printf(" %d", occurences[i]);
}


void remplir(char tab[LIGNES][COLONES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            tab[i][j] = rand() % 26 + 97;
        }
    }
}

void count(char tab[LIGNES][COLONES],int occurences[26]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONES; j++) {
            occurences[tab[i][j]-97]++;
        }
    }
}

int main(void) {
    char tab[LIGNES][COLONES];
    int occurences[26]={0};
    remplir(tab);
    count(tab,occurences);
    afficher(tab,occurences);
    return 0;
}


