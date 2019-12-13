#include <stdio.h>
#include <stdlib.h>

int main()
{

    char s[100];
    double gezahlt;

    printf("UE04 Rechner fuer Umsatzsteuer\n");
    printf("------------------------------\n\n");

    printf(" Gezahlt wurde: ");
    fgets(s, 100, stdin);
    sscanf(s, "%lf", &gezahlt);

    if(gezahlt > 0) {
      double steuer = gezahlt / 1.2 * 0,2;
      printf(" Steuer = %.2f\n", steuer);

      } else {
        printf(" Fehlerhafte Eingabe\n");
        }

    return 0;
}
