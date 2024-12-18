#include <stdio.h>
#include <string.h>

void chiffrer_xor(char* message, char cle);
void dechiffrer_xor(char* message, char cle);

int main() {
    char message[100];
    char cle;

    printf("Entrez le message à chiffrer : ");
    fgets(message, sizeof(message), stdin);  // Lecture du message
    message[strcspn(message, "\n")] = '\0';  // Enlever le retour à la ligne

    printf("Entrez la clé (un caractère) : ");
    cle = getchar();  // Lecture de la clé

    // Chiffrement du message
    chiffrer_xor(message, cle);
    printf("Message chiffré : %s\n", message);

    // Déchiffrement du message
    dechiffrer_xor(message, cle);
    printf("Message déchiffré : %s\n", message);

    return 0;
}


void chiffrer_xor(char* message, char cle) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] ^ cle;  // Chiffrement par XOR
    }
}

void dechiffrer_xor(char* message, char cle) {
    // Le déchiffrement est identique au chiffrement avec XOR
    chiffrer_xor(message, cle);
}
