#include <stdio.h>
#include <unistd.h>
#include "foncts.h"

int main(void) {
    int h=0,m=0;

    while(1) {
        printf("%dh%d\n",h,m);
        sleep(60);
        m=updatem(m);
        h=updateh(m,h);
    }
    return 0;
}
