#include <stdio.h>

// Prototype de la fonction pour calculer la moyenne d'un tableau
float moyenne_tableau(int tableau[], int taille);

int main() {
    int n;

    // Demande à l'utilisateur d'entrer le nombre de valeurs
    printf("Veuillez entrer le nombre de valeurs (N) : ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur : veuillez entrer un entier positif valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    int tableau[n];

    // Lecture des N nombres
    printf("Veuillez entrer %d nombres :\n", n);

    for (int i = 0; i < n; i++) {
        printf("Nombre %d : ", i + 1);
        if (scanf("%d", &tableau[i]) != 1) {
            printf("Erreur : veuillez entrer un entier valide.\n");
            return 1;
        }
    }

    // Calcul de la moyenne
    float moyenne = moyenne_tableau(tableau, n);

    // Affichage de la moyenne
    printf("La moyenne des nombres est : %.2f\n", moyenne);

    return 0;
}

// Fonction pour calculer la moyenne d'un tableau
float moyenne_tableau(int tableau[], int taille) {
    int somme = 0;

    // Calcul de la somme des éléments
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }

    // Calcul de la moyenne
    return (float)somme / taille;
}
