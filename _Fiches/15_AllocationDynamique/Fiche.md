# Malloc
## C quoi ?
- Reserve une certaine taille dans la mémoire, précisée en argument 
## Utilisation :
```c
int* entiers = (int*) malloc(10 * sizeof(int)); //crée un tableau de 10 entiers

char *phrase = (char*)malloc(longueur * sizeof(char)+1); //crée une phrase d'une longueur donnée
```
