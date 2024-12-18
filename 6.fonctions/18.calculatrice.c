#include <stdio.h>

// Prototypes des fonctions
int addition(int a, int b);
int soustraction(int a, int b);
int multiplication(int a, int b);
float division(int a, int b);

int main() {
    int choix, a, b;
    float resultat;

    // Affichage du menu
    printf("Calculatrice simple\n");
    printf("Choisissez une opération:\n");
    printf("1. Addition (+)\n");
    printf("2. Soustraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Votre choix (1-4): ");
    scanf("%d", &choix);

    // Demande des deux nombres à l'utilisateur
    printf("Entrez le premier nombre: ");
    scanf("%d", &a);

    printf("Entrez le deuxième nombre: ");
    scanf("%d", &b);

    // Traitement selon le choix de l'utilisateur
    switch (choix) {
        case 1:
            resultat = addition(a, b);
            printf("%d + %d = %.2f\n", a, b, resultat);
            break;
        case 2:
            resultat = soustraction(a, b);
            printf("%d - %d = %.2f\n", a, b, resultat);
            break;
        case 3:
            resultat = multiplication(a, b);
            printf("%d * %d = %.2f\n", a, b, resultat);
            break;
        case 4:
            if (b != 0) { // Vérification pour éviter la division par zéro
                resultat = division(a, b);
                printf("%d / %d = %.2f\n", a, b, resultat);
            } else {
                printf("Erreur: Division par zéro impossible.\n");
            }
            break;
        default:
            printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
            break;
    }

    return 0;
}

// Fonction addition
int addition(int a, int b) {
    return a + b;
}

// Fonction soustraction
int soustraction(int a, int b) {
    return a - b;
}

// Fonction multiplication
int multiplication(int a, int b) {
    return a * b;
}

// Fonction division
float division(int a, int b) {
    return (float) a / b; // Conversion explicite en float pour obtenir une division précise
}
