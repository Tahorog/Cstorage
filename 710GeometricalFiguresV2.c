#include <stdio.h>

int Triangle(int hauteur) {
    for (int i = 1; i <= hauteur; i++) {
        for (int j = 0; j < hauteur - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int Carre(int hauteur) {
    for (int i = 1; i <= hauteur; i++) {
        for (int j = 1; j <= hauteur; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int Sablier(int hauteur) {
    for (int i = hauteur; i > 0; i--) {
        for (int j = 0; j < hauteur - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 2; i <= hauteur; i++) {
        for (int j = 0; j < hauteur - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int Hauteur() {
    int hauteur;
    do {
        printf("Entrer la hauteur : ");
        if (scanf("%d", &hauteur) != 1) {
            printf("Erreur.\n");
        } else if (hauteur <= 0) {
            printf("La hauteur doit etre superieure a 0.\n");
        }
    } while (hauteur <= 0);
    return hauteur;
}

int main() {
    int choix, hauteur;

    do {
        printf("Menu\n");
        printf("1)Triangle\n");
        printf("2)Carre\n");
        printf("3)Sablier\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                hauteur = Hauteur();
                Triangle(hauteur);
                break;
            case 2:
                hauteur = Hauteur();
                Carre(hauteur);
                break;
            case 3:
                hauteur = Hauteur();
                Sablier(hauteur);
                break;
            default:
                printf("Veuillez reessayer.\n");
                break;
        }
    } while (choix != 3);

    return 0;
}

