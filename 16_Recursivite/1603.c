#include <stdio.h>
#include <stdlib.h>

int taille(char mot[100], int n) {
    if (mot[n] == '\0') {
        return n;
    }
    n+=1;
    return taille(mot, n);
}

int main(void) {
    char mot[100];
    printf("Entrez un mot :\n");
    scanf("%s", mot);

    printf("Longueur du mot : %d\n",taille(mot,0));
    return 0;
}

