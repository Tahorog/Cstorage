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


