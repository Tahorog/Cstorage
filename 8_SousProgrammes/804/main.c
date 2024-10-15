#include <stdio.h>
#include "exos.h"
int main() {
    int val1, val2;
    printf("Val1 : ");
    scanf("%d", &val1);
    printf("Val2 : ");
    scanf("%d", &val2);

    printf("Val1 : %d, Val2 : %d\n", val1, val2);

    parametre(val1, val2);
    return 0;
}
