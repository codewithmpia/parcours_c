#include <stdio.h>

// Prototype de la fonction pour trouver un élément dans un tableau
int trouver_un_element(int tableau[], int taille, int element);

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
            return 1; // Quitte le programme en cas d'erreur d'entrée
        }
    }

    int element;

    // Demande à l'utilisateur de saisir l'élément à rechercher
    printf("Veuillez entrer l'élément à rechercher : ");

    if (scanf("%d", &element) != 1) {
        printf("Erreur : veuillez entrer un entier valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Recherche de l'élément dans le tableau
    if (trouver_un_element(tableau, n, element)) {
        printf("L'élément %d existe dans le tableau.\n", element);
    } else {
        printf("L'élément %d n'existe pas dans le tableau.\n", element);
    }

    return 0;
}

// Fonction pour vérifier si un élément existe dans un tableau
int trouver_un_element(int tableau[], int taille, int element) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == element) { // Vérifie si l'élément correspond
            return 1; // L'élément est trouvé
        }
    }
    return 0; // L'élément n'est pas trouvé
}
