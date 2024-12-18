#include <stdio.h>

// Prototypes des fonctions de conversion
float kilometre_en_mile(float km);
float kilogramme_en_livre(float kg);
float celsius_en_fahrenheit(float celsius);
float fahrenheit_en_celsius(float fahrenheit);
float litre_en_gallon(float litre);
float gallon_en_litre(float gallon);
float baril_en_litre(float baril);
float litre_en_baril(float litre);

int main() {
    int choix;
    float valeur, resultat;

    // Menu de conversion
    printf("Choisissez une conversion :\n");
    printf("1. Kilomètres en Miles\n");
    printf("2. Kilogrammes en Livres\n");
    printf("3. Celsius en Fahrenheit\n");
    printf("4. Fahrenheit en Celsius\n");
    printf("5. Litres en Gallons\n");
    printf("6. Gallons en Litres\n");
    printf("7. Barils en Litres\n");
    printf("8. Litres en Barils\n");
    printf("Votre choix (1-8) : ");

    if (scanf("%d", &choix) != 1 || choix < 1 || choix > 8) {
        printf("Erreur : veuillez entrer un choix valide entre 1 et 8.\n");
        return 1;
    }

    // Traitement selon le choix
    switch (choix) {
        case 1:
            printf("Entrez la distance en kilomètres : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer une distance valide.\n");
                return 1;
            }
            resultat = kilometre_en_mile(valeur);
            printf("%.2f kilomètres = %.2f miles\n", valeur, resultat);
            break;

        case 2:
            printf("Entrez le poids en kilogrammes : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer un poids valide.\n");
                return 1;
            }
            resultat = kilogramme_en_livre(valeur);
            printf("%.2f kilogrammes = %.2f livres\n", valeur, resultat);
            break;

        case 3:
            printf("Entrez la température en Celsius : ");
            if (scanf("%f", &valeur) != 1) {
                printf("Erreur : veuillez entrer une température valide.\n");
                return 1;
            }
            resultat = celsius_en_fahrenheit(valeur);
            printf("%.2f°C = %.2f°F\n", valeur, resultat);
            break;

        case 4:
            printf("Entrez la température en Fahrenheit : ");
            if (scanf("%f", &valeur) != 1) {
                printf("Erreur : veuillez entrer une température valide.\n");
                return 1;
            }
            resultat = fahrenheit_en_celsius(valeur);
            printf("%.2f°F = %.2f°C\n", valeur, resultat);
            break;

        case 5:
            printf("Entrez le volume en litres : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer un volume valide.\n");
                return 1;
            }
            resultat = litre_en_gallon(valeur);
            printf("%.2f litres = %.2f gallons\n", valeur, resultat);
            break;

        case 6:
            printf("Entrez le volume en gallons : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer un volume valide.\n");
                return 1;
            }
            resultat = gallon_en_litre(valeur);
            printf("%.2f gallons = %.2f litres\n", valeur, resultat);
            break;

        case 7:
            printf("Entrez le nombre de barils : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer un nombre de barils valide.\n");
                return 1;
            }
            resultat = baril_en_litre(valeur);
            printf("%.2f barils = %.2f litres\n", valeur, resultat);
            break;

        case 8:
            printf("Entrez le nombre de litres : ");
            if (scanf("%f", &valeur) != 1 || valeur < 0) {
                printf("Erreur : veuillez entrer un nombre de litres valide.\n");
                return 1;
            }
            resultat = litre_en_baril(valeur);
            printf("%.2f litres = %.2f barils\n", valeur, resultat);
            break;

        default:
            printf("Erreur inattendue.\n");
            return 1;
    }

    return 0;
}

// Conversion de kilomètres en miles
float kilometre_en_mile(float km) {
    return km * 0.621371; // 1 kilomètre = 0.621371 miles
}

// Conversion de kilogrammes en livres
float kilogramme_en_livre(float kg) {
    return kg * 2.20462; // 1 kilogramme = 2.20462 livres
}

// Conversion de Celsius en Fahrenheit
float celsius_en_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32; // °C vers °F
}

// Conversion de Fahrenheit en Celsius
float fahrenheit_en_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9; // °F vers °C
}

// Conversion de litres en gallons
float litre_en_gallon(float litre) {
    return litre * 0.264172; // 1 litre = 0.264172 gallons
}

// Conversion de gallons en litres
float gallon_en_litre(float gallon) {
    return gallon * 3.78541; // 1 gallon = 3.78541 litres
}

// Conversion de barils (US) en litres
float baril_en_litre(float baril) {
    return baril * 159.0; // 1 baril (US) = 159 litres
}

// Conversion de litres en barils (US)
float litre_en_baril(float litre) {
    return litre / 159.0; // 1 baril (US) = 159 litres, donc litres vers barils : litres / 159
}
