#include <stdio.h>
#include "foncts.h"

int main(void) {
    int n,result,quit=0;

    do {
        printf("\nSaisir un entier :\n");
        scanf("%d", &n);

        switch (menu(n)) {
            case 1:
                result=plus1(n);
                break;
            case 2:
                result=fois2(n);
                break;
            case 3:
                result=moins4(n);
                break;
            case 4:
                result=sommen(n);
                break;
            case 5:
                quit=1;
                break;

        }
        if (quit==0)
            printf("%d\n",result);

    } while (quit==0);

    return 0;
}
