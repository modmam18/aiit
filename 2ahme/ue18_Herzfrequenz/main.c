
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_SIZE 10;

double sinsuschwingungen() {
    double feld1[999];
    int i;
    for(i = 0; i < 1000; i++) {
        feld1[i] = sin(((2 * M_PI) / 100) * i + rand() % 10 * (1 / 100));
    }
}



double fenster() {
    double feld2[999];
    int i;
        for(i = 0; i < WINDOW_SIZE; i++);{
            
        
           
       
    }



int main () {

    return 0;
}

