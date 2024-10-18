#include <stdio.h>

int calculMoyenne(int note1, int note2, int note3) {
    int moyenne;
    moyenne = (note1 + note2 + note3)/3;
    return moyenne;
}

int affichageMoyenne(int note1, int note2, int note3){
    int moyenne;
    if (0<=note1<=20 && 0<=note2<=20 && 0<=note3<=20) {
        moyenne = calculMoyenne(note1, note2 , note3);
    }else {
        moyenne = -1;
    }
    printf("La moyenne est : %d", moyenne);
    return moyenne;
}
