# Malloc
## C quoi ?
- Reserve une certaine taille dans la mémoire, précisée en argument

## Paramètres : 
malloc(\<taille>)
- taille de la mémoire à reserver (en octets)

## Utilisation :
```c
int* entiers = (int*) malloc(10 * sizeof(int)); //crée un tableau de 10 entiers

char *phrase = (char*)malloc(longueur * sizeof(char)+1); //crée une phrase d'une longueur donnée
```

# Calloc
## C quoi ?
- Reserve une certaine taille dans la mémoire, et l'initialise à 0

## Paramètres : 
calloc(<nb_elements>,<taille_element>)
- Nombre d'élément
- Taille d'un élément
 
## Utilisation :
```c
int * entiers = (int*) calloc(10, sizeof(int)); //crée un tableau de 10 entiers, initialisés à 0
```
# Gestion des erreurs
## Explication
les fonctions malloc et calloc peuvent échouer et renvoient dans ce cas un pointeur NULL

## Vérification de l'erreur
Si l'allocation échoue, on peut renvoyer un message d'erreur et arrêter le programme 
```c
int* entiers = (int*) malloc(10 * sizeof(int)); //crée un tableau de 10 entiers

if (entiers == NULL){ // gestion des erreurs
 printf("erreur lors de l'allocation"); 
 exit(-1); //on stope le programme
}
```

# Realloc
## C quoi ?
- Permet de réallouer un bloc de mémoire alloué dynamiquement

## Paramètres : 
realloc(\<pointeur>,<nouvelle_taille>)
- Pointeur vers le bloc alloué dynamiquement
- nouvelle taille à reserver dans la mémoire (en octets)

## Utilisation :
```c
int* entiers = (int*) malloc(10 * sizeof(int)); //crée un tableau de 10 entiers

entiers = realloc(entiers, 20 * sizeof(int)); //transforme en un tableau de 20 entiers
```

# Libération de la mémoire
## Explication
La mémoire allouée dynamiquement ne se libère pas automatiquement, il faut donc la libérer à la fin de son utilisation

## Libérer la mémoire
On utilise pour cela la fonction free, qui prend en argument le pointeur vers le bloc réservé dans la mémoire
```c
int* entiers = (int*) malloc(10 * sizeof(int)); //crée un tableau de 10 entiers

free(entiers); // libérer la mémoire dynamique
```

# Résumé

## Programme complet

```c
#include <stdio.h>
#include <stdlib.h>

//remplir le tableau
void remplir(int taille,int tableau[taille]) {
    for (int i = 0; i < taille; i++) {
        printf("Tab %d: ", i);
        scanf("%d",&tableau[i]);
    }
}

// afficher le tableau
void afficher(int taille,int tableau[taille]) {
    printf("\n--- Tableau ---\n");
    for (int i = 0; i < taille; i++) {
        printf("%d) %d\n", i, tableau[i]);
    }
    printf("\n");
}

// ajouter un élément à la fin du tableau avec realloc
void ajouter(int * taille,int **tableau,int nombre) {
    *taille = *taille + 1;
    *tableau= realloc(*tableau,(*taille)*sizeof(int));
    *tableau[*taille-1] = nombre;
}


int main() {
    int taille;

    printf("taille du tableau: ");
    scanf("%d",&taille);

    int* entiers = (int*) malloc(taille * sizeof(int)); //crée un tableau de taille donnée

    if (entiers == NULL) {
        printf("erreur\n");
        exit(-1);
    }

    remplir(taille,entiers);
    afficher(taille,entiers);

    ajouter(&taille,&entiers,3);

    afficher(taille,entiers);

    free(entiers); // libérer la mémoire dynamique
    return 0;
}
```



