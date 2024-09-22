#include <stdio.h>

int main() {
    int n;  // Variable pour stocker le nombre d'affichages

    // Boucle do...while pour garantir que le nombre est positif
    do {
        printf("Veuillez entrer un nombre positif d'affichages : ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Le nombre doit être positif. Veuillez réessayer.\n");
        }
    } while (n <= 0);  // Continue tant que le nombre est inférieur ou égal à 0

    // Boucle for pour afficher la chaine le nombre de fois demandé
    for (int i = 1; i <= n; i++) {
        printf("Bienvenue en TP : indice %d\n", i);
    }

    return 0;
}
