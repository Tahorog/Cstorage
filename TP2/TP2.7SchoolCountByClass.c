#include <stdio.h>

int main(void) {
    int nombreClasses, nombreEleves, totalEleves = 0;

    printf("Enter the number of classes in the school :");
    scanf("%d", &nombreClasses);

    for (int i = 1; i<=nombreClasses; i++) {
        printf("Enter number of students in class %d\n :", i);
        scanf("%d", &nombreEleves);
        totalEleves += nombreEleves;
    }

    printf("The total number of pupils in the school is : %d\n", totalEleves);
    return 0;
}
