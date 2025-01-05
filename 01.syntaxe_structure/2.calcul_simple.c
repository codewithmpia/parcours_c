#include <stdio.h>
#include <stdlib.h>

int additionner(int x, int y);
int soustraire(int x, int y);
int multiplier(int x, int y);
float diviser(int x, int y);

int main () {
    int x;
    int y;

    printf("Entrer x: ");
    scanf("%d", &x);

    printf("Entrer y: ");
    scanf("%d", &y);

    printf("%d + %d = %d\n", x, y, additionner(x, y));
    printf("%d - %d = %d\n", x, y, soustraire(x, y));
    printf("%d * %d = %d\n", x, y, multiplier(x, y));
    printf("%d / %d = %.2f\n", x, y, diviser(x, y));

    return 0;
}

// Additionner
int additionner(int x, int y) {
    return x + y;
}

// Soustraire
int soustraire(int x, int y) {
    return x - y;
}

// Multiplier
int multiplier(int x, int y) {
    return x * y;
}

// Diviser
float diviser(int x, int y) {
    if (y == 0) {
        printf("Impossible de diviser par 0\n");
        EXIT_FAILURE;
    }
    return (float) x / y;
}
