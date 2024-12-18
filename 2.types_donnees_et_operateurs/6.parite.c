#include <stdio.h>

void parite(int n);
void parite2(int n);

// Parité
int main() {
    int nombre;
    printf("Veuillez entrer un nombre entier: ");

    // Vérification de la validité de l'entrée
    if (scanf("%d", &nombre) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
        return 1;  // Retourner un code d'erreur
    }

    parite(nombre);

    parite2(nombre);
    return 0;
}

void parite(int n) {
    if (n % 2 == 0) {
        printf("%d est pair.\n", n);
    } else {
        printf("%d est impair.\n", n);
    }
}

void parite2 (int n) {
    printf("%d est %s.\n", n, (n % 2 == 0) ? "pair" : "impair");
};
