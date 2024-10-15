#include "exos.h"

#include <stdio.h>

int parametre(int x1, int x2) {
    printf("x1 = %d\nx2 = %d\n", x1, x2);
    x1 = x1 + 10;
    printf("x1 = %d\nx2 = %d\n", x1, x2);
    return x1, x2;
}
