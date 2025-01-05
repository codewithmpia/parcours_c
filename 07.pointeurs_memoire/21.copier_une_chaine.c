#include <stdio.h>

// Prototype de la fonction de copie de chaîne
void copier_une_chaine(char *source, char *destination);

int main() {
    char source[100], destination[100];

    // Demander à l'utilisateur de saisir une chaîne
    printf("Entrez une chaîne de caractères : ");
    fgets(source, sizeof(source), stdin);  // Utiliser fgets pour lire une ligne complète

    // Appeler la fonction pour copier la chaîne
    copier_une_chaine(source, destination);

    // Afficher la chaîne copiée
    printf("Chaîne copiée : %s\n", destination);

    return 0;
}

// Fonction qui copie une chaîne de caractères en utilisant des pointeurs
void copier_une_chaine(char *source, char *destination) {
    while (*source != '\0') {  // Tant que le caractère source n'est pas le caractère nul '\0'
        *destination = *source;  // Copier le caractère de source à destination
        source++;  // Avancer le pointeur source
        destination++;  // Avancer le pointeur destination
    }
    *destination = '\0';  // Ajouter le caractère nul '\0' à la fin de la chaîne destination
}
