#include <stdio.h>

float celcius_to_fahrenheit(float degre);
float fahrenheit_to_celcius(float degre);

// Convertisseur simple de température
int main () {
    float temp;
    printf("Entrer la température à convertir: ");
    scanf("%f", &temp); // Utiliser %f pour les entrées à virgule flottante
    printf("%.2f °C = %.2f °F\n", temp, celcius_to_fahrenheit(temp));
    printf("%.2f °F = %.2f °C\n", temp, fahrenheit_to_celcius(temp));
    return 0;
}

float celcius_to_fahrenheit(float degre) {
    return (degre * 1.8) + 32;
}

float fahrenheit_to_celcius(float degre) {
    return (degre - 32) / 1.8;
}
