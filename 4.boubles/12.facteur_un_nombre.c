#include <stdio.h>

// Prototype de la fonction pour afficher les diviseurs d'un nombre
void afficher_les_diviseurs_nombre(int n);

int main() {
    int n;

    // Demande à l'utilisateur d'entrer un entier positif
    printf("Veuillez entrer un entier positif: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : veuillez entrer un entier positif valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Affiche les diviseurs du nombre
    printf("Les diviseurs de %d sont :\n", n);

    afficher_les_diviseurs_nombre(n);

    return 0;
}

// Fonction pour afficher les diviseurs d'un nombre
void afficher_les_diviseurs_nombre(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { // Si i est un diviseur de n
            printf("%d ", i);
        }
    }
    printf("\n"); // Passe à la ligne après l'affichage des diviseurs
}
