#include <stdio.h>
#include <ctype.h>  // Pour la fonction isspace()

// Prototype de la fonction pour compter le nombre de mots dans un fichier
int compter_mots_dans_un_fichier(char *filename);

int main() {
    char nom_fichier[100];

    // Demander à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier à lire : ");
    fgets(nom_fichier, sizeof(nom_fichier), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    for (int i = 0; nom_fichier[i] != '\0'; i++) {
        if (nom_fichier[i] == '\n') {
            nom_fichier[i] = '\0';  // Remplacer '\n' par '\0'
            break;
        }
    }

    // Appeler la fonction pour compter les mots dans le fichier
    int nombre_de_mots = compter_mots_dans_un_fichier(nom_fichier);

    // Afficher le nombre de mots
    if (nombre_de_mots >= 0) {
        printf("Le fichier contient %d mots.\n", nombre_de_mots);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    return 0;
}

// Fonction pour compter les mots dans un fichier
int compter_mots_dans_un_fichier(char *filename) {
    FILE *fichier = fopen(filename, "r");  // Ouvrir le fichier en mode lecture

    if (fichier == NULL) {  // Vérifier si le fichier a bien été ouvert
        perror("Erreur lors de l'ouverture du fichier");
        return -1;  // Retourner -1 en cas d'erreur
    }

    int compteur_mots = 0;
    char c;
    int dans_mot = 0;

    // Lire le fichier caractère par caractère
    while ((c = fgetc(fichier)) != EOF) {
        if (isspace(c)) {  // Si le caractère est un espace, une tabulation ou une nouvelle ligne
            if (dans_mot) {
                // Fin d'un mot
                compteur_mots++;
                dans_mot = 0;
            }
        } else {
            // Si le caractère est une lettre, on est dans un mot
            dans_mot = 1;
        }
    }

    // Si le fichier se termine pendant qu'on est dans un mot, comptabiliser ce mot
    if (dans_mot) {
        compteur_mots++;
    }

    // Fermer le fichier après la lecture
    fclose(fichier);

    return compteur_mots;
}
