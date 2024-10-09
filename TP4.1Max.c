#include <stdio.h>
int getMax() {
    int d, c;
    printf("Enter c :");
    scanf("%d", &c);
    printf("Enter d :");
    scanf("%d", &d);

    if (d > c) {
        return d;

    }
    else {
        return c;
    }
}

int main() {
    int a, b, max;
    printf("Enter a :");
    scanf("%d", &a);
    printf("Enter b :");
    scanf("%d", &b);

    max = getMax();
    printf("The max is %d", max);
    return max;
}
