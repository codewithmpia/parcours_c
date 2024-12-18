#include <stdio.h>
#include <time.h>
#include <unistd.h>  // Pour la fonction sleep()

// Fonction qui affiche l'heure actuelle
void horloge_numerique();

int main() {
    // Affichage de l'horloge numérique qui se met à jour toutes les secondes
    horloge_numerique();
    return 0;
}

void horloge_numerique() {
    while (1) {
        // Obtenir l'heure actuelle
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);

        // Tableau pour stocker l'heure formatée
        char buffer[9]; // Format "HH:MM:SS"

        // Formater l'heure en "HH:MM:SS"
        strftime(buffer, sizeof(buffer), "%H:%M:%S", tm_info);

        // Effacer l'écran (optionnel, fonctionne sous Linux et macOS)
        printf("\033[H\033[J");

        // Afficher l'heure actuelle
        printf("L'heure actuelle est: %s\n", buffer);

        // Attendre une seconde avant de mettre à jour l'heure
        sleep(1);
    }
}
