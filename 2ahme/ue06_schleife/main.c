#include <stdio.h>
#include <stdlib.h>

int main() {

    //Gauss`sche Summenformel "primitiv errechnet"
    //https://de.wikipedia.org/wiki/Gau%C3%9Fsche_Summenformel//
    int s = 0;


    for (int i = 0; i < 100; i++) {
        s = s + i;
    }

    printf("S = %d\n", s);

    //Fibonacci Zaghlenreihe//
    int i1 = 0, i2 = 1;
    while (i2 < 1000) {
          printf("%d\n", i2);
          int i1Alt = i1;
          i1 = i2;
          i2 = i1Alt + i2;

    }

    return 0;

}
