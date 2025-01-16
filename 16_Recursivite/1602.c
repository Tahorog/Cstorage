#include <stdio.h>
#include <stdlib.h>

int somme(int taille,int tableau[taille], int n) {
    if (taille == n) {
        return 0;
    }
    return (somme(taille,tableau,n+1)+tableau[n]);
}

int main(void) {
    int sum = 0;
    int taille = 0;
    printf("Taille du tableau ?\n");
    scanf("%d", &taille);
    printf("Remplir le tableau\n");
    int * tableau = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++) {
        printf("-");
        scanf("%d", &tableau[i]);
    }
    printf("Somme des elements : %d\n",somme(taille,tableau,0));
    free(tableau);
    return 0;
}
