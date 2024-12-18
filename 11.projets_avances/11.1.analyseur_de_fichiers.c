#include <stdio.h>
#include <ctype.h>

void analyser_fichier(const char *nom_fichier);

int main() {
    char nom_fichier[100];
    printf("Entrez le nom du fichier a analyser : ");
    scanf("%s", nom_fichier);

    analyser_fichier(nom_fichier);

    return 0;
}

void analyser_fichier(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", nom_fichier);
        return;
    }

    int lignes = 0, mots = 0, caracteres = 0;
    char c, prev = '\0';

    while ((c = fgetc(fichier)) != EOF) {
        // Compter les caractères
        caracteres++;

        // Compter les lignes
        if (c == '\n') {
            lignes++;
        }

        // Compter les mots
        if (isspace(c) && !isspace(prev) && prev != '\0') {
            mots++;
        }

        prev = c;
    }

    // Ajouter le dernier mot si le fichier ne se termine pas par un espace ou une nouvelle ligne
    if (!isspace(prev) && prev != '\0') {
        mots++;
    }

    // Ajouter une ligne si le fichier ne se termine pas par une nouvelle ligne
    if (prev != '\n' && prev != '\0') {
        lignes++;
    }

    fclose(fichier);

    printf("\n--- Statistiques du fichier ---\n");
    printf("Nombre de lignes : %d\n", lignes);
    printf("Nombre de mots : %d\n", mots);
    printf("Nombre de caracteres : %d\n", caracteres);
}
