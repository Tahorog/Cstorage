#include <stdio.h>

int getVerbe(char verbe[100]) {
    int fin=0;
    do {
        printf("Verbe : ");
        scanf("%s", verbe);
        while (verbe[fin] != '\0') {
            fin++;
        }
    } while (!(verbe[fin-1] == 'r' && verbe[fin-2] == 'e'));
    return fin;
}

void conjVerbe(char verbe[100],int fin) {
    verbe[fin-2] = '\0'; // ne guarde que le radical
    printf("Je %se\nTu %ses\nIl %se\nNous %sons\nVous %sez\nIls %sent\n", verbe,verbe,verbe,verbe,verbe,verbe);
}

int main(void) {
    char verbe[100];
    int fin = getVerbe(verbe);
    conjVerbe(verbe,fin);

    return 0;
}


