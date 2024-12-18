#include <stdio.h>

#define SIZE 3

void afficher_grille(char grille[SIZE][SIZE]);
int verifier_victoire(char grille[SIZE][SIZE]);
int verifier_match_nul(char grille[SIZE][SIZE]);
void jouer(int joueur, char grille[SIZE][SIZE]);

int main() {
    char grille[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int tour = 0;
    int joueur_actuel = 1;
    int resultat = 0;

    printf("Bienvenue au jeu de morpion !\n\n");

    while (tour < SIZE * SIZE && resultat == 0) {
        afficher_grille(grille);
        jouer(joueur_actuel, grille);

        resultat = verifier_victoire(grille);
        if (resultat != 0) {
            afficher_grille(grille);
            printf("Félicitations ! Joueur %d a gagné !\n", joueur_actuel);
            return 0;
        }

        if (verifier_match_nul(grille)) {
            afficher_grille(grille);
            printf("C'est un match nul !\n");
            return 0;
        }

        joueur_actuel = (joueur_actuel == 1) ? 2 : 1;
        tour++;
    }

    return 0;
}

void afficher_grille(char grille[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", grille[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int verifier_victoire(char grille[SIZE][SIZE]) {
    // Vérifier les lignes
    for (int i = 0; i < SIZE; i++) {
        if (grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2]) {
            return 1;
        }
    }

    // Vérifier les colonnes
    for (int i = 0; i < SIZE; i++) {
        if (grille[0][i] == grille[1][i] && grille[1][i] == grille[2][i]) {
            return 1;
        }
    }

    // Vérifier les diagonales
    if (grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2]) {
        return 1;
    }
    if (grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0]) {
        return 1;
    }

    return 0;
}

int verifier_match_nul(char grille[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grille[i][j] != 'X' && grille[i][j] != 'O') {
                return 0; // Il reste des cases libres
            }
        }
    }
    return 1; // Toutes les cases sont remplies
}

void jouer(int joueur, char grille[SIZE][SIZE]) {
    int choix;
    char symbole = (joueur == 1) ? 'X' : 'O';

    while (1) {
        printf("Joueur %d (%c), entrez le numéro de case où vous voulez jouer : ", joueur, symbole);
        scanf("%d", &choix);

        // Calculer les coordonnées
        int row = (choix - 1) / SIZE;
        int col = (choix - 1) % SIZE;

        // Vérifier si la case est valide
        if (choix >= 1 && choix <= 9 && grille[row][col] != 'X' && grille[row][col] != 'O') {
            grille[row][col] = symbole;
            break;
        } else {
            printf("Case invalide, essayez à nouveau.\n");
        }
    }
}
