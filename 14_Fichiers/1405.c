#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    int id;
    char name[100];
    char realisator[100];
    int date;
    char genre[100];
}t_film;

void save_film(char fileName[100],int n,t_film liste[n]) {
    FILE *pf = fopen(fileName,"w");
    if (pf == NULL) {
        printf("File could not be opened\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(pf,"%d\n%d\n%s\n%s\n%d\n%s",i,liste[i].id,liste[i].name,liste[i].realisator,liste[i].date,liste[i].genre);
    }
    fclose(pf);
    pf=NULL;
    printf("File saved\n");
}

void load_film(char fileName[100],t_film liste[100]) {
    FILE *pf = fopen(fileName,"r");
    if (pf == NULL) {
        printf("File %s could not be opened\n",fileName);
        exit(1);
    }
    int rien;
    int i = 0;
    while (i<MAX && fscanf(pf,"%d",&rien)==1) {
        printf("boucle : %d\n",i);
        fscanf(pf,"%d",&liste[i].id);
        fscanf(pf,"%s",&liste[i].name);
        fscanf(pf,"%s",&liste[i].realisator);
        fscanf(pf,"%d",&liste[i].date);
        fscanf(pf,"%s",&liste[i].genre);
        i++;
    }
    printf("film loaded\n");
    fclose(pf);
    pf=NULL;
}

void show_film(t_film film) {
    printf("id : %d\n",film.id);
    printf("name : %s\n",film.name);
    printf("realisator : %s\n",film.realisator);
    printf("date : %d\n",film.date);
    printf("genre : %s\n",film.genre);
}

void show_liste(int n,t_film liste[n]) {
    for (int i = 0; i < n; i++) {
        printf("========== %d ==========\n",i);
        show_film(liste[i]);
        printf("\n");
    }
}

t_film get_film() {
    t_film film;
    printf("Enter id : ");
    scanf("%d",&film.id);
    printf("Enter name : ");
    scanf("%s",&film.name);
    printf("Enter realisator : ");
    scanf("%s",&film.realisator);
    printf("Enter date : ");
    scanf("%d",&film.date);
    printf("Enter genre : ");
    scanf("%s",&film.genre);
    return film;
}

void add_to_liste(int d,int n,t_film liste[n]) {
    for (int i = d; i < d+n; i++) {
        printf("========== %d ==========\n",i);
        liste[i]=get_film();
        printf("\n");
    }
}


void init_liste(int n,t_film liste[n]) {
    for (int i = 0; i < n; i++) {
        liste[i].id = -1;
    }
}

int main(void) {
    t_film liste[MAX];
    char fileName[100];
    init_liste(10,liste);
    printf("FilePath ?");
    scanf("%s",fileName);
    fflush(stdin);
    fileName[strlen(fileName)]='\0';
    load_film(fileName,liste);
    show_liste(10,liste);
    add_to_liste(10,2,liste);
    fflush(stdin);
    printf("FilePath ?");
    scanf("%s",fileName);
    fileName[strlen(fileName)]='\0';
    save_film(fileName,12,liste);

    return 0;
}
