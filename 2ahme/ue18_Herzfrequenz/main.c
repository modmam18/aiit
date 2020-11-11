#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_WINDOW_SIZE 100
#define MDATA_MAX_SIZE 1000




double getSinusWithNoise(double f[], int length, double length_period, double amplitude, double offset, double amplitude_noise)
{



    for(int i=0; i <length ; i++){
        f[i] = amplitude * sin(2*M_PI/length_period * i) + offset + (rand() % 100) * amplitude_noise/100;

    }

    return 0;
}

double removeOffset(double f[], int length) {
    double offset = 0;
    double summe;
    int i;

    for(i=0; i < length; i++)
        summe += f[i];

    offset = summe / length;

    for(int i=0; i < length; i++) {
        f[i] -= offset;
    }

    return offset;

}



void calcMovingAveraging(double f[], int length) {
    int n = 10;
    int sum = 0;
    int i;
    int data;

    for(i = 0; i < length; i++) {
        if (i <= 989) {

            for(data = 0; data < n; data++) {
                sum = sum + f[i + data];
            }
            f[i] = sum/n;

        } else {
            break;
        }
        if( i = 990) {
            for(data = 0; data < 9; data++) {
                sum = sum + f[i + data];
            }

        }
    }


}


int main()
{
		double mdata[MDATA_MAX_SIZE];
    double offset = 0.0;


    getSinusWithNoise(mdata, MDATA_MAX_SIZE, 100.0, 2.0, 1.0, 0.0);
    offset = removeOffset(mdata, MDATA_MAX_SIZE);

    if (offset == 1.0)
    	printf("HuHu\n");
    else
    	printf("Offset-Differenz %3.2f", 1.0 - offset);
    return 0;

}

