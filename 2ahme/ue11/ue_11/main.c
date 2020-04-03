#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInputIntergerValue(char text[]) {
    char s[100];
    int n;
    int rv;

    do {
        printf("%s", text);
        fgets(s, 100, stdin);
        n=sscanf(s, "%d", &rv);
    } while (n!=1);

   return rv;
}

double getInputDoubleValue (char text[]) {
    char s[100];
    int n;
    double rv;

    do {
        printf("s: ", text);
        fgets(s, 100, stdin);
        n=sscanf(s, "%lf", &rv);
    } while (n!=1);

    return rv;
}

int getSelectMenu () {
    double rv;

    do {

        printf("-------------------");
        printf("1...Wuerfel");
        printf("2...Quader");
        printf("3...Kugel");
        printf("4...Programm beenden");

        rv = getInputIntergerValue("Auswahl (1-4):");

    } while ( rv < 1 || rv > 4);

    return rv;
}

double calcCube () {
    double l;

    printf("Wuerfel:\n");

    do {

        double l = getInputDoubleValue("Laenge: ");

    } while (l < 0);

    double V = l * l * l;
    double F = 6 * (l * l);

    printf("Volumen: %.2lf\n", V);
    printf("Oberflaeche: %.2lf\n", F);

    return 0;
}

double calcCuboid () {
    double l;
    double h;
    double b;


    printf("Quader:\n");

    do {
        l = getInputDoubleValue("Länge: ");
    } while (l < 0);

    do {
        b = getInputDoubleValue("Breite: ");
    } while (b < 0);

    do {
        h = getInputDoubleValue("Höhe: ");
        } while (h < 0);

    double V = b * h * l;
    double F = 2 * l * b + 2 * l * h + 2 * b * h;

    printf("Volumen: %.2lf\n", V);
    printf("Oberflaeche: %2.lf\n", F);

    return 0;
}

double calcSphere () {

    printf("Kugel:\n");

    do {
        double d = getInputDoubleValue("Durchmesser :");
    } while (d < 0);

    double r = d / 2;
    double V = 4 / 3 * M_PI * r * r *r;
    double F = 4 * M_PI * r * r;

    printf("Volumen: %.2lf\n", V);
    printf("Flaeche: %.2lf\n", F);

    return 0;
}




int main() {

    int wahl

    wahl = getSelectMenu();

    while (1 == 1) {

    switch(wahl); {

        case 1: calcCube(); break;
        case 2: calcCuboid(); break;
        case 3: calcSphere(); break;
        case 4: return 0;

    }

    }

        return 0;
}




    printf("Hello world!\n");
    return 0;
}
