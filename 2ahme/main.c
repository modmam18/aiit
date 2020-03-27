#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getInputdoubleValue(char text[]) {
        char s[100];
        int n;
        double rv;

        do {
        printf("%s", text);
        fgets(s, 100, stdin);
        n=sscanf(s, "%lf", &rv);
    } while (n != 1);

    return rv;

}

double getPositiveDoubleInputValue (char text[]) {
        double f1;

        do {
            f1 = getInputdoubleValue(text);
        } while (f1 < 0);

        return f1;
}

double calcForce (double fx, double fy)  {


        double fresultierend = sqrt(fx * fx + fy * fy);

        return fresultierend;
}

int main() {
        double fx = getPositiveDoubleInputValue("fx: ");
        double fy = getPositiveDoubleInputValue("fy: ");
        double ergebnis = calcForce(fx, fy);

        printf("Ergebniss: %.2lf\n", ergebnis);

        return 0;
}
