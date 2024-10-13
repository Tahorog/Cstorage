#include <stdio.h>
#include <unistd.h>
#include "Fonctions_horloge.h"


int main(void) {
    int minutes = 0, heures = 0, minutefin, heurefin, matin, HeureM=0;
    char Demijournee;

    do {
        printf("Est-ce le matin?\n1)OUI\n2)NON\n");
        scanf("%d", &matin);
    } while (matin<1 || matin>2);

    printf("Entrez l'heure de debut : ");
    scanf("%d", &heures);
    printf("Entrez la minute de debut :");
    scanf("%d", &minutes);
    printf("Entrez l'heure de fin :");
    scanf("%d", &heurefin);
    printf("Entrez la minute de fin :");
    scanf("%d", &minutefin);

    if (matin == 1) {
        Demijournee = 'A';
    }else {
        Demijournee = 'P';
    }

    while (heures != heurefin || minutes != minutefin) {
        if (Demijournee == 'P' && heures >= 12) {
            HeureM = heures -12;
        }else {
            HeureM = heures;
        }
        printf("%d h (%cM) %d min\n", HeureM, Demijournee, minutes);
        minutes = horlogeminute(minutes);
        heures = horlogeheure(minutes, heures);
        Demijournee = horlogeDemijournee(heures, Demijournee);
        sleep(1);
        //Pour obtenir une horloge fonctionnel avec la vraie échelle de temps, il faut remplacer sleep(1) par sleep(60)
    }
    printf("%d h (%cM) %d min\n", HeureM, Demijournee, minutes);


}

