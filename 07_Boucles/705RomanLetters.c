#include <stdio.h>

int main(void) {
    int A;
    printf("A?");
    scanf("%d", &A);

    while (A>=1000) {
        printf("M");
        A-=1000;
    }
    while (A>=500) {
        printf("D");
        A-=500;
    }
    while (A>=100) {
        printf("C");
        A-=100;
    }
    while (A>=50) {
        printf("L");
        A-=50;
    }
    while (A>=10) {
        printf("X");
        A-=10;
    }
    while (A>=5) {
        printf("V");
        A-=5;
    }
    while (A>=1) {
        printf("l");
        A-=1;
    }
    return 0;
}
