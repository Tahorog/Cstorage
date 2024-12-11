#include <stdio.h>

int count(char mot[100]) {
    int i = 0;
    do {
        i++;
    } while (!(mot[i] == '\0' || mot[i] == '\n'));
    return i;
}

int main(void) {
    char mot[100];
    char phrase[100];

    printf("1. mot :");
    scanf("%s",mot);

    fflush(stdin);
    printf("2. phrase :");
    fgets(phrase,100,stdin);

    printf("1. mot :\n%s\nLongueur : %d\n\n",mot,count(mot));

    printf("2. phrase :\n%sLongueur : %d\n\n",phrase,count(phrase));

    return 0;
}
