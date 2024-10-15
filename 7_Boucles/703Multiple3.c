#include <stdio.h>

int main() {
    int n, i;
    do {
        printf("Entrer un entier positif: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Erreur.\n");
        }
    } while (n <= 0);

    printf("On a donc : %d et %d\n", -n, n);
    printf("Les multiples de 3 compris entre ces deux nombres sont :\n");
    printf("====================================\n");
    for (i = -n; i <= n; i++) {
        if (i % 3 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
