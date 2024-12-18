#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100
#define MAX_NOM 50
#define MAX_NOTES 5

// Structure pour représenter un étudiant
typedef struct {
    char nom[MAX_NOM];
    int notes[MAX_NOTES];
    float moyenne;
} Etudiant;

// Tableau pour stocker les étudiants
Etudiant etudiants[MAX_ETUDIANTS];
int total_etudiants = 0;

// Fonction pour calculer la moyenne des notes d'un étudiant
float calculer_moyenne(int notes[], int taille) {
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += notes[i];
    }
    return (float)somme / taille;
}

// Fonction pour ajouter un étudiant
void ajouter_etudiant() {
    if (total_etudiants < MAX_ETUDIANTS) {
        printf("Entrez le nom de l'etudiant : ");
        getchar();  // Consommer le '\n' restant dans le buffer
        fgets(etudiants[total_etudiants].nom, sizeof(etudiants[total_etudiants].nom), stdin);
        etudiants[total_etudiants].nom[strcspn(etudiants[total_etudiants].nom, "\n")] = 0; // Enlever le '\n' de la fin

        printf("Entrez les notes de l'etudiant :\n");
        for (int i = 0; i < MAX_NOTES; i++) {
            printf("Note %d : ", i + 1);
            scanf("%d", &etudiants[total_etudiants].notes[i]);
        }

        // Calcul de la moyenne de l'étudiant
        etudiants[total_etudiants].moyenne = calculer_moyenne(etudiants[total_etudiants].notes, MAX_NOTES);

        total_etudiants++;
        printf("Etudiant ajouté avec succès!\n");
    } else {
        printf("Le nombre maximum d'etudiants a ete atteint!\n");
    }
}

// Fonction pour afficher les informations des étudiants
void afficher_etudiants() {
    if (total_etudiants == 0) {
        printf("Aucun etudiant a afficher.\n");
    } else {
        printf("\n--- Liste des etudiants ---\n");
        for (int i = 0; i < total_etudiants; i++) {
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Notes : ");
            for (int j = 0; j < MAX_NOTES; j++) {
                printf("%d ", etudiants[i].notes[j]);
            }
            printf("\nMoyenne : %.2f\n\n", etudiants[i].moyenne);
        }
    }
}

// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Afficher les etudiants\n");
    printf("3. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    while (1) {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                afficher_etudiants();
                break;
            case 3:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide. Essayez encore.\n");
        }
    }
    return 0;
}
