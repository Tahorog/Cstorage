#include <stdio.h>


struct nombreRationnel {
    int numerator, denominator;
};

struct nombreRationnel multiplication(struct nombreRationnel a, struct nombreRationnel b) {
    struct nombreRationnel result;

    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;

    return result;
}

struct nombreRationnel addition(struct nombreRationnel a, struct nombreRationnel b) {
    struct nombreRationnel result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}


struct nombreRationnel saisie(void) {
    struct nombreRationnel result;
    scanf("%d", &result.numerator);
    scanf("%d", &result.denominator);
    return result;
}

void affichage(struct nombreRationnel a) {
    printf("%d/%d", a.numerator, a.denominator);
}

int main(void) {
    struct nombreRationnel r1, r2;
    r1 = saisie();
    r2 = saisie();

    affichage(r1);
    printf("+");
    affichage(r2);
    printf("=");
    affichage(addition(r1, r2));
    printf("\n");

    affichage(r1);
    printf("*");
    affichage(r2);
    printf("=");
    affichage(multiplication(r1, r2));
    printf("\n");


    return 0;
}
