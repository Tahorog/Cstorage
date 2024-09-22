#include <stdio.h>

int main(void) {
    int pierres, etages = 0, total_pierres = 0, pierres_etage;

    printf("Enter the number of rocks: ");
    scanf("%d", &pierres);

    while (1) {
        etages++;
        pierres_etage = etages * etages;
        if (total_pierres + pierres_etage > pierres) {
            break;
        }
        total_pierres += pierres_etage;
    }

    printf("You can build %d floors with %d stones. \n", etages-1, pierres);

    return 0;
}
