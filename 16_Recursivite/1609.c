#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX 100

void showListe(int liste[MAX],char lettre) {
    int i =0;
    printf("%c) ",lettre);
    while (liste[i]!=0) {
        printf("%d ",liste[i]);
        i++;
    }
    printf("\n\n");
}

void show(int A[MAX],int B[MAX], int C[MAX]) {
    showListe(A,'A');
    showListe(B,'B');
    showListe(C,'C');
}

void deplace(int n,int depart[MAX],int * tD, int inter[MAX], int * tI, int arrive[MAX], int * tA) {
    if (n==0) return;
    if (n==1) {
        arrive[*tA] = depart[*tD-1];
        depart[*tD-1] = 0;
        *tA=*tA+1;
        *tD=*tD-1;
        return;
    }
    deplace(n-1,depart,tD,arrive, tA,inter, tI);
    deplace(1,depart, tD ,inter, tI ,arrive, tA);
    deplace(n-1,inter, tI,depart, tD,arrive, tA);
}

int main(void) {
    struct timespec start, end;
    int A[MAX]={0}, B[MAX]={0}, C[MAX]={0};
    int tA=0, tB=0, tC=0, n;

    printf("Nombre de disques: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) // initialisation de A
        A[i] = n - i;
    tA=n;

    show(A, B, C);

    printf("Traitement...\n");
    clock_gettime(CLOCK_REALTIME, &start);
    deplace(n, A,&tA, B,&tB, C,&tC);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Done :)\n\n");
    show(A, B, C);

    printf("STATS :\n- Mouvements : %.0f\n- Temps : %fs\n\n\n",pow(2,n)-1,(end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)/1e9);
    return 0;
}

