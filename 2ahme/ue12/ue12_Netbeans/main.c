

#include <stdio.h>
#include <stdlib.h>

int wandleDreieckInStern (double rab, double rac, double rbc, double *pRa, double *pRb, double *pRc) {
      
  double r = rac + rab + rbc;
  
  if (pRa != NULL && pRb != NULL && pRc != NULL && r > 0 && rac > 0 && rab > 0 && rbc > 0) {
    *pRa = (rab * rac) / (rac + rab + rbc);
    *pRb = (rab * rbc) / (rac + rab + rbc);
    *pRc = (rac * rab) / (rac + rab + rbc);
    return 0;
  } else {
    return 1;
  }
}

int wandleSternInDreieck (double *pRab, double *pRac, double *pRbc, double ra, double rb, double rc){
  
  if (pRac != NULL && pRab != NULL && pRbc != NULL && ra > 0 && rb > 0 && rc > 0) {
    *pRac = (ra * rb + rb * rc + rc + ra) / rb;
    *pRab = (ra * rb + rb * rc + rc * ra) / rc;
    *pRbc = (ra * rb + rb * rc + rc * ra) / ra;
    return 0;
  } else {
    return 1;
  }
}

int main () {
  int f1;
  int f2;
  double ra, rb, rc;
  double rab, rac, rbc;
  
  f1 = wandleDreieckInStern(10, 15, 20, &ra, &rb, &rc);
  f2 = wandleSternInDreieck(25, 30, 35, &rab, &rac, &rbc);
  
  return 0;
}

