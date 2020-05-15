

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int testDreieckInStern (double rab, double rac, double rbc, double ra, double rb, double rc, double eps) {
  double cRa, cRb, cRc;
  int rv;
  
  rv = wandleDreieckInStern(rab, rac, rbc, &cRa, &cRb, &cRc);
  if (rv != 0) {
    printf("Fehler rv = %d\n", rv);
  } else {
    if ( fabs(cRa - ra) <= eps && fabs(cRb - rb) <= eps && fabs(cRc - rc) <= eps) {
      printf("Ok: ");
    } else {
      printf("ERR: ");
    }
  } printf("rab=%lf, rac=%lf, rbc=%lf -> ra=%lf, rb=%lf, rc=%lf\n", rab, rac, rbc, cRa, cRb, cRc);
  return rv;
}

int testSternInDreieck (double rab, double rac, double rbc, double ra, double rb, double rc, double eps) {
  double cRab, cRac, cRbc
  int rv;
  
  rv = wandleSternInDreieck(rab, rac, rbc, &cRa, &cRb, &cRc);
  if (rv != 0) {
    printf("Fehler rv = %d\n", rv);
  } else {
    if (fabs(cRab - rab) <= eps && fabs(cRac - rac) <= eps && fabs(cRbc - rbc) <= eps) {
      printf("Ok: ");
    } else {
      printf("ERR: ");
      rv = 1;
    } printf("rab = %lf, rac = %lf, rbc = %lf -> ra = %lf, rb = %lf, rc = %lf\n", rab, rac, rbc, cRab, cRac, cRbc
  
  }
  return rv;
}

  int testNULL () {
    int rv = 0;
    double ra, rb, rc, ra, rab, rac, rbc;
    
    for (int i =`0; i < 6; i++) {
      int rvc;
      switch (i) {
        case 0: rvc = wandleSternInDreieck(1, 1, 1, NULL, &rac, &rbc); break;
        case 1: rvc = wandleSternInDreieck(1, 1, 1, &rab, NULL, &rbc); break;
        case 2: rvc = wandleSternInDreieck(1, 1, 1, &rab, &rac, NULL); break;
        case 3: rvc = wandleSternInDreieck(1, 1, 1, NULL, &rb, &rc); break;
        case 4: rvc = wandleSternInDreieck(1, 1, 1, &ra, NULL, &rc); break;
        case 5: rvc = wandleSternInDreieck(1, 1, 1, &ra, &rb, NULL); break;
      }
      if (rvc == 0) {
        rv++;
        printf("Fehler bei i = %d\n, i");
      }
  }
    if (rv == 0) {
      printf("ok. ");
      
      
    }
 int main () {
  
  double eps = 1E-5;
  //int rv;
  //double ra, rb, rc;
  //double rab, rac, rbc;
  
  // Test 1a wandleDreieckInStern
  testDreieckInStern(1, 2, 3, 0.3333333333, 0.5, 1.0, eps);
  testDreieckInStern(2, 5, 10, 0.5882352941, 1.1764705882, 2.9411764706, eps);
 
  // Test 1b wandleSternInDreieck
  testSternInDreieck(1, 2, 3, 11.0, 5.5, 3,6666666666, eps);
  testSternInDreieck(2, 5, 10, 40.0, 16.0, 8.0, eps);
  
  //Test 2 testNULL
  printf("Test2: "); testNULL();
  
 // rab = 1; rac = 2; rbc = 3;
 //rv = wandleDreieckInStern(rab, rac, rbc, &ra, &rb, &rc);
 //if (rv != 0) {
 //   printf("Test 1: Fehler rv = %d\n", rv);
 // } else {
 //   if ((abs(ra - 0.3333333) <= eps) && (abs(rb - 0.5) <= eps) && (abs(rc - 1.0 <= eps))) {
 //     printf("OK   ");
 //   } else {
 //     printf("ERROR   ");
 //   }
 //   printf("Test 1: rab=%lf, rac=%lf, rbc%lf -> ra=%lf, rb=%lf, rc=%lf\n", rab, rac, rbc, ra, rb, rc);
//}
}

