// Ceci est une proposition de correction non officielle,
// N'hésitez pas a reporter les bugs ou erreurs, ou à demander de l'aide sur discord

// Pas encore commenté déso 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE 40

typedef struct {
    float *notes;
    int taille;
    char nom[41];
    float moy;
} Etudiant;

float * allouer_notes(int * taille) {
    do {
        printf("Nombre de notes: ");
        scanf("%d", taille);
    } while (!(*taille>=5 && *taille<=20));

    float * notes = (float *) malloc(*taille * sizeof(float));

    if (!notes) {
        printf("Erreur allocation memoire\n");
        exit(-1);
    }

    return notes;
}

void remplir_notes(int taille, float tab[taille]) {
    for (int i = 0; i < taille; i++) {
        tab[i] = rand() %20 + rand() %100 /100.0;
    }
}

void completer_etudiant(Etudiant * etudiant) {
    etudiant->notes=allouer_notes(&etudiant->taille);
    remplir_notes(etudiant->taille, etudiant->notes);

    fflush(stdin);
    do {
        printf("Nom de l'etudiant ?");
        fgets(etudiant->nom, 40, stdin);
    } while (etudiant->nom[0]=='\0');
    etudiant->nom[strlen(etudiant->nom)-1] = '\0';

    etudiant->moy=0;
    for (int i = 0; i < etudiant->taille; i++) {
        etudiant->moy += etudiant->notes[i];
    }
    etudiant->moy /= (float)(etudiant->taille);

    printf("\n%s\nnotes (%d) :\n", etudiant->nom,etudiant->taille);
    for (int i = 0; i < etudiant->taille; i++) {
        printf("- %.2f\n", etudiant->notes[i]);
    }
    printf("Moyenne: %.2f\n\n", etudiant->moy);
}


void sauvegarder_etudiant(Etudiant tab[TAILLE]) {
    FILE *pf = fopen("etudiant.txt", "w");

    if (pf == NULL) {
        printf("Erreur ouverture fichier\n");
        exit(-1);
    }

    for (int i = 0; i < TAILLE; i++) {
        fprintf(pf, "%s\n", tab[i].nom);
        fprintf(pf, "%d\n", tab[i].taille);
        for (int j = 0; j < tab[i].taille; j++) {
            fprintf(pf, "%.2f\n", tab[i].notes[j]);
        }
        fprintf(pf,"%.2f\n\n", tab[i].moy);
    }
}

int main() {
    srand(time(NULL));
    Etudiant tab[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        completer_etudiant(&tab[i]);
    }
    sauvegarder_etudiant(tab);

    for (int i = 0; i < TAILLE; i++) {
        free(tab[i].notes);
    }

    return 0;
}




// Arthur Picard 31/01/2025
