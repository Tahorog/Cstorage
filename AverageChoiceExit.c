#include <stdio.h>

int main() {
    int nombre, count;
    float somme;
    int choix;

    do {
        somme = 0;
        count = 0;

        while (1) {
            printf("Entrez un nombre entier positif (ou un nombre negatif pour arreter) : ");
            scanf("%d", &nombre);

            if (nombre < 0) {
                break;
            }

            somme += nombre;
            count++;
        }

        if (count > 0) {
            printf("Nombre de valeurs positives : %d\n", count);
            printf("Moyenne : %f\n", somme / count);
        } else {
            printf("Aucune valeur positive saisie.\n");
        }

        printf("Voulez-vous quitter le programme ? (oui = 1 / non = 0) : ");
        scanf(" %d", &choix);

    } while (choix != 1);

    return 0;
}
