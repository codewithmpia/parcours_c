#include <stdio.h>

// Prototypes des fonctions
int factorielle_recursive(int n);
int factorielle_iterative(int n);

int main() {
    int n;

    // Demande à l'utilisateur d'entrer un entier positif
    printf("Veuillez entrer un entier positif : ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Erreur : veuillez entrer un entier positif valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Calcul et affichage de la factorielle (récursive)
    printf("Factorielle (récursive) de %d est : %d\n", n, factorielle_recursive(n));

    // Calcul et affichage de la factorielle (itérative)
    printf("Factorielle (itérative) de %d est : %d\n", n, factorielle_iterative(n));

    return 0;
}

// Fonction récursive pour calculer la factorielle
int factorielle_recursive(int n) {
    if (n == 0 || n == 1) { // Cas de base
        return 1;
    }
    return n * factorielle_recursive(n - 1); // Appel récursif
}

// Fonction itérative pour calculer la factorielle
int factorielle_iterative(int n) {
    int resultat = 1;

    for (int i = 2; i <= n; i++) { // Multiplie les nombres de 2 à n
        resultat *= i;
    }

    return resultat;
}
