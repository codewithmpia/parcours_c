#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 100

void generer_mot_de_passe(char* mot_de_passe, int longueur);

int main() {
    int longueur;
    char mot_de_passe[TAILLE_MAX];

    // Demander à l'utilisateur la longueur du mot de passe
    printf("Entrez la longueur du mot de passe : ");
    scanf("%d", &longueur);

    // Vérification que la longueur est valide
    if (longueur <= 0 || longueur > TAILLE_MAX - 1) {
        printf("Longueur invalide. Veuillez entrer une valeur entre 1 et %d.\n", TAILLE_MAX - 1);
        return 1;
    }

    // Générer le mot de passe
    generer_mot_de_passe(mot_de_passe, longueur);

    // Afficher le mot de passe généré
    printf("Mot de passe généré : %s\n", mot_de_passe);

    return 0;
}


// Fonction pour générer un mot de passe sécurisé
void generer_mot_de_passe(char* mot_de_passe, int longueur) {
    // Liste des caractères autorisés pour le mot de passe
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    // Taille de la chaîne de caractères (sans le caractère null terminator)
    int taille_caractères = sizeof(caracteres) - 1;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Génération du mot de passe
    for (int i = 0; i < longueur; i++) {
        // Choisir un caractère aléatoire
        mot_de_passe[i] = caracteres[rand() % taille_caractères];
    }
    // Ajouter le caractère null à la fin du mot de passe
    mot_de_passe[longueur] = '\0';
}
