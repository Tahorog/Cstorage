int horlogeminute(int tempsm){
    if (tempsm == 59) {
        tempsm = 0;
    }else {
        tempsm ++;
    }
    return tempsm;
}

int horlogeheure(int tempsm, int tempsh, char Demijournee){

    int HeureM=0;
        if (tempsh > 23) {
            tempsh = 0;
        }else if (tempsm == 0){
            tempsh ++;
        }
    return tempsh;
}

char horlogeDemijournee(int tempsh, char Demijournee) {
    if (tempsh<12) {
        Demijournee = 'A';
    }else {
        Demijournee = 'P';
    }
    return Demijournee;
}


