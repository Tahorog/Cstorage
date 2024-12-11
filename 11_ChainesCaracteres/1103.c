#include <stdio.h>

void getMot(char mot[100]) {
    printf("Mot :\n");
    fgets(mot, 100, stdin);
}

int count(char mot[100]) {
    int i = 0;
    int count = 0;
    do {
        if ((mot[i] >=97 && mot[i] <=122)||(mot[i] >=48 && mot[i] <=57))
            count++;
        i++;
    } while (!(mot[i] == '\0' || mot[i] == '\n'));
    return count;
}

int countMots(char mot[100]) {
    int i = 0;
    int count = 1;
    do {
        if (mot[i] ==' ' && mot[i+1]!=' ' && mot[i+1] != '\n' && mot[i+1] != '\0')
            count++;
        i++;
    } while (!(mot[i] == '\0' || mot[i] == '\n'));
    return count;
}


int main(void) {
    char mot[100];
    getMot(mot);
    printf("%s\nNombre de minuscules et de chiffres : %d\nNombre de mots : %d", mot, count(mot),countMots(mot));

    return 0;
}
