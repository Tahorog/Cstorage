#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5
#define L 10

typedef struct {
    int jour;
    int mois;
    int annee;
}t_date;

typedef struct {
    int id;
    char titre[100];
    char auteurs[5][100];
    char theme[5][100];
    float prix;
    t_date parution;
}t_livre;

t_date get_date() {
    t_date date;
    printf("date de parution\n");
    printf("jour:");
    scanf("%d", &date.jour);
    printf("mois:");
    scanf("%d", &date.mois);
    printf("annee:");
    scanf("%d", &date.annee);
    return date;
}

void get_livre(t_livre *livre) {
    int i=0;
    printf("id:");
    scanf("%d", &livre->id);
    printf("titre:");
    scanf("%s", &livre->titre);
    printf("auteurs (0 to stop):");
    do {
        fflush(stdin);
        scanf("%s", &livre->auteurs[i]);
        i++;

    } while (i<MAX && livre->auteurs[i-1][0]!='0');
    livre->auteurs[i-1][0]='\0';
    i=0;
    printf("theme (0 to stop):");
    do {
        fflush(stdin);
        scanf("%s", &livre->theme[i]);
        i++;
    } while (i<MAX && livre->theme[i-1][0]!='0');
    livre->theme[i-1][0]='\0';
    printf("prix:");
    scanf("%f", &livre->prix);
    livre->parution = get_date();
}

void get_liste(int n,t_livre liste[n]) {
    for(int i=0;i<n;i++) {
        printf("========== %d ==========\n",i);
        get_livre(&liste[i]);
        printf("\n");
    }
}

void show_livre(t_livre livre) {
    printf("id: %d\n",livre.id);
    printf("titre: %s\n",livre.titre);
    printf("auteurs:\n");
    for(int i=0;livre.auteurs[i][0]!='\0';i++) {
        printf("- %s\n",livre.auteurs[i]);
    }
    printf("theme:\n");
    for(int i=0;livre.theme[i][0]!='\0';i++) {
        printf("- %s\n",livre.theme[i]);
    }
    printf("prix: %f\n",livre.prix);
    printf("date de parution :\njours:%d\nmois:%d\nannee:%d\n",livre.parution.jour,livre.parution.mois,livre.parution.annee);
}

void show_liste(int n,t_livre liste[n]) {
    for(int i=0;i<n;i++) {
        printf("========== %d ==========\n",i);
        show_livre(liste[i]);
        printf("\n");
    }
}

void save_liste(char fileName[100],int n,t_livre liste[n]) {
    int nbauteurs=0;
    int nbtheme=0;
    FILE *pf = fopen(fileName,"w");
    if (pf == NULL) {
        printf("File could not be opened\n");
        exit(1);
    }
    printf("Saving...\n");
    for (int i = 0; i < n; i++) {
        fprintf(pf, "%d\n%d\n%s\n%f\n", i, liste[i].id, liste[i].titre, liste[i].prix);
        fprintf(pf,"%d\n%d\n%d\n", liste[i].parution.jour,liste[i].parution.mois, liste[i].parution.annee);
        nbauteurs=0;
        nbtheme=0;
        while (liste[i].auteurs[nbauteurs][0] != '\0') {
            nbauteurs++;
        }
        while (liste[i].theme[nbtheme][0] != '\0') {
            nbtheme++;
        }
        fprintf(pf,"%d\n",nbauteurs);
        for (int j = 0; liste[i].auteurs[j][0]!='\0'; j++) {
            fprintf(pf,"%s\n",liste[i].auteurs[j]);
        }
        fprintf(pf,"%d\n",nbtheme);
        for (int j = 0; j < nbtheme; j++) {
            fprintf(pf,"%s\n",liste[i].theme[j]);
        }
    }
    fclose(pf);
    pf=NULL;
    printf("File saved\n");
}

void load_liste(char fileName[100],t_livre liste[100]) {
    FILE *pf = fopen(fileName,"r");
    if (pf == NULL) {
        printf("File %s could not be opened\n",fileName);
        exit(1);
    }
    int rien;
    int i = 0;
    while (i<MAX && fscanf(pf,"%d",&rien)==1) {
        fscanf(pf,"%d",&liste[i].id);
        fscanf(pf,"%s",&liste[i].titre);
        fscanf(pf,"%f",&liste[i].prix);
        fscanf(pf,"%d",&liste[i].parution.jour);
        fscanf(pf,"%d",&liste[i].parution.mois);
        fscanf(pf,"%d",&liste[i].parution.annee);

        int nbauteurs = 0;
        fscanf(pf,"%d",&nbauteurs);
        for (int j = 0; j < nbauteurs; j++) {
            fscanf(pf,"%d",&liste[i].auteurs[j]);
        }
        int nbtheme = 0;
        fscanf(pf,"%d",&nbtheme);
        for (int j = 0; j < nbtheme; j++) {
            fscanf(pf,"%d",&liste[i].theme[j]);
        }
        i++;
    }
    printf("file loaded\n");
    fclose(pf);
    pf=NULL;
}

void menu(int n, t_livre liste[n]) {
    int quit=0;
    while(!quit) {
        int retour=0;
        do {
            printf("\n===== MENU =====\n");
            printf("1. Input liste\n");
            printf("2. Show liste\n");
            printf("3. Save liste\n");
            printf("4. Load liste\n");
            printf("5. Exit\n");
            printf("================\n->");
            scanf("%d",&retour);
        } while ( !(0<retour && retour<6));
        switch(retour) {
            case 1:
                get_liste(n,liste);
            break;
            case 2:
                show_liste(n,liste);
            break;
            case 3:
                save_liste("../livres.txt",n,liste);
            break;
            case 4:
                load_liste("../livres.txt",liste);
            break;
            case 5:
                quit=1;
            break;
        }
    }
}

int main(void) {
    t_livre liste[L];

    menu(L,liste);

    return 0;
}
