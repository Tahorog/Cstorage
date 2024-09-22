#include <stdio.h>

int main(void) {
    int age, tarifenfant, tarifsenior, pleintarif, tarifjeune, etudiant, reponse;

    tarifenfant = 4;
    tarifsenior = 6;
    pleintarif = 9;
    etudiant = 6;
    reponse = 0;
    tarifjeune = 6;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age<= 12) {
        printf("You must pay : %d\n", tarifenfant);
    }
    else if (age > 12 && age <= 17) {
        printf("You must pay : %d\n", tarifjeune);
    }
    else if (age > 17 && age <= 27) {
        printf("Are you a student ? (1 : yes / 0 : no)");
        scanf("%d", &reponse);
        if (reponse == 1) {
            printf("You must pay : %d\n", etudiant);
        }
        else if (reponse == 0) {
            printf("You must pay : %d\n", pleintarif);
        }
    }
    else if (age >= 65) {
        printf("You must pay : %d\n", tarifsenior);
    }
    else if (age < 65 && age > 27) {
        printf("You must pay : %d\n", pleintarif);
    }

    return 0;
}
