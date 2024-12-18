#include <stdio.h>
#include <string.h>

void chiffrer_cesar(char* message, int decalage);
void dechiffrer_cesar(char* message, int decalage);

int main() {
    char message[100];
    int decalage;

    printf("Entrez le message à chiffrer : ");
    fgets(message, sizeof(message), stdin);  // Lecture du message
    message[strcspn(message, "\n")] = '\0';  // Enlever le retour à la ligne

    printf("Entrez le décalage : ");
    scanf("%d", &decalage);

    // Chiffrement du message
    chiffrer_cesar(message, decalage);
    printf("Message chiffré : %s\n", message);

    // Déchiffrement du message
    dechiffrer_cesar(message, decalage);
    printf("Message déchiffré : %s\n", message);

    return 0;
}


void chiffrer_cesar(char* message, int decalage) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Vérifier si le caractère est une lettre majuscule
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + decalage) % 26) + 'A';
        }
        // Vérifier si le caractère est une lettre minuscule
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + decalage) % 26) + 'a';
        }
    }
}

void dechiffrer_cesar(char* message, int decalage) {
    chiffrer_cesar(message, -decalage);  // Pour déchiffrer, on applique le décalage inverse
}
