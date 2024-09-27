//Exercice 602
#include <stdio.h>

int main(void) {
       int entier_1, entier_2, entier_3;
       printf("Entrez trois entiers : \n");
       scanf("%d %d %d", &entier_1, &entier_2, &entier_3);
       if (entier_1 == entier_2 == entier_3) {
           printf("Tous les entiers saisis sont identiques.\n");
       }
       else if ((entier_1 == entier_2 && entier_3 != entier_1) || (entier_3 == entier_1 && entier_2 != entier_1)) {
           printf("Seuls deux des trois entiers sont identiques.\n");
       }
       else {
           printf("Tous les entiers saisis sont differents.\n");
       }
return 0;
}
