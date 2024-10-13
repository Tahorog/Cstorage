#include <stdio.h>

int main(void)
{
    /*Exercice 502*/
    float Nlv, Nf, Nm, Np, moyenneG, moyenneL, moyenneS;
    do {
        printf("entrez la note de langue vivante");
        scanf("%f", &Nlv);
    } while (Nlv < 0 || Nlv > 20);
    do {
        printf("entrez la note de français");
        scanf("%f", &Nf);
    } while (Nf < 0 || Nf > 20);
    do {printf("entrez la note de mathématique");
    scanf("%f", &Nm);

    } while (Nm < 0 || Nm > 20);
    do {printf("entrez la note de physique");
    scanf("%f", &Np);

    } while (Np< 0 || Np > 20);

    moyenneG = (Nlv + Nf + Nm + Np) / 4;
    if (moyenneG > 10) {
        printf ("La moyenne est superieure à 10");
    }
    if (Nf>moyenneG && Nm > moyenneG ) {
        printf("Les notes de mathématiques et de français sont supérieures à la moyenne des quatre notes");
        
    }
    if (Nlv > 10 || Nf > 10 || Nm > 10 || Np > 10) {
        printf("Il y a au moins une note supérieure à 10");
    }
    if (Nlv > 10 && Nf > 10 && Nm > 10 && Np > 10) {
        printf("Toutes les notes sont superieurs à 10");

    }
    moyenneS = (Nm + Np)/2;
    moyenneL = (Nlv + Nf)/2;

    if (moyenneL == 10 || moyenneS == 10) {
        printf("La moyenne (10) est obtenue pour l’un des deux types (littéraire et scientifique)");
        
    }
    if (moyenneG >= 10 && moyenneL == 10 || moyenneS == 10) {
        printf("La moyenne des quatre notes, moyenneG, est supérieure ou égale à 10 et la moyenne (10) est obtenue pour l’un des deux types");

        
    }

    return 0;
}
