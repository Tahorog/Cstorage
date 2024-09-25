#include <stdio.h>

int U(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        int U0 = 1, U1 = 1, U_next;
        for (int i = 2; i <= n; i++) {
            U_next = U0 + U1;
            U0 = U1;
            U1 = U_next;
        }
        return U1;
    }
}

int main() {
    int n;

    printf("Entrez un entier n: ");
    scanf("%d", &n);

    printf("U(%d) = %d\n", n, U(n));

    return 0;
}
