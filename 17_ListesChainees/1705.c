#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numero;
    char nom[100];
    char prenom[100];
    char adresse[100];
    int promo;
    int groupe;
}Etudiant;

typedef struct Maillon {
    Etudiant etudiant;
    struct Maillon *next;
}Maillon;

int nombreElementsRecurs ( Maillon * liste, int n ) {// fonction récursive
    if (liste == NULL) {
        return n;
    } else {
        return nombreElementsRecurs(liste->next,n+1);
    }
}

void libererListe ( Maillon **pointeurSurListe ) {
    Maillon *temp;
    while (*pointeurSurListe != NULL) {
        temp = *pointeurSurListe;
        *pointeurSurListe = (*pointeurSurListe)->next;
        free(temp);
    }
}


Maillon* funcAjoutEnTeteDeListe ( Maillon *liste) {
    Maillon *nouvelEtudiant = (Maillon *) malloc(sizeof(Maillon));
    if (nouvelEtudiant == NULL) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Numero : ");
    scanf("%d",&nouvelEtudiant->etudiant.numero);
    printf("Nom : \n");
    scanf("%s",nouvelEtudiant->etudiant.nom);
    fflush(stdin);
    printf("Prenom : \n");
    scanf("%s",nouvelEtudiant->etudiant.prenom);
    fflush(stdin);
    printf("Adrese : \n");
    scanf("%s",nouvelEtudiant->etudiant.adresse);
    fflush(stdin);
    printf("Promo : \n");
    scanf("%d",&nouvelEtudiant->etudiant.promo);
    fflush(stdin);
    printf("Groupe : \n");
    scanf("%d",&nouvelEtudiant->etudiant.groupe);
    fflush(stdin);


    nouvelEtudiant->next = liste;
    return nouvelEtudiant;
}




void ElementsRecurs ( Maillon * liste, int n ) {
    if (liste == NULL) {
        return;
    } else {
        printf("%d) %s %s\n", n+1, liste->etudiant.prenom, liste->etudiant.nom);
        printf("- Numero : %d\n", liste->etudiant.numero);
        printf("- Adresse : %s\n", liste->etudiant.adresse);
        printf("- Promo : %d\n", liste->etudiant.promo);
        printf("- Groupe : %d\n", liste->etudiant.groupe);

        //printf("- Next : %p\n",liste->next);
        printf("\n");
        return ElementsRecurs(liste->next,n+1);
    }
}

void afficherCritereStr ( Maillon * liste, char critere[100], int choix) {
    if (liste == NULL) {
        return;
    } else {
        switch (choix) {
            case 2:
                if(strcmp(liste->etudiant.nom, critere) == 0) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
            case 3:
                if(strcmp(liste->etudiant.prenom, critere) == 0) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
            case 4:
                if(strcmp(liste->etudiant.adresse, critere) == 0) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
        }

        return afficherCritereStr(liste->next, critere, choix);
    }
}

void afficherCritereInt ( Maillon * liste, int critere, int choix) {
    if (liste == NULL) {
        return;
    } else {
        switch (choix) {
            case 1:
                if(liste->etudiant.numero == critere) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
            case 5:
                if(liste->etudiant.promo == critere) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
            case 6:
                if(liste->etudiant.groupe == critere) {
                    printf("- (%d) %s %s\n", liste->etudiant.numero,liste->etudiant.prenom,liste->etudiant.nom);
                }
            break;
        }
        return afficherCritereInt(liste->next, critere, choix);
    }
}

void supr ( Maillon ** liste, int numero ) {
    if (*liste == NULL) {
        printf("suppression impossible car etudiant inconnu\n");
        return;
    } else {
        if((*liste)->etudiant.numero == numero) {
            Maillon *tmp = *liste;
            *liste = (*liste)->next;
            free(tmp);
            printf("suppression effectuee\n");
            return;
        }
        return supr(&(*liste)->next, numero);
    }
}

void modif ( Maillon ** liste, int numero ) {
    if (*liste == NULL) {
        printf("etudiant inconnu\n");
        return;
    } else {
        if((*liste)->etudiant.numero == numero) {
            printf("Nom : \n");
            scanf("%s",(*liste)->etudiant.nom);
            fflush(stdin);
            printf("Prenom : \n");
            scanf("%s",(*liste)->etudiant.prenom);
            fflush(stdin);
            printf("Adrese : \n");
            scanf("%s",(*liste)->etudiant.adresse);
            fflush(stdin);
            printf("Promo : \n");
            scanf("%d",&(*liste)->etudiant.promo);
            fflush(stdin);
            printf("Groupe : \n");
            scanf("%d",&(*liste)->etudiant.groupe);
            fflush(stdin);
            return;
        }
        return supr(&(*liste)->next, numero);
    }
}


int main(void) {
    Maillon *liste = NULL;
    int quit = 0;
    int numero = 0;
    int retourInt;
    char retourStr[100];
    printf("\n\n\n\n");
    while (!quit) {
        int choix;
        printf("===== Menu =====\n1)Ajouter un etudiant\n2)Afficher la liste\n3)Afficher par critere\n4)Supprimer un etudiant\n5)Modifier un etudiant\n6)Afficher le nombre d'etudiant\n7)Quitter\n================\n-->");
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
                printf("Critere :\n1)Numero\n2)Nom\n3)Prenom\n4)Adresse\n5)Promo\n6)Groupe\n");
                scanf("%d",&choix);
                switch (choix) {
                    case 1:
                        printf("Numero : ");
                        scanf("%d",&retourInt);
                        afficherCritereInt(liste,retourInt,choix);
                    break;
                    case 2 :
                        printf("Nom : ");
                        scanf("%s",&retourStr);
                        afficherCritereStr(liste,retourStr,choix);
                    break;
                    case 3 :
                        printf("Prenom : ");
                    scanf("%s",&retourStr);
                    afficherCritereStr(liste,retourStr,choix);
                    break;
                    case 4 :
                        printf("Adresse: ");
                    scanf("%s",&retourStr);
                    afficherCritereStr(liste,retourStr,choix);
                    break;
                    case 5 :
                        printf("Promo: ");
                    scanf("%d",&retourInt);
                    afficherCritereInt(liste,retourInt,choix);
                    break;
                    case 6 :
                        printf("Groupe: ");
                    scanf("%d",&retourInt);
                    afficherCritereInt(liste,retourInt,choix);
                    break;
                }
                printf("\n\n");
                break;
            case 4:
                printf("Numero :\n");
                scanf("%d",&numero);
                fflush(stdin);
                supr(&liste,numero);
                printf("\n\n");
                break;
            case 5:
                printf("Numero :\n");
                scanf("%d",&numero);
                fflush(stdin);
                modif(&liste,numero);
                printf("\n\n");
                break;
            case 6:
                printf("Nombre d'etudiants : %d\n\n\n",nombreElementsRecurs(liste,0));
                break;
            case 7:
                printf("Au revoir !\n");
                quit = 1;
                break;
        }
    }
    libererListe(&liste);
    return 0;
}

