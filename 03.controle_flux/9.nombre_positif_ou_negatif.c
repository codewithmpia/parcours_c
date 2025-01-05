#include <stdio.h>

// Prototype de la fonction pour vérifier la nature d'un nombre
void verifier_positif_negatif(int x);

int main() {
    int nombre;

    // Demande à l'utilisateur d'entrer un nombre
    printf("Veuillez entrer un nombre entier: ");
    if (scanf("%d", &nombre) != 1) {
        // Gestion des entrées non valides
        printf("Erreur : veuillez entrer un nombre entier valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Vérification de la nature du nombre
    verifier_positif_negatif(nombre);

    return 0;
}

// Fonction pour vérifier si un nombre est positif, négatif ou nul
void verifier_positif_negatif(int x) {
    if (x < 0) {
        printf("%d est un nombre négatif.\n", x);
    } else if (x == 0) {
        printf("%d est égal à zéro.\n", x);
    } else {
        printf("%d est un nombre positif.\n", x);
    }
}
