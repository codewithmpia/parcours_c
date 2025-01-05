#include <stdio.h>
#include <string.h>
#include <ctype.h> // Pour la fonction tolower()

// Prototype de la fonction pour vérifier si la chaîne est un palindrome
_Bool verifier_palindrome(char *str);

int main() {
    char str[100];

    // Demander à l'utilisateur de saisir une chaîne
    printf("Entrez une chaîne de caractères : ");
    fgets(str, sizeof(str), stdin);  // Utiliser fgets pour éviter les problèmes d'espaces

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    str[strcspn(str, "\n")] = 0;

    // Vérifier si la chaîne est un palindrome
    if (verifier_palindrome(str)) {
        printf("La chaîne est un palindrome.\n");
    } else {
        printf("La chaîne n'est pas un palindrome.\n");
    }

    return 0;
}

// Fonction pour vérifier si une chaîne est un palindrome
_Bool verifier_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Ignorer les caractères non alphabétiques (espaces, ponctuation)
        if (!isalnum(str[start])) {
            start++;
        } else if (!isalnum(str[end])) {
            end--;
        } else {
            // Comparer les caractères en minuscules pour ignorer la casse
            if (tolower(str[start]) != tolower(str[end])) {
                return 0;  // Retourne 0 si ce n'est pas un palindrome
            }
            start++;
            end--;
        }
    }

    return 1;  // Retourne 1 si c'est un palindrome
}
