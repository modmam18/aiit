#include <stdio.h>


double *print1DimFeld(double feld[], int anzahl) {
    printf("print1DimFeld:\n");
    for (int i = 0; i < anzahl; i++) {
        printf("feld[%d] %p => %f\n", i, &feld[i], feld[i]);
    }
    printf("\n\n");
    return &feld[0];
}

void eindimensionalesFeld() {

    char text1[] = "Hi"; 
    printf("%s\n", text1);
    printf("text1: sizeof(text1) = %d Bytes\n", (int)sizeof(text1));
    for (int i = 0; i < sizeof(text1); i++) {
        printf(" %d", (int)text1[i]);
    }
    
    printf("\n\n");

    char text2[] = { 'H', 'i', 0};
    printf("text2: %s\n", text2);
    printf("sizeof(text2) = %d Bytes\n", (int)sizeof(text2));
    for (int i =  0; i < sizeof(text2); i++) {
        printf(" %d", (int)text2[i]);
    }
    printf("\n\n");

    char text3[10] = { 'H', 'i', 0};
    printf("text3: %s\n", text3);
    printf("text3: %s\n", text3);
    printf("sizeof(text3) = %d Bytes\n", (int)sizeof(text3));
    for (int i = 0; i < sizeof(text3); i++) {
        printf(" %d", (int)text3[i]);
    }
    printf("\n\n");

    double df1[] = { 1.0, 2.0, 3.0};
    printf("sizeof(df1) = %d Bytes\n", (int)sizeof(df1));
    for (int i = 0; i < sizeof(df1) / sizeof(double); i++) {
        printf(" %f", df1[i]);
    }
    printf("\n\n");

    double df2[5] = { 1.0, 2.0, 3.0, 4.0 };
    printf("sizeof(df2) = %d Bytes\n", (int)sizeof(df2));
    for (int i = 0; i < sizeof(df2) / sizeof(df2[0]); i++) {
        printf(" %f", df2[i]);
    }
    printf("\n\n");

    
    text1[0] = 'H';
    text1[1] = 'a';
    text1[2] = 0;

    printf("%s\n", text1);

    double *df3 = print1DimFeld(df2, sizeof(df2) / sizeof(double));
    printf("sizeof(df3) = %d Bytes\n", (int)sizeof(df3));
    for (int i = 0; i < 5; i++) {
        printf(" %f", df3[i]);
    }
    printf("\n\n");
}

int main() {

    eindimensionalesFeld();

    return 0;
}

