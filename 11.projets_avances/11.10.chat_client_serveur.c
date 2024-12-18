#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5086
#define TAILLE_BUFFER 1024

int main() {
    int clientSocket;
    struct sockaddr_in serveurAddr;
    char buffer[TAILLE_BUFFER];

    // Créer un socket TCP
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Erreur de création du socket");
        exit(1);
    }

    // Initialiser la structure sockaddr_in pour le serveur
    memset(&serveurAddr, 0, sizeof(serveurAddr));
    serveurAddr.sin_family = AF_INET;
    serveurAddr.sin_port = htons(PORT);

    // Convertir l'adresse IP du serveur en format binaire
    if (inet_pton(AF_INET, "127.0.0.1", &serveurAddr.sin_addr) <= 0) {
        perror("Adresse du serveur invalide");
        close(clientSocket);
        exit(1);
    }

    // Se connecter au serveur
    if (connect(clientSocket, (struct sockaddr*)&serveurAddr, sizeof(serveurAddr)) == -1) {
        perror("Erreur de connexion au serveur");
        close(clientSocket);
        exit(1);
    }

    printf("Connecté au serveur sur le port %d\n", PORT);

    // Communication avec le serveur
    while (1) {
        // Lire le message de l'utilisateur
        printf("Vous: ");
        fgets(buffer, TAILLE_BUFFER, stdin);

        // Envoyer le message au serveur
        send(clientSocket, buffer, strlen(buffer), 0);

        // Recevoir la réponse du serveur
        memset(buffer, 0, TAILLE_BUFFER);
        int bytesReceived = recv(clientSocket, buffer, TAILLE_BUFFER, 0);
        if (bytesReceived <= 0) {
            if (bytesReceived == 0)
                printf("Le serveur a fermé la connexion.\n");
            else
                perror("Erreur de réception");
            break;
        }
        printf("Serveur: %s\n", buffer);
    }

    // Fermer le socket
    close(clientSocket);

    return 0;
}
