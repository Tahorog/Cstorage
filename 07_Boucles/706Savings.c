#include <stdio.h>

int main() {
    double somme_initiale = 30.0;
    double taux = 0.003;
    int mois;
    double somme_finale = somme_initiale;

    printf("Entrez le nombre de mois: ");
    scanf("%d", &mois);

    for (int i = 1; i <= mois; i++) {
        somme_finale += somme_finale * taux;
    }

    printf("Le solde de votre épargne au bout de %d mois est: %f€\n", mois, somme_finale);

    return 0;
}
