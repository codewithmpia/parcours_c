#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256  // Nombre maximum de caractères ASCII

// Prototype de la fonction pour compter la fréquence des caractères
void compter_frequence_de_chaque_caractere_dans_chaine(char *str);

int main() {
    char str[100];

    // Demander à l'utilisateur de saisir une chaîne
    printf("Entrez une chaîne de caractères : ");
    fgets(str, sizeof(str), stdin);  // Utiliser fgets pour lire une ligne complète

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    str[strcspn(str, "\n")] = 0;

    // Appeler la fonction pour compter la fréquence des caractères
    compter_frequence_de_chaque_caractere_dans_chaine(str);

    return 0;
}

// Fonction pour compter la fréquence des caractères dans la chaîne
void compter_frequence_de_chaque_caractere_dans_chaine(char *str) {
    int freq[MAX_CHAR] = {0};  // Tableau pour stocker la fréquence des caractères

    // Parcourir la chaîne et compter les occurrences des caractères
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;  // Incrémenter le compteur pour le caractère str[i]
    }

    // Afficher les caractères avec leurs fréquences
    printf("Fréquence des caractères dans la chaîne :\n");

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}
