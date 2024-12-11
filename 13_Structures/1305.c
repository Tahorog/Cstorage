#include <stdio.h>

#define N 20

typedef struct {
    int jour;
    int mois;
    int annee;
}t_date;

typedef struct {
    int numero;
    int categorie;
    t_date date;
    int stock;
    float price;
} t_article;

t_date get_date() {
    t_date date;
    printf("date de peremption\n");
    printf("jour:");
    scanf("%d", &date.jour);
    printf("mois:");
    scanf("%d", &date.mois);
    printf("annee:");
    scanf("%d", &date.annee);
}

t_article remplir() {
    t_article article;
    printf("numero de designation: ");
    scanf("%d", &article.numero);
    printf("categorie: ");
    scanf("%d", &article.categorie);
    article.date= get_date();
    printf("stock");
    scanf("%d", &article.stock);
    printf("price");
    scanf("%f", &article.price);
    return article;
}

void show_article(t_article article) {
    printf("numero de designation: %d\n", article.numero);
    printf("categorie: %d\n", article.categorie);
    printf("date de peremption :\njours:%d\nmois:%d\nannee:%d\n",article.date.jour,article.date.mois,article.date.annee);
    printf("stock: %d\n",article.stock);
    printf("price: %f\n",article.price);
}

void show_liste(int n,t_article liste[n]) {
    for (int i = 0; i < n; i++) {
        printf("========== %d ==========\n",i);
        show_article(liste[i]);
        printf("\n");
    }
}

void remplir_liste(int n, t_article liste[n]) {
    for (int i=0; i<n; i++) {
        printf("========== %d ==========\n",i);
        liste[i] = remplir();
        printf("\n");
    }
}

void find_categorie(int n, t_article liste[n],int categorie) {
    for (int i = 0; i < n; i++) {
        if (liste[i].categorie == categorie) {
            show_article(liste[i]);
        }
    }
}

int find_expired(int n,t_article liste[n],t_date date) {
    int expired=0;
    for (int i = 0; i < n; i++) {
        if (liste[i].date.annee > date.annee){
            expired++;
        }
        else if (liste[i].date.annee == date.annee) {
            if (liste[i].date.mois > date.mois) {
                expired++;
            }
            else if (liste[i].date.mois == date.mois) {
                if (liste[i].date.jour > date.jour) {
                    expired++;
                }
            }
        }

    }
    return expired;
}

int main(void) {
    t_article liste[N];
    t_date date;
    int categorie;

    remplir_liste(N,liste);
    show_liste(N,liste);

    printf("===============\n");
    printf("Categorie:");
    scanf("%d",&categorie);

    date = get_date();
    find_expired(N,liste,date);

    return 0;
}
