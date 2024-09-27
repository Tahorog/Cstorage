      //Exercice 601
 //Le programme permettant de déterminer si une valeur saisie est multiple de 5, et, supérieure ou égale à -3 ?

#include <stdio.h>

int main(void) {
       int entier1;
       printf("Entrez un entier : \n");
       scanf("%d", &entier1);
       if (entier1 % 5 ==0 && entier1 > -3) {
           printf("L'entier saisi est un multiple de 5 et est superieur a -3. \n");
       }
       else if (entier1 % 5 == 0 && entier1 < -3) {
           printf("L'entier saisi est un multiple de 5 mais est inferieur a -3. \n");
       }
       else if (entier1 % 5 != 0 && entier1 > -3) {
           printf("L'entier saisi n'est pas un multiple de 5 mais est superieur a -3.\n");
       }
       else if (entier1 == -3) {
           printf("L'entier saisi n'est pas un multiple de 5 mais est egale a -3.\n");
       }
       else {
           printf("L'entier saisi n'est pas un multiple de 5 et est inferieur a -3.\n");
       }
}
