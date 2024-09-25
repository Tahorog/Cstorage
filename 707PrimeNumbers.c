#include <stdio.h>

int est_premier(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int nombre;

    do {
        printf("Entrez un entier positif (> 1): ");
        scanf("%d", &nombre);
    } while (nombre <= 1);

    printf("Les nombres premiers entre 1 et %d sont :\n", nombre);

    for (int i = 2; i <= nombre; i++) {
        if (est_premier(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
