#include <stdio.h>
int main() {
    int x, reponse, correct, incorrect;

    do {
        printf("Entrer un x positif ");
        scanf("%d", &x);
    } while(x<=0);
    do {
        correct = 0;
        incorrect = 0;
        for (int i = 0; i <=9; i++) {
            printf("%d*%d",x , i);
            scanf("%d",&reponse);
            if(reponse == x*i) {
                correct +=1;
            }
            else
                incorrect +=1;
        }
        if (incorrect==0) {
            printf("Tu as eu tout bon");
        }
        else
            printf("Recommence, tu as eu %d reponse(s) incorrecte(s).", incorrect);
    } while(incorrect!=0);

    return 0;
}
