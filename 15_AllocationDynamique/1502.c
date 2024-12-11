#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Fonction de comparaison pour qsort
int comparer(const void *a, const void *b) { // a et b des pointeurs génériques (car on utilise qsort
    char *chaineA = *(char**)a;// conversion implicite vers char
    char *chaineB = *(char**)b;//idem
    return strcmp(chaineA, chaineB); //renvoie à q sort le resultat de la comparaison (type bool
}

int main(void) {
    char **liste = (char**)malloc(MAX * sizeof(char*));
    char mot[100];
    int tailleTot =0;
    char *unePhrase = NULL;

    for (int i = 0; i < MAX; i++) {
        printf("%d Entrer un mot : ", i + 1);
        scanf("%s", mot);// recupere le mot
        liste[i] = (char*)malloc((strlen(mot) + 1) * sizeof(char));//alloue de la memeoire pour mot
        strcpy(liste[i], mot); // enregistre dans l'espace alloue
        tailleTot += strlen(liste[i]) + 1;
    }

    // comparaison avec qsort, les regles de comparaisons sont gérés par la fonction comparer
    qsort(liste, MAX, sizeof(char*), comparer);

    unePhrase = (char*)malloc(tailleTot * sizeof(char));
    unePhrase[0] = '\0'; // pour pouvoir ajouter apres avec strcat

    // Copie les mots dans unePhrase, libère tableau
    for (int i = 0; i < MAX; i++) {
        strcat(unePhrase, liste[i]); // ajout du mot à unePhrase
        if (i < MAX - 1) {
            strcat(unePhrase, " "); // ajoute un espace sauf pour le dernier mot
        } else {
            strcat(unePhrase, "."); // ajoute un point final
        }
        free(liste[i]); // libère la memoire utilisé par l'element de la liste
    }
    free(liste); // libère la memoire utilisé par liste

    // Affichage de la phrase complète
    printf("\nLa phrase finale est : \n%s\n", unePhrase);

    free(unePhrase); // libère la memoire utilisé par unePhrase
    return 0;
}
