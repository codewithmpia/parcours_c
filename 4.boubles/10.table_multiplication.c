#include <stdio.h>

// Prototype de la fonction pour afficher la table de multiplication
void afficher_table_multiplication(int nombre);

int main() {
    int nombre;

    // Demande à l'utilisateur d'entrer un nombre
    printf("Veuillez entrer un nombre pour afficher sa table de multiplication: ");

    if (scanf("%d", &nombre) != 1) {
        printf("Erreur : veuillez entrer un nombre entier valide.\n");
        return 1; // Quitte le programme en cas d'erreur d'entrée
    }

    // Affiche la table de multiplication
    afficher_table_multiplication(nombre);

    return 0;
}

// Fonction pour afficher la table de multiplication d'un nombre
void afficher_table_multiplication(int nombre) {
    printf("\nTable de multiplication pour %d:\n", nombre);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", nombre, i, (nombre * i));
    }
}
