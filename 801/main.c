#include <stdio.h>
#include "foncts.h"


int main(void) {
    int a,b;
    printf("Please enter two numbers a and b\n");
    scanf("%d%d", &a,&b);

    printf("%d^2=%d\n%d^2=%d\n",a,carre(a),b,carre(b));


    return 0;
}
