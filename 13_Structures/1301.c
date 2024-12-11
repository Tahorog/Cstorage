#include <stdio.h>

typedef struct {
    char name[30];
    int age;
    char lettre;
    int time;
    bool vu;
    int note; // sur 10
} t_film;

void remplir(t_film *film){
    printf("Enter name: ");
    scanf("%s", &(*film).name);
    printf("Enter Date: ");
    scanf("%d", &(*film).age);
    printf("Enter lettre: ");
    scanf(" %c", &(*film).lettre);
    printf("Enter time: ");
    scanf("%d", &(*film).time);
    printf("Enter vu ?: ");
    scanf("%d", &(*film).vu);
    printf("Enter note: ");
    scanf("%d", &(*film).note);
}

void afficher(t_film *film) {
    printf("Name: %s\n", (*film).name);
    printf("Date: %d\n", (*film).age);
    printf("Lettre: %c\n", (*film).lettre);
    printf("Time: %d\n", (*film).time);
    printf("Vu: %d\n", (*film).vu);
    printf("Note: %d/10\n", (*film).note);
}

int main(void) {
    t_film film;

    remplir(&film);
    afficher(&film);

    return 0;
}


