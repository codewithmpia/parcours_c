#include <stdio.h>

// Prototype de la fonction qui échange les valeurs
void echanger_de_valeurs(int *a, int *b);

int main() {
    int x, y;

    // Demander à l'utilisateur de saisir deux nombres
    printf("Entrez le premier nombre: ");
    scanf("%d", &x);

    printf("Entrez le deuxième nombre: ");
    scanf("%d", &y);

    // Afficher les valeurs avant l'échange
    printf("Avant échange: x = %d, y = %d\n", x, y);

    // Appeler la fonction pour échanger les valeurs
    echanger_de_valeurs(&x, &y);

    // Afficher les valeurs après l'échange
    printf("Après échange: x = %d, y = %d\n", x, y);

    return 0;
}

// Fonction qui échange les valeurs de deux variables
void echanger_de_valeurs(int *a, int *b) {
    int temp;

    // Utilisation d'une variable temporaire pour l'échange
    temp = *a;  // Stocker la valeur de a dans temp
    *a = *b;     // Mettre la valeur de b dans a
    *b = temp;   // Mettre la valeur de temp (ancien a) dans b
}
