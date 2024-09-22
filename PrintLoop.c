#include <stdio.h>

int main() {
    int n;  

    do {
        printf("Veuillez entrer un nombre positif d'affichages : ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Le nombre doit être positif. Veuillez réessayer.\n");
        }
    } while (n <= 0);  

    for (int i = 1; i <= n; i++) {
        printf("Bienvenue en TP : indice %d\n", i);
    }

    return 0;
}
