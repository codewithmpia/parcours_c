#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour écrire dans un fichier
void ecrire_dans_un_fichier(char *filename);

int main() {
    char filename[100];

    // Demander à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier dans lequel écrire : ");
    fgets(filename, sizeof(filename), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '\n') {
            filename[i] = '\0';  // Remplacer '\n' par '\0'
            break;
        }
    }

    // Appeler la fonction pour écrire dans le fichier
    ecrire_dans_un_fichier(filename);

    return 0;
}

// Fonction pour écrire dans un fichier
void ecrire_dans_un_fichier(char *filename) {
    FILE *fichier = fopen(filename, "a");  // Ouvrir le fichier en mode ajout ("a")

    if (fichier == NULL) {  // Vérifier si le fichier a bien été ouvert
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char phrase[256];  // Tableau pour stocker chaque phrase
    printf("Entrez des phrases à ajouter au fichier. Appuyez sur 'Entrée' sans texte pour terminer.\n");

    // Lire les phrases de l'utilisateur jusqu'à une phrase vide
    while (1) {
        printf("Entrez une phrase: ");
        fgets(phrase, sizeof(phrase), stdin);

        // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
        if (phrase[strlen(phrase) - 1] == '\n') {
            phrase[strlen(phrase) - 1] = '\0';
        }

        // Si la phrase est vide, on arrête
        if (strlen(phrase) == 0) {
            break;
        }

        // Écrire la phrase dans le fichier
        fprintf(fichier, "%s\n", phrase);
    }

    // Fermer le fichier après l'écriture
    fclose(fichier);

    printf("Les phrases ont été ajoutées au fichier %s.\n", filename);
}
