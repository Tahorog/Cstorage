#include <stdio.h>

int main(void)
{
    //Exercice 1

    int Entier1, Entier2;
    printf("Entrez les valeurs de deux entiers : \n");
    scanf("%d", &Entier1);
    scanf("%d", &Entier2);
if(Entier1 > Entier2) {
    printf("le premier entier est superieur.\n");
}
else {
    printf("le deuxieme entier est superieur.\n");
}
return 0;
}
