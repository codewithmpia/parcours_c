#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction qui exécute le jeu de devinette
void jeu_de_devinette();

int main() {
    // Lancer le jeu de devinette
    jeu_de_devinette();
    return 0;
}

void jeu_de_devinette() {
    int nombre_secret, guess;
    int essais = 0;

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Générer un nombre secret aléatoire entre 1 et 100
    nombre_secret = rand() % 100 + 1;

    printf("Bienvenue dans le jeu de devinette!\n");
    printf("Devinez un nombre entre 1 et 100.\n");

    // Boucle de jeu où l'utilisateur fait des suppositions
    do {
        printf("Entrez votre supposition: ");
        if (scanf("%d", &guess) != 1) {
            printf("Veuillez entrer un nombre valide.\n");
            // Vider le buffer d'entrée
            while (getchar() != '\n');
            continue;
        }

        // Vérification de l'intervalle de la supposition
        if (guess < 1 || guess > 100) {
            printf("Veuillez entrer un nombre entre 1 et 100.\n");
        } else {
            essais++; // Compter les essais

            if (guess < nombre_secret) {
                printf("C'est plus grand!\n");
            } else if (guess > nombre_secret) {
                printf("C'est plus petit!\n");
            } else {
                printf("Félicitations! Vous avez trouvé le nombre secret %d en %d essais.\n", nombre_secret, essais);
            }
        }
    } while (guess != nombre_secret);  // Continuer tant que la supposition est incorrecte
}
