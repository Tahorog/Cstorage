#include <stdio.h>

int plus1(int a) {
    return a + 1;
}

int fois2(int a) {
    return a * 2;
}

int moins4(int a) {
    return a - 4;
}
int sommen(int a) {
    int S =0;
    for(int i=0;i<=a;i++)
        S+=i;
    return S;
}

int menu(int n) {
    int choix = 0;
    do {
        printf("Choisir dans le Menu :\n1-Ajouter 1\n2-Fois 2\n3-Moins 4\n4-Somme de %d premiers entiers\n5-Quitter\n",n);
        scanf("%d", &choix);
    } while (choix<1 || choix>5);
    return choix;
    }
