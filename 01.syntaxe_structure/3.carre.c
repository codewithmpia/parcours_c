#include <stdio.h>

// Le carré d'un nombre
int main () {
    int user_input;
    printf("Entrer un nombre: ");
    scanf("%d", &user_input);

    printf("Le carré de %d est %d\n", user_input, (user_input * user_input));

    return 0;
}
