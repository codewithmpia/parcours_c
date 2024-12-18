#include <stdio.h>

// Prototype de la fonction pour calculer la somme des N premiers nombres
int somme_n_premiers_nombres(int n);

int main() {
    int n;

    // Demande à l'utilisateur d'entrer un entier positif
    printf("Veuillez entrer un entier positif N: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Erreur : veuillez entrer un entier positif valide.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Calcule la somme des nombres de 1 à N
    int somme = somme_n_premiers_nombres(n);

    // Affiche le résultat
    printf("La somme des nombres de 1 à %d est : %d\n", n, somme);

    return 0;
}

// Fonction pour calculer la somme des N premiers nombres
int somme_n_premiers_nombres(int n) {
    int somme = 0;
    for (int i = 1; i <= n; i++) {
        somme += i; // Ajoute le nombre courant à la somme
    }
    return somme;
}
