#include <stdio.h>
#include <string.h>

// Prototype de la fonction pour inverser une chaîne de caractères
void inverser_une_chaine(char *str);

int main() {
    char str[100];

    // Demander à l'utilisateur de saisir une chaîne
    printf("Entrez une chaîne de caractères : ");
    fgets(str, sizeof(str), stdin);  // Utiliser fgets pour lire une ligne complète

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    str[strcspn(str, "\n")] = 0;

    // Appeler la fonction pour inverser la chaîne
    inverser_une_chaine(str);

    // Afficher la chaîne inversée
    printf("Chaîne inversée : %s\n", str);

    return 0;
}

// Fonction pour inverser une chaîne de caractères
void inverser_une_chaine(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Inverser la chaîne
    while (start < end) {
        // Échanger les caractères à la position start et end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Avancer les indices
        start++;
        end--;
    }
}
