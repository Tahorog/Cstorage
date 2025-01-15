#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int jour;
    int mois;
    int annee;
}t_date;

typedef struct Voiture {
    t_date date;
    char immatriculation[10];
    char marque[100];
    char modele[100];
    int vitesseMax;
    char carburant;
    struct Voiture *next;
}Voiture;


Voiture* funcAjoutEnTeteDeListe ( Voiture *liste) {
    Voiture *nouvelleVoiture = (Voiture *) malloc(sizeof(Voiture));
    if (nouvelleVoiture == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Immatriculation : \n");
    scanf("%s",nouvelleVoiture->immatriculation);
    fflush(stdin);
    printf("Marque : \n");
    scanf("%s",nouvelleVoiture->marque);
    fflush(stdin);
    printf("Modele : \n");
    scanf("%s",nouvelleVoiture->modele);
    fflush(stdin);
    printf("Vitesse Maximale : \n");
    scanf("%d",&nouvelleVoiture->vitesseMax);
    fflush(stdin);
    printf("Carburant : \n");
    scanf("%c",&nouvelleVoiture->carburant);
    fflush(stdin);
    printf("=== Date ===\n");
    printf("Jour : \n");
    scanf("%d",&nouvelleVoiture->date.jour);
    fflush(stdin);
    printf("Mois : \n");
    scanf("%d",&nouvelleVoiture->date.mois);
    fflush(stdin);
    printf("Annee : \n");
    scanf("%d",&nouvelleVoiture->date.annee);
    fflush(stdin);

    nouvelleVoiture->next = liste;
    return nouvelleVoiture;
}




void ElementsRecurs ( Voiture * liste, int n ) {
    if (liste == NULL) {
        return;
    } else {
        printf("%d) %s\n", n+1, liste->immatriculation);
        printf("- Marque : %s\n", liste->marque);
        printf("- Modele : %s\n", liste->modele);
        printf("- Vitesse Maximale : %d\n", liste->vitesseMax);
        printf("- Carburant : %c\n", liste->carburant);
        printf("- Date : %d/%d/%d\n",liste->date.jour,liste->date.mois,liste->date.annee);
        //printf("- Next : %p\n",liste->next);
        printf("\n");
        return ElementsRecurs(liste->next,n+1);
    }
}

void afficherMarque ( Voiture * liste, char marque[100] ) {
    if (liste == NULL) {
        return;
    } else {
        if(strcmp(liste->marque, marque) == 0) {
            printf("- %s\n", liste->immatriculation);
        }
        return afficherMarque(liste->next, marque);
    }
}

void libererListe ( Voiture **pointeurSurListe ) {
    Voiture *temp;
    while (*pointeurSurListe != NULL) {
        temp = *pointeurSurListe;
        *pointeurSurListe = (*pointeurSurListe)->next;
        free(temp);
    }
}

void supr ( Voiture ** liste, char imm[100] ) {
    if (*liste == NULL) {
        printf("suppression impossible car voiture inconnue\n");
        return;
    } else {
        if(strcmp((*liste)->immatriculation, imm) == 0) {
            Voiture *tmp = *liste;
            *liste = (*liste)->next;
            free(tmp);
            printf("suppression effectuee\n");
            return;
        }
        return supr(&(*liste)->next, imm);
    }
}

int main(void) {
    Voiture *liste = NULL;
    char marque[100];
    char immatriculation[100];
    int quit = 0;
    printf("\n\n\n\n");
    while (!quit) {
        int choix;
        printf("===== Menu =====\n1)Ajouter une voiture\n2)Afficher la liste\n3)Afficher par marque\n4)Supprimer une voiture\n5)Quitter\n================\n-->");
        scanf("%d",&choix);
        switch (choix) {
            case 1:
                liste = funcAjoutEnTeteDeListe(liste);
                break;
            case 2:
                printf("========== liste ==========\n");
                ElementsRecurs(liste,0);
                printf("\n");
                break;
            case 3:
                printf("Marque :\n");
                scanf("%s",marque);
                printf("===== %s =====\n",marque);
                afficherMarque(liste,marque);
                printf("\n\n");
                break;
            case 4:
                printf("Immatriculation :\n");
                scanf("%s",immatriculation);
                supr(&liste,immatriculation);
                printf("\n\n");
                break;
            case 5:
                printf("Au revoir !\n");
                quit = 1;
                break;
        }
    }
    libererListe(&liste);
    return 0;
}

