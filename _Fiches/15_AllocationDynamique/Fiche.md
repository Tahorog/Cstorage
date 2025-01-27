# Malloc
## C quoi ?
- Reserve une certaine taille dans la mémoire, précisée en argument

## Paramètres : 
malloc(<taille>)
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
