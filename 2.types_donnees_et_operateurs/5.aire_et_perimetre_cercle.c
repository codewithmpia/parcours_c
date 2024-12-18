#include <stdio.h>
#define PI 3.14

float aire(int rayon);
float perimetre(int rayon);

// Aire et périmètre d'un cercle
int main () {
    int rayon;
    printf("Veuillez entrer le rayon: ");
    scanf("%d", &rayon);

    printf("L'aire = %.2f\n", aire(rayon));
    printf("Le périmètre = %.2f\n", perimetre(rayon));
    return 0;
}

float aire(int rayon) {
    // aire = PI * R^2
    return PI * rayon * rayon;
}

float perimetre(int rayon) {
    // périmètre = 2 * PI * r
    return 2 * PI * rayon;
}
