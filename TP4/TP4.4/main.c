#include <stdio.h>
#include "fonction_scanf.h"
#include "fonction_verif_multiple.h"

//Macro:
#define V  10

int main(void) {

    

    int num1, num2, verif, verif3;
    num1 = saisirEntier(num1);
    num2 = saisirEntier(num2);

    verif = fct_verif_multiple(num1, num2);
    if (verif == 1) {
        printf("%d est un multiple de %d.\n", num1, num2);
    }else{printf("%d n'est pas un multiple de %d.\n", num1, num2);}

    verif3 = fct_verif_multiple3(num1);
return 0;
}
