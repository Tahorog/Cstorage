#include "foncts.h"
#include "stdio.h"
#define TAILLE 10

void remplir(float tab[TAILLE]) {
    for (int i=0;i<TAILLE;i++)
        scanf("%f",&tab[i]);
}

void show(float tab[TAILLE]) {
    for (int i=0;i<TAILLE;i++)
        printf("%f\n",tab[i]);
}

float getMoy(float tab[TAILLE]) {
    float moy=0;
    for (int i=0;i<TAILLE;i++)
        moy+=tab[i];
    moy/=TAILLE;
    return moy;
}
float getMax(float tab[TAILLE]) {
    float max=0;
    for (int i=0;i<TAILLE;i++) {
        if (tab[i]>max)
            max=tab[i];
    }
    return max;
}

float getMin(float tab[TAILLE]) {
    float min=20;
    for (int i=0;i<TAILLE;i++) {
        if (tab[i]<min)
            min=tab[i];
    }
    return min;
}
