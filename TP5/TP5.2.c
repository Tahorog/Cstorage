#include <stdio.h>
int main(void){
    int tab[100];
    int taille, max = 0;

    do {
        printf("Entre un nombre d'entier");
        scanf("%d",&taille);
    } while (taille < 1 || taille > 100);

    for (int i = 0; i < taille; i++) {
        scanf("%d",&tab[i]);
        if (tab[i] > max)
            max = tab[i];
    }
    printf("%d ", max);
    return 0;
}
