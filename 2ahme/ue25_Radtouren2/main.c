#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANZAHL_TOUREN 100

struct datum {

    int tag;
    int monat;
    int jahr;
};

struct daten{

    char name[50];
    int laenge;
    int anzahl;
    int hoehe;

};
struct radtour {

    struct daten datentour;
    struct datum datumtour;
};

int eingabeZahl(char* txt, int ug, int og, int *zahl){

int ok = 1;
char s[100];

    do{
        if(!ok){
          printf(" Bitte geben sie eine zahl zwischen %d und %d ein", ug, og);
        }
        printf("%s", txt);
        fgets(s, sizeof(s), stdin);
        fflush(stdin);

        if(s[0] == '<'){
            return 0;
        }

        ok = sscanf(s, "%d", zahl);
        ok &=(*zahl >= ug) && (*zahl <= og);

    }while(!ok);

    return 1;
}

int eingabeString(char *txt, char *texteingabe, int len){

int ok = 1;
    char s[100];

    do{
         if(!ok){
          printf(" Ihre Eingabe ist zu lang. Bitte geben Sie einen Text mit maximal %d Zeichen ein \n", len);
        }
        printf("%s", txt);
        fgets(s, len, stdin);
        fflush(stdin);

        if( s[0] == '<'){
            return 0;
        }
        ok = (strlen(s) > 0) && (strlen(s) < (len-1));
    }while(!ok);
    strcpy(texteingabe, s);
    texteingabe[strlen(s)-1] = '\0';
    return 1;
}

int eingabedatum(struct datum *datumtour){

  int tag = 0;
  int monat = 0;
  int jahr = 0;

printf("\n\n\tBitte geben Sie das Datum der Tour ein: \n");

if(eingabeZahl("\nTag: ", 1, 31, &tag)){
  if(eingabeZahl("\nMonat: ", 1, 12, &monat)){
    if(eingabeZahl("\nJahr: ", 1, 2021, &jahr)){

      datumtour->tag = tag;
      datumtour->monat = monat;
      datumtour->jahr = jahr;

      return 1;
      }
    }
  }
  return 0;
}

int eingabedaten(struct daten *datentour){

char nt[100];
int l = 0;
int f = 0;
int hm = 0;

printf("\n\n\tBitte tragen Sie nun die Daten Ihrer Tour ein: \n");

if(eingabeString("\nName der Tour: ", nt, 100)){
  if(eingabeZahl("\nL�nge in km: ", 1, 9999, &l)){
    if(eingabeZahl("\nAnzahl der Fahrten: ", 1, 9999, &f)){
      if(eingabeZahl("\nH�henmeter der Strecke: ", 1, 9999, &hm)){

        strcpy(datentour->name, nt);
        datentour->laenge = l;
        datentour->anzahl = f;
        datentour->hoehe = hm;

        return 1;
        }
      }
    }
  }
  return 0;
}

int neuetour(struct radtour *tour, int *anzahl){


int merker = 0;

    do{

    merker = 0;
    if(eingabedaten(&tour[*anzahl].datentour)){
      for(int i = 0; i < *anzahl; i++){
        if(strcmp(tour[*anzahl].datentour.name, tour[i].datentour.name) == 0){
          printf("\n\n Tour existiert bereits, bitte w�hlen Sie einen anderen Namen!");
            merker++;
          }
        }
      }
    }while(merker > 0);
      if(eingabedatum(&tour[*anzahl].datumtour)){

      *anzahl = *anzahl + 1;
     return 1;
    }
  return 0;
}

void ausgabeSchueler(struct radtour tour[], int anzahl){

    printf("\nIhre Radtouren\n");
    printf("============================================================================");
    for(int i = 0; i < anzahl; i++){
        printf("\n%d. \t%s %d %d %d  | %d.%d.%d", i+1,
               tour[i].datentour.name,
               tour[i].datentour.laenge,
               tour[i].datentour.anzahl,
               tour[i].datentour.hoehe,

               tour[i].datumtour.tag,
               tour[i].datumtour.monat,
               tour[i].datumtour.jahr);
    }
}

void sortieren(struct radtour *radtouren, struct radtour *radtouren2, int anzahl){


 for(int i = 0; i < anzahl -1; i++){
        for(int j = 0; j < anzahl -1 -i; j++){
          if(strcmp(radtouren[j].datentour.name, radtouren[j + 1].datentour.name) > 0){

            radtouren2[0] = radtouren[j];
            radtouren[j] = radtouren[j + 1];
            radtouren[j + 1] = radtouren2[0];


      }
    }
  }
}


int suchen(struct radtour *tour, int anzahl){

char tmp[100];
char tmp2[100];
char tmp3[5];
int merker = 0;
int merker2 = 0;
int i = 0;

eingabeString("\nSuche: ", tmp, 100);
do{

  strncpy(tmp2, tour[i].datentour.name, strlen(tmp));

    if(strcmp(tmp, tmp2) == 0){
      printf("\nErgebnis: %s", tour[i].datentour.name);
      merker ++;
      i++;
      merker2 = i;

    }else{
    i++;
    }

  }while(i != anzahl);

  if(merker > 1){
    printf("\nMehrere Ergebnisse, bitte genauer!\n");
    return -1;
  }

  else if(merker == 0){
    printf("\nKein Ergebniss, bitte wiederholen!\n");
    return -1;
  }

  else if(merker == 1){
      printf("\n\nBitte w�hlen Sie: ");
      printf("\n====================");
      printf("\nJ f�r best�tigen ");
      printf("\nN f�r abbrechen ");

      eingabeString("\n\nWahl:", tmp3, 5);

      if (strcmp(tmp3, "J") == 0){
       return merker2;
        }


      else if (strcmp(tmp3, "N") == 0){
          return 0;

      }
  }
return 1;
}


void durchschnitt(struct radtour *tour, int anzahl, double *durchschnitt){

int ergebnis = 0;

  for(int i = 0; i < anzahl; i++){
    ergebnis = ergebnis + tour[i].datentour.laenge;
  }

  *durchschnitt = ergebnis/anzahl;

}

int radtourenLaden(struct radtour *radtouren){
    char s[100];
    int  counter = 7;
    int n = 0;

    FILE *f = fopen("Radtour.ods","r");

    for(int i = 0; i < (counter-1); i++){
        while(sscanf(f, "%s", s)!= NULL){

            char *p = strtok(s, "\t");
            if(p == NULL){
                break;
            }
            strcpy(radtouren[i].datentour.name, p);

            p = strtok(NULL,"\t");
            if(p == NULL){
                break;
            }
            sscanf(p,"%d", radtouren[i].datentour.laenge);

            p = strtok(NULL,"\t" );
            if(p == NULL){
                break;
            }
            sscanf(p, "%d", radtouren[i].datentour.hoehe);

            p = strtok(NULL,"\t" );
            if(p == NULL){
                break;
            }
            sscanf(p, "%d", radtouren[i].datentour.anzahl);

            p = strtok(NULL,"." );
            if(p == NULL){
                break;
            }
            sscanf(p, "%d", radtouren[i].datumtour.tag);

            p = strtok(NULL,"." );
            if(p == NULL){
                break;
            }
            sscanf(p, "%d", radtouren[i].datumtour.monat);

            p = strtok(NULL,"." );
            if(p == NULL){
                break;
            }
            sscanf(p, "%d", radtouren[i].datumtour.jahr);

        }
        fclose(f);
    }


  return (counter-1);
}

void radtourSpeichern(struct radtour *radtouren, int anzahl){
    FILE *f = fopen("Radtour.ods","w");


    fprintf(f,"Name\t Laenge\t Hoehenmeter\t Anzahl\t Datum\n");
    for(int m = 0; m < anzahl; m++){

     fprintf(f,"%s \t %d \t %d \t %d \t %d.%d.%d \n",
             radtouren[m].datentour.name,
             radtouren[m].datentour.laenge,
             radtouren[m].datentour.hoehe,
             radtouren[m].datentour.anzahl,

             radtouren[m].datumtour.tag,
             radtouren[m].datumtour.monat,
             radtouren[m].datumtour.jahr);
     }
    fclose(f);
}
int main(){

   struct radtour radtouren[MAX_ANZAHL_TOUREN]= {

        {{"Radtour 1", 1000, 6, 350}, {11, 11, 2003}} ,
        {{"Aadtour 2", 1500, 5, 567}, {24, 04, 2020}} ,
        {{"Uadtour 3", 1000, 4, 250}, {1, 11, 2003}} ,
        {{"Oadtour 4", 1600, 3, 567}, {23, 04, 2020}} ,
        {{"Eadtour 5", 1500, 2, 567}, {23, 04, 2020}} ,
        {{"Iadtour 6", 1500, 1, 689}, {23, 04, 2020}} ,

    };

  struct radtour radtouren2[MAX_ANZAHL_TOUREN]= {
    };

int tourenanzahl = 6;
int n = 0;
int a = 4;
double durchsch = 0;

do{

printf("\n\nMenue: ");
printf("\n1.........Tour hinzuf�gen:");
printf("\n2.........Touren ausgeben:");
printf("\n3............Tour l�schen:");
printf("\n4.................Beenden:");
printf("\n5...................Laden:");
printf("\n6...............Speichern:");


//eingabeZahl("\n\nMenue-Auswahl: ", 1, 6, &a);

  switch(a) {

 case 1:
   neuetour(radtouren, &tourenanzahl);
      ausgabeSchueler(radtouren, tourenanzahl);

    break;

 case 2:

      sortieren(radtouren, radtouren2, tourenanzahl);
      durchschnitt(radtouren, tourenanzahl, &durchsch);
      ausgabeSchueler(radtouren, tourenanzahl);
      printf("\n\n Durchschnittliche L�nge Ihrer Touren: %.3lf", durchsch);

    break;

 case 3:

      do{
        n = suchen(radtouren, tourenanzahl);
      }while(n == (-1));

        if(n == 0){
        break;
        }

      for(int i = 0; i < tourenanzahl; i++, n++){
        radtouren[n - 1] = radtouren[n];
      }
      tourenanzahl = tourenanzahl - 1;
      ausgabeSchueler(radtouren, tourenanzahl);
      break;

    case 4:

     tourenanzahl = radtourenLaden(radtouren);
     printf("%d", tourenanzahl);

    break;

    case 5:

     radtourSpeichern(radtouren, tourenanzahl);

   break;

  }
}while(a != 6);

printf("Programm beendet!");
return 0;
}
