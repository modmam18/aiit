#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInputIntegerValue (char text[]) {
    char s[100];
    int n;
    int rv;

    do {
        printf("%s\n", text);
        fgets(s, 100, stdin);
        n = sscanf(s, "%d", &rv);
    } while (n != 1);

    return rv;
}

double getInputDoubleValue (char text[]) {
    char s[100];
    int n;
    double rv;

    do {
        printf ("%s", text);
        fgets(s, 100, stdin);
        n = sscanf(s, "%lf", &rv);
    } while (n != 1);

    return rv;
}

int getSelectedMenu () {
    char s[100];
    int rv;

    do {
        printf("-----------------\n");
        printf("1...Wuerfel: \n");
        printf("2...Quader: \n");
        printf("3...Kugel: \n");
        printf("4...Programm beenden\n");
        printf(" Auswahl (1-4): ");
        fgets(s, 100, stdin);
        sscanf(s, "%d", &rv);
    } while (rv < 1 || rv > 4);

    return rv;
}

void calcCube () {
    double l;

    printf("\nWuerfel: \n\n");

    do {
        l = getInputDoubleValue("Laenge: ");
    } while (l < 0);

    double V = l * l *l;
    double F = 6 * (l * l);

    printf("Volumen: %.2lf\n", V);
    printf("Flaeche: %.2lf\n", F);

}

void calcCuboid () {
    double h;
    double l;
    double b;
    double F;
    double V;

    printf("\nQuader: \n\n");

    do {
        l = getInputDoubleValue("Laenge: ");
    } while ( l < 0 );

    do {
        b = getInputDoubleValue("Breite: ");
    } while ( b < 0 );

    do {
        h = getInputDoubleValue("Höhe: ");
    } while ( h < 0 );


    V = b * h * l;
    F = 2 * l * b + 2 * l * b + 2 * b *h;

    printf("Volumen: %.2lf\n", V);
    printf("Flaeche: %.2lf\n", F);

}

void calcSphere () {
    double sphered;


    printf("\nKugel: \n");

    do {
        sphered = getInputDoubleValue("Durchmesser: ");
    } while (sphered < 0);

    double flaeche = 4 * M_PI * (sphered / 2) * (sphered / 2);
    double volumen = (4 / 3) * M_PI * ((sphered / 2) * (sphered / 2) * (sphered / 2));

    printf("Volumen: %.2lf\n", volumen);
    printf("Flaeche: %.2lf\n", flaeche);

}


int main() {

    printf("UE11 - Koerperberechnung\n\n");
    while (1 == 1) {
        printf("\n-------------------\n");

        int auswahl = getSelectedMenu();

        switch (auswahl) {
            case 1: {calcCube();
            break;
            }
            case 2: {calcCuboid();
            break;
            }
            case 3: {calcSphere();
            break;
            }
            case 4: {
            return 0;
            }
        }
    }
}
