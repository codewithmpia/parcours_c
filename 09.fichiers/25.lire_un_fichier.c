#include <stdio.h>
#include <stdlib.h>

// Prototype de la fonction pour lire un fichier ligne par ligne
void lire_un_fichier(const char *nom_fichier);

int main() {
    char nom_fichier[100];

    // Demander à l'utilisateur de saisir le nom du fichier
    printf("Entrez le nom du fichier à lire : ");
    fgets(nom_fichier, sizeof(nom_fichier), stdin);

    // Supprimer le caractère de nouvelle ligne à la fin de la chaîne
    // Recherche du caractère de nouvelle ligne et remplacement par '\0'
    for (int i = 0; nom_fichier[i] != '\0'; i++) {
        if (nom_fichier[i] == '\n') {
            nom_fichier[i] = '\0';  // Remplacer '\n' par '\0'
            break;  // Sortir de la boucle une fois le '\n' trouvé et supprimé
        }
    }

    // Appeler la fonction pour lire le fichier
    lire_un_fichier(nom_fichier);

    return 0;
}

// Fonction pour lire un fichier ligne par ligne et afficher son contenu
void lire_un_fichier(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");  // Ouvrir le fichier en mode lecture

    if (fichier == NULL) {  // Vérifier si le fichier a bien été ouvert
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    char ligne[256];  // Un tableau pour stocker chaque ligne du fichier

    // Lire le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);  // Afficher la ligne lue
    }

    // Fermer le fichier après lecture
    fclose(fichier);
}
