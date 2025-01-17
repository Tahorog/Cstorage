#include <stdio.h>
#include <stdlib.h>

int puissance(int n, int p) {
    if (p == 0) {
        return 1;
    }
    p-=1;
    return puissance(n,p)*n;
}

int main(void) {
    int n =0 ,p=0;
    printf("Entrez un nombre :\n");
    scanf("%d", &n);
    printf("Entrez une puissance :\n");
    scanf("%d", &p);

    printf("%d^%d = %d\n",n,p,puissance(n,p));
    return 0;
}

