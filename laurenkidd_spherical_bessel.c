#include <stdio.h> 
#include <math.h>      /* pow */  /* sin */ /* cos */
#define pi 3.14159265358979323846
double bessel_up(double x, int l);
double bessel_down(double x, int n, int lmax);   

int main(void){ 

    double x = 5*pi/180.;
    int lmax = 15;
    for ( int l = 0 ; l < lmax; l++ ) {
        printf("%s %d %s %le %s %le\n","l",l, "up" ,bessel_up(x,l),"down",bessel_down(x,l,lmax));
    }
    //double j[lmax+1];
    //j =  bessel_down(x,lmax);
    //for ( int l = 0 ; l < lmax+1; l++ ) {
      //  printf("%s %d  %le\n","bessel_down",l,bessel_down(x,l,lmax));
    //}
    return 0; 
} 

double bessel_up(double x, int l) {  
// (l+1)th (i.e.) upward term of spherical bessel function. 
// // where l starts at 1. 
     switch(l){
         case 0:
             return sin(x)/x;                 
         case 1:
             return sin(x)/pow(x,2) - cos(x)/x;                 
         default:  
             return (2.*(l-1)+1.)*bessel_up(x,l-1) - bessel_up(x,l-2)*x;
     }

  }

double bessel_down(double x, int n, int lmax) {  
// (l-1)th (i.e.) downward term of spherical bessel function. 
// // where l starts at lmax. 
     //start with some initial values for j(lmax) and j(lmax+1)
     double j[lmax+1];
     j[lmax] = 1.;     //j(lmax)
     j[lmax+1] = 0.;     //j(lmax +1)
     for ( int l = lmax ; l > 0; l-- ) {
         j[l-1] = (2.*l+1.)*j[l] - x*j[l+1];
         //j1 = j0;
         //j2 = j1;
     }
     double scale = (sin(x)/x)/j[0]; //rescale j[] so j[0] = sin(x)/x
     return (j[n]*scale); 
 }    
