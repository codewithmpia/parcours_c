#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure pour stocker les informations de chaque contact
typedef struct {
    char nom[50];
    char numero[20];
} Contact;

// Tableau pour stocker les contacts
Contact carnet[MAX_CONTACTS];
int total_contacts = 0;

// Fonction pour ajouter un contact
void ajouter_contact() {
    if (total_contacts < MAX_CONTACTS) {
        printf("Entrez le nom du contact : ");
        getchar(); // Pour consommer le retour à la ligne après l'entrée précédente
        fgets(carnet[total_contacts].nom, sizeof(carnet[total_contacts].nom), stdin);
        carnet[total_contacts].nom[strcspn(carnet[total_contacts].nom, "\n")] = 0; // Enlever le '\n' à la fin du nom

        printf("Entrez le numéro de téléphone : ");
        fgets(carnet[total_contacts].numero, sizeof(carnet[total_contacts].numero), stdin);
        carnet[total_contacts].numero[strcspn(carnet[total_contacts].numero, "\n")] = 0; // Enlever le '\n' à la fin du numéro

        total_contacts++;
        printf("Contact ajouté avec succès!\n");
    } else {
        printf("Le carnet d'adresses est plein!\n");
    }
}

// Fonction pour afficher tous les contacts
void afficher_contacts() {
    if (total_contacts == 0) {
        printf("Aucun contact à afficher.\n");
    } else {
        printf("\n--- Liste des contacts ---\n");
        for (int i = 0; i < total_contacts; i++) {
            printf("Nom : %s, Numéro : %s\n", carnet[i].nom, carnet[i].numero);
        }
    }
}

// Fonction pour rechercher un contact par nom
void rechercher_contact() {
    char nom_recherche[50];
    printf("Entrez le nom du contact à rechercher : ");
    getchar(); // Pour consommer le retour à la ligne après l'entrée précédente
    fgets(nom_recherche, sizeof(nom_recherche), stdin);
    nom_recherche[strcspn(nom_recherche, "\n")] = 0; // Enlever le '\n' à la fin du nom

    int trouve = 0;
    for (int i = 0; i < total_contacts; i++) {
        if (strcmp(carnet[i].nom, nom_recherche) == 0) {
            printf("Contact trouvé : Nom : %s, Numéro : %s\n", carnet[i].nom, carnet[i].numero);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun contact trouvé avec ce nom.\n");
    }
}

// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter un contact\n");
    printf("2. Afficher tous les contacts\n");
    printf("3. Rechercher un contact\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    while (1) {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_contact();
                break;
            case 2:
                afficher_contacts();
                break;
            case 3:
                rechercher_contact();
                break;
            case 4:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }
    return 0;
}
