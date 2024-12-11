#include <stdio.h>
#include "foncts.h"

int main(void) {
    int a = 1,b = 2,sum;
    somme(a,b,&sum);
    printf("a: %d, b: %d, a+b = %d",a,b,sum);
    return 0;
}

