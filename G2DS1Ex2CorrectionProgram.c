#include <stdio.h>
//fais par dimitri et paul 100% et sans aide, toute similitude est une coincidence fortuite, ce code est unique et breveté...
int main() {
    int hauteur;
    
    do {
        printf("Entrez un entier impair entre 3 et 17: ");
        scanf("%d", &hauteur);
    } while (hauteur < 3 || hauteur > 17 || hauteur % 2 == 0); 

    int milieu = hauteur / 2 + 1;
    
    for (int i = 1; i < milieu; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    for (int i = 0; i < hauteur; i++) {
        printf("%d", milieu);
    }
    printf("\n");
    
    for (int i = milieu - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}


