#include <stdio.h>

// Prototype de la fonction pour trier un tableau
void tri_un_tableau(int tableau[], int taille);

int main() {
    int n;

    // Demande à l'utilisateur d'entrer la taille du tableau
    printf("Veuillez entrer la taille du tableau : ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : veuillez entrer un entier positif valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    int tableau[n];

    // Saisie des éléments du tableau
    printf("Veuillez entrer %d éléments :\n", n);

    for (int i = 0; i < n; i++) {
        printf("Élément %d : ", i + 1);
        if (scanf("%d", &tableau[i]) != 1) {
            printf("Erreur : veuillez entrer un entier valide.\n");
            return 1;
        }
    }

    // Tri du tableau
    tri_un_tableau(tableau, n);

    // Affichage du tableau trié
    printf("Tableau trié dans l'ordre croissant :\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}

// Fonction pour trier un tableau (tri par sélection)
void tri_un_tableau(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int min_index = i;

        // Trouve le plus petit élément dans la sous-partie non triée
        for (int j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[min_index]) {
                min_index = j;
            }
        }

        // Échange les éléments si nécessaire
        if (min_index != i) {
            int temp = tableau[i];
            tableau[i] = tableau[min_index];
            tableau[min_index] = temp;
        }
    }
}
