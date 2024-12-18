#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5080
#define BUFFER_SIZE 1024

void start_server();
char *read_file(const char *filename);

int main() {
    start_server();
    return 0;
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Lire le contenu du fichier HTML
    char *html_content = read_file("index.html");
    if (html_content == NULL) {
        fprintf(stderr, "Erreur : impossible de lire le fichier index.html\n");
        exit(EXIT_FAILURE);
    }

    // Construction de la réponse HTTP
    char http_response[BUFFER_SIZE];
    snprintf(http_response, sizeof(http_response),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "Content-Length: %lu\r\n"
             "\r\n"
             "%s",
             strlen(html_content), html_content);

    // Libérer le contenu HTML une fois qu'il est utilisé
    free(html_content);

    // Création du socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Erreur de création du socket");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du serveur
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Écoute sur toutes les interfaces
    address.sin_port = htons(PORT);

    // Liaison du socket à l'adresse et au port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Erreur de liaison");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Mise en écoute du socket
    if (listen(server_fd, 5) < 0) {
        perror("Erreur de mise en écoute");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Serveur en écoute sur le port %d...\n", PORT);

    while (1) {
        // Acceptation des connexions entrantes
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Erreur lors de l'acceptation de la connexion");
            continue;
        }

        // Lecture des données de la requête
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Requête reçue :\n%s\n", buffer);

        // Envoi de la réponse HTTP
        write(new_socket, http_response, strlen(http_response));

        // Fermeture de la connexion
        close(new_socket);
    }

    // Fermeture du serveur (inaccessible ici en pratique)
    close(server_fd);
}

// Fonction pour lire le contenu d'un fichier
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    // Aller à la fin du fichier pour déterminer sa taille
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Allouer un tampon pour le contenu du fichier
    char *content = malloc(filesize + 1);
    if (content == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(file);
        return NULL;
    }

    // Lire le fichier dans le tampon
    fread(content, 1, filesize, file);
    content[filesize] = '\0'; // Terminaison de chaîne

    fclose(file);
    return content;
}
