#include <stdio.h>
#include <stdlib.h>

typedef struct Chaine {
    int real;
    struct Chaine *next;
}Chaine;


Chaine* funcAjoutEnTeteDeListe ( Chaine *liste,int real ) {
    Chaine *nouvelleCellule = (Chaine *) malloc(sizeof(Chaine));
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouvelleCellule->real = real;
    nouvelleCellule->next = liste;
    return nouvelleCellule;
}



int ElementNRecurs ( Chaine * liste, int n, int show) {// fonction récursive
    if (n == show) {
        printf("%d) %d\n", n, liste->real);
        return 1;
    }
    if (liste == NULL) {
        return -1;
    } else {
        return ElementNRecurs(liste->next,n+1,show);
    }
}

int ElementsRecurs ( Chaine * liste, int n ) {// fonction récursive
    if (liste == NULL) {
        return n;
    } else {
        printf("%d) %d\n", n, liste->real);
        return ElementsRecurs(liste->next,n+1);
    }
}


int main(void) {
    Chaine *liste = NULL;
    liste = funcAjoutEnTeteDeListe(liste, 10);
    liste = funcAjoutEnTeteDeListe(liste, 20);
    ElementsRecurs(liste,0);
    return 0;
}

