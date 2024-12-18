#include <stdio.h>
#include <string.h> // Inclure pour strncpy

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char nom[50];
    char etat[20]; // Etat limité à 20 caractères
} Processus;

void afficher_processus(Processus *processus, int nombre);
void ajouter_processus(Processus *processus, int *nombre);
void arreter_processus(Processus *processus, int nombre);
void supprimer_processus(Processus *processus, int *nombre);

int main() {
    Processus processus[MAX_PROCESSES];
    int nombre_processus = 0;
    int choix;

    do {
        printf("\n--- Gestionnaire de processus ---\n");
        printf("1. Afficher les processus\n");
        printf("2. Ajouter un processus\n");
        printf("3. Arrêter un processus\n");
        printf("4. Supprimer un processus\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficher_processus(processus, nombre_processus);
                break;
            case 2:
                ajouter_processus(processus, &nombre_processus);
                break;
            case 3:
                arreter_processus(processus, nombre_processus);
                break;
            case 4:
                supprimer_processus(processus, &nombre_processus);
                break;
            case 5:
                printf("Quitter le gestionnaire de processus.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}

void afficher_processus(Processus *processus, int nombre) {
    if (nombre == 0) {
        printf("Aucun processus à afficher.\n");
        return;
    }

    printf("\n--- Liste des processus ---\n");
    for (int i = 0; i < nombre; i++) {
        printf("PID: %d | Nom: %s | Etat: %s\n", processus[i].pid, processus[i].nom, processus[i].etat);
    }
}

void ajouter_processus(Processus *processus, int *nombre) {
    if (*nombre >= MAX_PROCESSES) {
        printf("Nombre maximum de processus atteint.\n");
        return;
    }

    Processus nouveau;
    nouveau.pid = *nombre + 1; // Génère un PID incrémental.
    printf("Entrez le nom du processus : ");
    scanf("%s", nouveau.nom);

    // Utilisation de strncpy pour éviter un débordement
    strncpy(nouveau.etat, "En cours d'exécution", sizeof(nouveau.etat) - 1);
    nouveau.etat[sizeof(nouveau.etat) - 1] = '\0'; // Assurer la terminaison

    processus[*nombre] = nouveau;
    (*nombre)++;

    printf("Processus ajouté avec succès.\n");
}

void arreter_processus(Processus *processus, int nombre) {
    int pid;
    printf("Entrez le PID du processus à arrêter : ");
    scanf("%d", &pid);

    for (int i = 0; i < nombre; i++) {
        if (processus[i].pid == pid) {
            // Utilisation de strncpy pour éviter un débordement
            strncpy(processus[i].etat, "Arrêté", sizeof(processus[i].etat) - 1);
            processus[i].etat[sizeof(processus[i].etat) - 1] = '\0'; // Assurer la terminaison
            printf("Le processus PID %d a été arrêté.\n", pid);
            return;
        }
    }

    printf("Aucun processus trouvé avec le PID %d.\n", pid);
}

void supprimer_processus(Processus *processus, int *nombre) {
    int pid;
    printf("Entrez le PID du processus à supprimer : ");
    scanf("%d", &pid);

    for (int i = 0; i < *nombre; i++) {
        if (processus[i].pid == pid) {
            for (int j = i; j < *nombre - 1; j++) {
                processus[j] = processus[j + 1];
            }
            (*nombre)--;
            printf("Le processus PID %d a été supprimé.\n", pid);
            return;
        }
    }

    printf("Aucun processus trouvé avec le PID %d.\n", pid);
}
