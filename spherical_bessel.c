#include <stdio.h> 
#include <math.h>      /* pow */  /* sin */ /* cos */
#define pi 3.14159265358979323846
double bessel_up(double x, int l);
double bessel_down(double x, int n, int lmax);   

int main(void){ 

    double x = pi/6.; //define value for x, arbitrarily assigned to pi/6 radians
    int lmax = 15;       //define order for upward and downward recursion
    for ( int l = 0 ; l < lmax; l++ ) {
        printf("%s %d %s %le %s %le\n","l",l, "up" ,bessel_up(x,l),"down",bessel_down(x,l,lmax));
    }
    return 0; 
} 
//-----------------end of main ---------------------//

double bessel_up(double x, int l) {  
// (l+1)th (upward) term of spherical bessel function. 
// // where l starts at 1. 
     switch(l){
         case 0:
             return sin(x); //x*j0                
         case 1:
             return sin(x)/x - cos(x);   //x*j1                 
         default:  
             return (2.*(l-1)+1.)*bessel_up(x,l-1) - bessel_up(x,l-2)*x;
     }

  }

double bessel_down(double x, int n, int lmax) {  
// (l-1)th (downward) term of spherical bessel function. 
// // where l starts at lmax.     
     double j[lmax+1];
     //start with some initial values for j(lmax) and j(lmax+1)
     j[lmax] = 1.;     //j(lmax)
     j[lmax+1] = 0.;     //j(lmax +1)
     for ( int l = lmax ; l > 0; l-- ) {
         j[l-1] = (2.*l+1.)*j[l] - x*j[l+1];
     }
     double scale = sin(x)/j[0]; //rescale j[] so x*j[0] = sin(x)
     return (j[n]*scale); 
 }    
