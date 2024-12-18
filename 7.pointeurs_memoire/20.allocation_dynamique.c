#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// Prototype de la fonction d'allocation dynamique
void allocation_dynamique(int n);

int main() {
    int taille;

    // Demander à l'utilisateur la taille du tableau
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    // Appeler la fonction d'allocation dynamique
    allocation_dynamique(taille);

    return 0;
}

// Fonction pour allouer dynamiquement un tableau, le remplir et libérer la mémoire
void allocation_dynamique(int n) {
    // Déclaration d'un pointeur pour le tableau
    int *tableau;

    // Allocation dynamique de mémoire pour un tableau de taille n
    tableau = (int *)malloc(n * sizeof(int));

    // Vérifier si l'allocation a échoué
    if (tableau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }

    // Remplir le tableau avec des valeurs (par exemple, des carrés de 1 à n)
    for (int i = 0; i < n; i++) {
        tableau[i] = (i + 1) * (i + 1); // Stocke le carré de l'indice
    }

    // Afficher les valeurs du tableau
    printf("Tableau rempli :\n");
    for (int i = 0; i < n; i++) {
        printf("tableau[%d] = %d\n", i, tableau[i]);
    }

    // Libérer la mémoire allouée dynamiquement
    free(tableau);
    printf("Mémoire libérée.\n");
}
