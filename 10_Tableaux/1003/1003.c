#include <stdio.h>
#include "foncts.h"




int main(void) {
    float tab[TAILLE];
    float moy, max, min;

    remplir(tab);
    show(tab);
    moy=getMoy(tab);
    max=getMax(tab);
    min=getMin(tab);

    printf("moyenne = %f\n",moy);
    printf("maximum = %f\n",max);
    printf("minimum = %f\n",min);

    return 0;
}
