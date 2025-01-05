#include <stdio.h>

void copier_un_fichier(char *input_filename, char *output_filename);

int main() {
    char input_filename[100];
    char output_filename[100];

    // Demander à l'utilisateur les noms des fichiers
    printf("Entrez le nom du fichier source (à copier) : ");
    fgets(input_filename, sizeof(input_filename), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    for (int i = 0; input_filename[i] != '\0'; i++) {
        if (input_filename[i] == '\n') {
            input_filename[i] = '\0';  // Remplacer '\n' par '\0'
            break;
        }
    }

    printf("Entrez le nom du fichier de destination : ");
    fgets(output_filename, sizeof(output_filename), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    for (int i = 0; output_filename[i] != '\0'; i++) {
        if (output_filename[i] == '\n') {
            output_filename[i] = '\0';  // Remplacer '\n' par '\0'
            break;
        }
    }

    // Appeler la fonction pour copier le fichier
    copier_un_fichier(input_filename, output_filename);

    return 0;
}

// Fonction pour copier le contenu d'un fichier dans un autre
void copier_un_fichier(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");  // Ouvrir le fichier source en mode lecture

    if (input_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier source");
        return;
    }

    FILE *output_file = fopen(output_filename, "w");  // Ouvrir le fichier de destination en mode écriture

    if (output_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier de destination");
        fclose(input_file);  // Fermer le fichier source si le fichier de destination ne peut pas être ouvert
        return;
    }

    char buffer[1024];  // Un tampon pour stocker temporairement le contenu du fichier
    size_t n;

    // Lire le fichier source et écrire dans le fichier de destination
    while ((n = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        fwrite(buffer, 1, n, output_file);
    }

    // Fermer les fichiers après l'opération
    fclose(input_file);
    fclose(output_file);

    printf("Le fichier a été copié avec succès.\n");
}
