
int updatem(int m) {
    if (m==59) {
        return 0;
    } else {
        return m+1;
    }
}

int updateh(int m,int h) {
    if (m==0) {
        if (h==11) {
            return 0;
        } else {
            return h+1;
        }
    } else {
        return h;
    }
}
