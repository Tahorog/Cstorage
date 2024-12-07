#include <stdio.h>

//Macro :
#define V 10

int fct_verif_multiple(int num1, int num2){
  int verif;
  if(num1 % num2 ==1 ){
    verif = 1;
   }else{verif=0;}
 return verif;
}

int fct_verif_multiple3(int num1) {
    int verif3, num2;
    num2 = 3;
    verif3 = fct_verif_multiple(num1, num2);
    if(verif3 == 1) {
        printf("%d est un multiple de 3\n", num1);
    }else{printf("%d n'est pas un multiple de 3\n", num1);}

    if(num1 > V) {
        printf("%d est superieur a 10\n");
    }else{printf("%d n'est pas un superieur a 10\n", num1);}
    return num1;
}
