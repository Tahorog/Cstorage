#include <stdio.h>

int main(void) {
    int tableau[13];

    for (int i = 0; i < 13; i++) {
        scanf("%d",tableau + i);
    }
    for (int i = 0; i < 13; i++) {
        printf("%d\n",tableau[i]);
    }
    return 0;
}
