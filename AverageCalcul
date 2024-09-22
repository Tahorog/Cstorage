#include <stdio.h>

int main(void) {
    float note1, note2, note3, moyenne;
    printf("Enter note1: ");
    scanf("%f", &note1);
    printf("Enter note2: ");
    scanf("%f", &note2);
    printf("Enter note3: ");
    scanf("%f", &note3);

    while (note1 + note2 + note3 != 0 || note1 + note2 + note3 >= 60) {
        if (note1>= 0 && note1 <= 20 && note2>= 0 && note2 <= 20 && note3>= 0 && note3 <= 20) {
            moyenne = (note1 + note2 + note3)/3;
            break;
        }
        else {
            if (note1 >= 20) {
                printf("note1 :");
                scanf("%f", &note1);
            }
            if (note2 >= 20) {
                printf("note2 :");
                scanf("%f", &note2);
            }
            if (note3 >= 20) {
                printf("note3 :");
                scanf("%f", &note3);
            }
        }
    }

    printf("Average : %f\n", moyenne);
    return 0;
}
