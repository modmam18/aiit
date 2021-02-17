#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANZAHL 13
#define MAX_ZEICHEN_PRO_NAME 13

void ausgabe(char txt[MAX_ANZAHL][MAX_ZEICHEN_PRO_NAME]){
    for(int i = 0; i < MAX_ANZAHL; i++){
        printf("%s, ", txt[i]);
    }
}

void sortieren(char txt[MAX_ANZAHL][MAX_ZEICHEN_PRO_NAME]){
    char tmp[15];

    for(int i = 0; i < MAX_ANZAHL; i++){
        for(int j = 0; j < MAX_ANZAHL - 1 - i; j++){
            if(strcmp(txt[j], txt[j+1]) > 0){
                strcpy(tmp, txt[j]);
                strcpy(txt[j], txt[j+1]);
                strcpy(txt[j+1], tmp);
            }
        }
    }

}
int main(){


    char namensliste[13][13] = {"Lieschnegg", "Krampl", "Mueller", "Rumpf", "Grassmugg", "Sever", "Modre", "Pommer", "Hoebel", "Pojer", "Muehlbacher", "Kolb", "Kurzmann"};

    //char *namensliste[] = {"Lieschnegg", "Krampl", "Mueller", "Rumpf", "Grassmugg", "Sever", "Modre", "Pommer", "Hoebel", "Pojer", "Muehlbaccher", "Kolb", "Kurzmann",'\0'};

    printf("Unsortiert: \n");
    ausgabe(namensliste);

    printf("\nSortiert:\n");
    sortieren(namensliste);
    ausgabe(namensliste);



    return 0;
}
