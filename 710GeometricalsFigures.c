#include <stdio.h>

int main(void) {
    int figure,h;

    do {
        printf("SELECT IN MENU : \n1)Triangle\n2)carre\n3)sablier\n\n");
        scanf("%d", &figure);
    }while (figure < 1 || figure > 3);

    do {
        printf("Taille ?\n");
        scanf("%d", &h);
    }while (h < 1 || h > 50);

    switch (figure) {
        case 1:
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < h-i-1; j++)
                    printf(" ");
                for (int k = 0; k < (i+1)*2-1; k++)
                printf("*");
                printf("\n");
            }
            break;
        case 2:
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < h; j++)
                    printf("*");
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < i; j++)
                    printf(" ");
                for (int k = 0; k < (h-i)*2-1; k++)
                    printf("*");
                printf("\n");
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < h-i-1; j++)
                    printf(" ");
                for (int k = 0; k < (i+1)*2-1; k++)
                    printf("*");
                printf("\n");
            }
            break;
    }
}
