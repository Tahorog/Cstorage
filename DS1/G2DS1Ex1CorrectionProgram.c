#include <stdio.h>
int main() {
    int n, x, reponse, booleen;

    do {
        printf("Enter n positif :");
        scanf("%d", &n);
        printf("Enter x positif :");
        scanf("%d", &x);

        if (x<=0) {
            return 0;
        }
        else if (n<=0) {
            return 0;
        }

        printf("Ecrire somme de n et x");
        scanf("%d", &reponse);
        if (reponse==n+x) {
            printf("Bravo\n");

        } else {
            printf("Bad");
        }

        if (n>x) {
            printf("Est ce que n est un multiple de x (oui : 1 non : 0");
            scanf("%d", &booleen);
        }
        else if (n<x) {
            printf("Est ce que x est un multiple de n (oui : 1 non : 0");
            scanf("%d", &booleen);
        }

        if (n%x == 0 && booleen==1) {
            printf("Bravo\n");

        } else if (n%x == 1 && booleen==0) {
            printf("Bravo\n");
        }
        else {
            printf("Bad\n");
        }
    } while (x > 0 || n > 0);

    return 0;
}
