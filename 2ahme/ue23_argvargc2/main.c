#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getOP(char text){
    int op = 0;

    if(text == '+'){
            op = 1;

    } else if(text == '-'){
            op = 2;

    } else if(text == '*'){
            op = 3;

    } else if(text == '/'){
            op = 4;
    }

    return op;

}

int getLenghOfNumber(char *text){

    //double f[10] = {10, 111, 12, 12.34};
    int merker = 0;
    int laenge = 0;

    for(int i= 0; (merker = 0); i++){
        if(text[i] >= 0 || text[i] <= 9 || text[i] == '.'){
            laenge++;
        } else {
            merker = 1;
        }
    }
    return laenge;
}

void calc(double num1, double num2, int op, double *result){
    if(op == 1){
        *result = num1 + num2;
    } else if(op == 2){
        *result = num1 - num2;
    } else if(op == 3){
        *result = num1 * num2;
    } else if(op == 4){
        *result = num1 / num2;
    }
}

int parseText(char text[], int length, double *result){

double num1 = 0;
double num2 = 0;
int offset = 0;
int op = 0;
int bracket_open = 0;

    if(*text == '\0'){
        return -1;
    } else {
        op = getOP(text[offset]);
    }

    if(text[offset] == '('){
        bracket_open = 1;
        offset++;
    }

    if(text[offset] == '('){
        offset = offset + parseText(text + offset, length - offset, result);
        return offset;
    }

    if(op == 0){
        if(sscanf(text+offset, "%lf", &num1) != 1){
        return -1;
        }
        offset = offset + getLenghOfNumber(text+offset);
        op = getOP(text[offset]);
    } else {
        num1 = *result;
    }

    if(op == 0){
        return -1;
    }

    offset++;

    if(text[offset] == '('){
        offset = offset + parseText(text+offset, length - offset, &num2);
    } else {
        if(sscanf(text+offset, "%lf", &num2) == 1){
            offset = offset + getLenghOfNumber(text + offset);
        } else {
            return -1;
        }
    }

    if((op < 3) && (text[offset] == '*' || text[offset] == '/') && (text[offset]=! ')')){
        offset = offset + parseText(text + offset, length - offset, &num2);
        calc(num1, num2, op, result);
    } else {
        calc(num1, num2, op, result);
    }

    if(text[offset] == ')'){
        if(bracket_open == 0){
            return offset;
        }
        offset = offset + 1;

        if(*(text - 1) == '*' || *(text - 1) == '/'){
        return offset;
        }

    }

    if(text[offset] == ')'){
        return offset;
    }

    return offset + parseText(text + offset, length - offset, result);

}

int main (int argc, char* argv[]) {
    double result = 0;


    printf("argc= %d\n", argc); //Falsch???????
    for (int i = 0; i < argc; i++)
    {
      printf("  %d: %s\n", i, argv[i]);
    }

    for(int o = 0; o < argc; o++){
        if (strcasecmp("-calc", argv[o + 1]) == 0){
            parseText(argv[2], strlen(argv[2]), &result);
            printf("%lf", result);
        }
    }

  return 0;
}
