#include <stdio.h>

// Déclaration de la fonction pour trouver le plus grand nombre
int trouver_le_plus_grand_nombre(int nombres[3]);

int main () {
    int nombres[3];

    // Demande à l'utilisateur de saisir trois nombres
    printf("Veuillez entrer trois nombres:\n");

    for (int i = 0; i < 3; i++) {
        printf("Nombre %d: ", i + 1);
        scanf("%d", &nombres[i]);
    }

    // Appel de la fonction pour trouver le plus grand nombre
    int plus_grand = trouver_le_plus_grand_nombre(nombres);

    // Affichage du résultat
    printf("Le plus grand nombre est: %d\n", plus_grand);

    return 0;
}

int trouver_le_plus_grand_nombre(int nombres[3]) {
    int max = nombres[0];  // Supposer que le premier nombre est le plus grand

    for (int i = 1; i < 3; i++) {
        if (nombres[i] > max) {
            max = nombres[i];  // Mettre à jour le plus grand nombre si nécessaire
        }
    }

    return max;  // Retourner le plus grand nombre
}
