 //Exercice 708
#include <stdio.h>

int main(void) {
       int u0 = 3, n = 0;
       printf("Entrez un entier n : \n");
       scanf("%d", &n);

       for (int i = 1; i <= n; i++) {
           u0 = u0*3 + 4;
       }
       printf("U%d = %d", n, u0);
  return 0;
}
