#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the number n: ");
    scanf("%d", &n);

    while (n % 2 != 0 || n % 7 != 0) {
        printf("Pick another number :");
        scanf("%d", &n);
    }
    return 0;
}
