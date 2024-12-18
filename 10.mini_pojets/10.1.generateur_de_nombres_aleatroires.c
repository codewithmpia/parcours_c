#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour générer un nombre aléatoire entre start et end (inclus)
int generer_un_nombre_aleatoire(int start, int end);

int main() {
    int start, end;

    // Demander à l'utilisateur les bornes
    printf("Entrez la borne inférieure : ");
    scanf("%d", &start);

    printf("Entrez la borne supérieure : ");
    scanf("%d", &end);

    // Vérification que la borne inférieure est bien inférieure à la borne supérieure
    if (start > end) {
        printf("Erreur : la borne inférieure doit être inférieure ou égale à la borne supérieure.\n");
        return 1; // Sortie prématurée du programme
    }

    // Initialiser le générateur de nombres aléatoires avec le temps
    srand(time(NULL));

    // Appeler la fonction pour générer un nombre aléatoire
    int random_number = generer_un_nombre_aleatoire(start, end);

    // Afficher le résultat
    printf("Le nombre aléatoire généré entre %d et %d est : %d\n", start, end, random_number);

    return 0;
}

// Fonction qui génère un nombre aléatoire entre start et end (inclus)
int generer_un_nombre_aleatoire(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}
