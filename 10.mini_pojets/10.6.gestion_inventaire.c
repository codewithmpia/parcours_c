#include <stdio.h>
#include <string.h>

#define MAX_PRODUITS 100
#define MAX_NOM_PRODUIT 50

// Structure pour représenter un produit
typedef struct {
    char nom[MAX_NOM_PRODUIT];
    int quantite;
    float prix;
} Produit;

// Tableau pour stocker l'inventaire
Produit inventaire[MAX_PRODUITS];
int total_produits = 0;

// Fonction pour ajouter un produit à l'inventaire
void ajouter_produit() {
    if (total_produits < MAX_PRODUITS) {
        printf("Entrez le nom du produit : ");
        getchar();  // Consomme le '\n' restant dans le buffer
        fgets(inventaire[total_produits].nom, sizeof(inventaire[total_produits].nom), stdin);
        inventaire[total_produits].nom[strcspn(inventaire[total_produits].nom, "\n")] = 0; // Enlever le '\n'

        printf("Entrez la quantite du produit : ");
        scanf("%d", &inventaire[total_produits].quantite);

        printf("Entrez le prix du produit : ");
        scanf("%f", &inventaire[total_produits].prix);

        total_produits++;
        printf("Produit ajoute avec succes!\n");
    } else {
        printf("L'inventaire est plein, impossible d'ajouter plus de produits.\n");
    }
}

// Fonction pour afficher l'inventaire
void afficher_inventaire() {
    if (total_produits == 0) {
        printf("L'inventaire est vide.\n");
    } else {
        printf("\n--- Inventaire ---\n");
        for (int i = 0; i < total_produits; i++) {
            printf("Produit : %s\n", inventaire[i].nom);
            printf("Quantite : %d\n", inventaire[i].quantite);
            printf("Prix : %.2f €\n", inventaire[i].prix);
            printf("-------------------\n");
        }
    }
}

// Fonction pour mettre à jour la quantité d'un produit
void mettre_a_jour_quantite() {
    char nom_produit[MAX_NOM_PRODUIT];
    int nouvelle_quantite = 0;
    int trouve = 0;

    printf("Entrez le nom du produit a mettre a jour : ");
    getchar();  // Consomme le '\n' restant dans le buffer
    fgets(nom_produit, sizeof(nom_produit), stdin);
    nom_produit[strcspn(nom_produit, "\n")] = 0; // Enlever le '\n'

    for (int i = 0; i < total_produits; i++) {
        if (strcmp(inventaire[i].nom, nom_produit) == 0) {
            printf("Quantite actuelle du produit %s : %d\n", inventaire[i].nom, inventaire[i].quantite);
            printf("Entrez la nouvelle quantite : ");
            scanf("%d", &nouvelle_quantite);
            inventaire[i].quantite = nouvelle_quantite;
            printf("Quantite mise a jour avec succes!\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouve dans l'inventaire.\n");
    }
}

// Fonction pour calculer la valeur totale de l'inventaire
void calculer_valeur_totale() {
    float total = 0;
    for (int i = 0; i < total_produits; i++) {
        total += inventaire[i].quantite * inventaire[i].prix;
    }
    printf("La valeur totale de l'inventaire est : %.2f €\n", total);
}

// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter un produit\n");
    printf("2. Afficher l'inventaire\n");
    printf("3. Mettre a jour la quantite d'un produit\n");
    printf("4. Calculer la valeur totale de l'inventaire\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    while (1) {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_produit();
                break;
            case 2:
                afficher_inventaire();
                break;
            case 3:
                mettre_a_jour_quantite();
                break;
            case 4:
                calculer_valeur_totale();
                break;
            case 5:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }
    return 0;
}
