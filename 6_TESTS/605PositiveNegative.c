#include <stdio.h>

int main(void) {
    int n;
    printf("Entrer un nombre :");
    scanf("%d", &n);

    if (n > 0) {
        printf("Le nombre est positif");
    }
    else if (n = 0) {
        printf("Le nombre est nul");
    }
    else {
        printf("Le nombre est negatif");
    }
    return 0;
}
