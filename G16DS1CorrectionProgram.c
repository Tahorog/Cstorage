#include <stdio.h>
int main() {
    int longueur, hauteur = 3;

    do {
        printf("Longueur = ", longueur);
        scanf("%d", &longueur);
    } while (longueur %4 && 8<=longueur<=36);

    while (longueur >= 4) {
        for (int i = 1; i <= hauteur; i++) {
            for (int j = 1; j <= longueur; j++) {
                printf("*");
            }
            printf("\n");
        }
        longueur -= 4;
    }
    return 0;
}
