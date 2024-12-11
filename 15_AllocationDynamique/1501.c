#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * truc() {
    char phrase1[100];
    char phrase2[100];
    int longueur =0;
    printf("Enter Phrase: ");
    fgets(phrase1,100,stdin);
    longueur = strlen(phrase1);
    phrase1[longueur-1] = '\0';
    printf("Enter Phrase: ");
    fgets(phrase2,100,stdin);
    longueur += strlen(phrase2);

    char *retour = (char*)malloc(longueur * sizeof(char)+3);
    strcpy(retour, phrase1);
    strcat(retour, " ");
    strcat(retour, phrase2);
    return retour;
}


int main(void) {

    char *phrase = truc();

    printf("%s", phrase);

    free(phrase);
    return 0;
}
