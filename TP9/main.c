#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    float moyenne; // sur 20
}Moyenne;

void ajoutEnFinDeTableau ( Moyenne **promo,int *nbMoyennes,const char *nom,float moyenne ) {
    (*nbMoyennes)++;
    *promo = (Moyenne *) realloc (*promo, (*nbMoyennes)*sizeof(Moyenne));

    if (*promo == NULL) {
        fprintf(stderr, "Erreur : échec de la réallocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    (*promo)[(*nbMoyennes) - 1].moyenne = moyenne;
    strcpy((*promo)[(*nbMoyennes) - 1].name, nom);
}


void ajoutEnDebutDeTableau ( Moyenne **promo,int *nbMoyennes,const char *nom,float moyenne ) {
    (*nbMoyennes)++;
    *promo = (Moyenne *) realloc (*promo, (*nbMoyennes)*sizeof(Moyenne));

    if (*promo == NULL) {
        fprintf(stderr, "Erreur : échec de la réallocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    // décaller
    for (int i = *nbMoyennes - 1; i > 0; i--) {
        (*promo)[i].moyenne = (*promo)[i-1].moyenne;
        strcpy((*promo)[i].name, (*promo)[i-1].name);
    }

    // ajouter
    (*promo)[0].moyenne = moyenne;
    strcpy((*promo)[0].name, nom);
}
void afficherTableau ( Moyenne* promo, int size ) {
    printf("* Tableau :\n");
    for (int i = 0; i < size; i++) {
        printf("- %s a %0.2f/20 de moyenne\n",promo[i].name,promo[i].moyenne);
    }
}

//===============================================================================================
typedef struct Cellule{
    char name[100];
    float moyenne;
    struct Cellule *next;

}Cellule;

Cellule* funcAjoutEnTeteDeListe ( Cellule *liste,const char *nom,float moyenne ) {
    Cellule *nouvelleCellule = (Cellule *) malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nouvelleCellule->name, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->next = liste;
    return nouvelleCellule;
}

void procAjoutEnTeteDeListe ( Cellule **liste,const char *nom,float moyenne ) {
    Cellule *nouvelleCellule = (Cellule *) malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nouvelleCellule->name, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->next = *liste;
    *liste = nouvelleCellule;
}

Cellule* funcAjoutEnFinDeListe ( Cellule *liste,const char *nom,float moyenne ) {
    Cellule *nouvelleCellule = (Cellule *) malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nouvelleCellule->name, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->next = NULL;

    if (liste == NULL) {
        return nouvelleCellule;
    }

    Cellule *temp = liste; // parcours de la liste
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nouvelleCellule;

    return liste;
}

void procAjoutEnFinDeListe ( Cellule **liste,const char *nom,float moyenne ) {
    Cellule *nouvelleCellule = (Cellule *) malloc(sizeof(Cellule));
    if (nouvelleCellule == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nouvelleCellule->name, nom);
    nouvelleCellule->moyenne = moyenne;
    nouvelleCellule->next = NULL;

    if (*liste == NULL) {
        return;
    }

    Cellule *temp = *liste; // parcours de la liste
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nouvelleCellule;
}

void afficherListeAvecWhile ( Cellule *liste ) {
    printf("* Liste affichee avec While :\n");
    Cellule *temp = liste;
    while (temp != NULL) {
        printf("- %s a %0.2f/20 de moyenne\n", temp->name, temp->moyenne);
        temp = temp->next;
    }
    printf("\n");
}

void afficherListeAvecFor ( Cellule *liste ) {
    printf("* Liste affichee avec For :\n");
    for (Cellule *temp = liste; temp != NULL; temp = temp->next) {
        printf("- %s a %.2f/20 de moyenne\n", temp->name, temp->moyenne);
    }
    printf("\n");
}

void libererListe ( Cellule **pointeurSurListe ) {
    Cellule *temp;
    while (*pointeurSurListe != NULL) {
        temp = *pointeurSurListe;
        *pointeurSurListe = (*pointeurSurListe)->next;
        free(temp);
    }
}

int nombreElementsWhile ( Cellule * liste ) {// fonction non récursive
    int n = 0;
    Cellule *temp = liste;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    return n;
}


int nombreElementsRecurs ( Cellule * liste, int n ) {// fonction récursive
    if (liste == NULL) {
        return n;
    } else {
        return nombreElementsRecurs(liste->next,n+1);
    }
}

//===============================================================================================

int main() {
    printf("\n********* Tableau dynamique *********\n\n");
    Moyenne *promo = NULL;
    int nbMoyennes = 0;
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Toto", 12.4);
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Tata", 10.4);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Tutu", 15.32);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Titi", 16.0);
    afficherTableau(promo, nbMoyennes);
    free(promo);

    printf("\n\n********* Liste simplement chainee *********\n\n");
    Cellule *liste = NULL;
    liste = funcAjoutEnTeteDeListe(liste, "Toto", 12.4);
    procAjoutEnTeteDeListe(&liste, "Tata", 10.4);
    liste = funcAjoutEnFinDeListe(liste, "Tutu", 15.32);
    procAjoutEnFinDeListe(&liste, "Titi", 16.0);
    printf("Il y a %d cellules dans la liste chainee.(sans recursivite)\n\n",nombreElementsWhile(liste));
    printf("Il y a %d cellules dans la liste chainee.(avec recursivite)\n\n",nombreElementsRecurs(liste,0));
    afficherListeAvecWhile(liste);
    afficherListeAvecFor(liste);
    libererListe(&liste);
    return 0;
}
