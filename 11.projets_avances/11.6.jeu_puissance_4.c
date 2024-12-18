#include <stdio.h>
#include <stdbool.h>

#define LIGNES 6
#define COLONNES 7

void afficher_grille(char grille[LIGNES][COLONNES]);
bool jouer_coup(char grille[LIGNES][COLONNES], int colonne, char jeton);
bool verifier_victoire(char grille[LIGNES][COLONNES], char jeton);
bool grille_pleine(char grille[LIGNES][COLONNES]);

int main() {
    char grille[LIGNES][COLONNES];

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            grille[i][j] = ' ';
        }
    }

    int colonne;
    char jeton_actuel = 'X';

    while (true) {
        afficher_grille(grille);

        printf("Joueur %c, choisissez une colonne (1-%d) : ", jeton_actuel, COLONNES);
        scanf("%d", &colonne);

        // Valider l'entrée
        if (colonne < 1 || colonne > COLONNES || !jouer_coup(grille, colonne - 1, jeton_actuel)) {
            printf("Coup invalide, réessayez.\n");
            continue;
        }

        // Vérifier la victoire
        if (verifier_victoire(grille, jeton_actuel)) {
            afficher_grille(grille);
            printf("Joueur %c a gagné !\n", jeton_actuel);
            break;
        }

        // Vérifier si la grille est pleine
        if (grille_pleine(grille)) {
            afficher_grille(grille);
            printf("Match nul !\n");
            break;
        }

        // Changer de joueur
        jeton_actuel = (jeton_actuel == 'X') ? 'O' : 'X';
    }

    return 0;
}

void afficher_grille(char grille[LIGNES][COLONNES]) {
    printf("\n");

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("| %c ", grille[i][j]);
        }
        printf("|\n");
    }

    for (int j = 0; j < COLONNES; j++) {
        printf("----");
    }

    printf("-\n");

    for (int j = 0; j < COLONNES; j++) {
        printf("  %d ", j + 1);
    }

    printf("\n\n");
}

bool jouer_coup(char grille[LIGNES][COLONNES], int colonne, char jeton) {
    if (colonne < 0 || colonne >= COLONNES || grille[0][colonne] != ' ') {
        return false;
    }

    for (int i = LIGNES - 1; i >= 0; i--) {
        if (grille[i][colonne] == ' ') {
            grille[i][colonne] = jeton;
            return true;
        }
    }
    return false;
}

bool verifier_victoire(char grille[LIGNES][COLONNES], char jeton) {
    // Vérification des lignes
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j <= COLONNES - 4; j++) {
            if (grille[i][j] == jeton && grille[i][j + 1] == jeton && grille[i][j + 2] == jeton && grille[i][j + 3] == jeton) {
                return true;
            }
        }
    }

    // Vérification des colonnes
    for (int j = 0; j < COLONNES; j++) {
        for (int i = 0; i <= LIGNES - 4; i++) {
            if (grille[i][j] == jeton && grille[i + 1][j] == jeton && grille[i + 2][j] == jeton && grille[i + 3][j] == jeton) {
                return true;
            }
        }
    }

    // Vérification des diagonales (haut-gauche vers bas-droite)
    for (int i = 0; i <= LIGNES - 4; i++) {
        for (int j = 0; j <= COLONNES - 4; j++) {
            if (grille[i][j] == jeton && grille[i + 1][j + 1] == jeton && grille[i + 2][j + 2] == jeton && grille[i + 3][j + 3] == jeton) {
                return true;
            }
        }
    }

    // Vérification des diagonales (haut-droite vers bas-gauche)
    for (int i = 0; i <= LIGNES - 4; i++) {
        for (int j = 3; j < COLONNES; j++) {
            if (grille[i][j] == jeton && grille[i + 1][j - 1] == jeton && grille[i + 2][j - 2] == jeton && grille[i + 3][j - 3] == jeton) {
                return true;
            }
        }
    }

    return false;
}

bool grille_pleine(char grille[LIGNES][COLONNES]) {
    for (int j = 0; j < COLONNES; j++) {
        if (grille[0][j] == ' ') {
            return false;
        }
    }
    return true;
}
