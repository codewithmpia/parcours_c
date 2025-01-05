#include <stdio.h>

// Prototype de la fonction pour le calcul de l'impôt
int calcul_impot(int revenu);

int main() {
    int salaire_annuel;

    // Demande du salaire annuel
    printf("Veuillez entrer votre salaire annuel (en euros, positif): ");
    if (scanf("%d", &salaire_annuel) != 1 || salaire_annuel < 0) {
        printf("Entrée invalide. Veuillez entrer un entier positif.\n");
        return 1; // Quitte le programme en cas d'erreur
    }

    // Calcul de l'impôt
    int impot = calcul_impot(salaire_annuel);

    // Affichage du résultat
    printf("Pour un revenu annuel de %d €, vous devez payer %d € d'impôt.\n", salaire_annuel, impot);

    return 0;
}

// Calcul de l'impôt sur le revenu
int calcul_impot(int revenu) {
    int impot = 0;

    if (revenu <= 10064) {
        // Pas d'impôt
        impot = 0;
    } else if (revenu <= 27794) {
        // 11% de la tranche 10,065 - 27,794 €
        impot = (revenu - 10064) * 11 / 100;
    } else if (revenu <= 74517) {
        // 30% de la tranche 27,795 - 74,517 €
        impot = 2076 + (revenu - 27794) * 30 / 100;
    } else if (revenu <= 157806) {
        // 41% de la tranche 74,518 - 157,806 €
        impot = 17567 + (revenu - 74517) * 41 / 100;
    } else {
        // 45% au-delà de 157,806 €
        impot = 61798 + (revenu - 157806) * 45 / 100;
    }

    return impot;
}
