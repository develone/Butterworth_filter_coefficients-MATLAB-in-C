#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "iir.h"

double *binomial_mult(int n, double *p) {
int i,j;
double *a;
printf("rcof 0x%x \n",p);
/*
allocates 2*6 * 8 = 96 bytes and sets to zero
*/
a = (double *)calloc( 2 * n, sizeof(double) );
    for( i = 0; i < n; ++i )
    {
	for( j = i; j > 0; --j )
	{
	printf("i = %d j = %d \n", i,j);
            printf("1st eq indexs\n");

	    a[2*j] += p[2*i] * a[2*(j-1)] - p[2*i+1] * a[2*(j-1)+1];
            printf("a (2 * j) = %d \n",(2 * j));
	    printf("p (2 * i) = %d a (2*(j-1)) = %d \n",(2*i),(2*(j-1)));
	    printf("p ((2 * i) + 1) = %d a (2*(j-1) + 1) = %d \n",((2 * i) + 1),(2*(j-1) + 1));
            printf("2nd eq indexs\n");

	    a[2*j+1] += p[2*i] * a[2*(j-1)+1] + p[2*i+1] * a[2*(j-1)];
            printf("a ((2*j)+1) = %d \n",((2*j)+1));
            printf("a = %d \n",((2*j)+1));
            printf("p ((2 * i)+1) = %d a (2*(j-1)) = %d \n",((2*i)+1),(2*(j-1)+1));
            printf("p ((2 * i)+1 = %d a (2*(j-1)) = %d \n",((2*i)+1),((2*(j-1))));

	}
	a[0] += p[2*i];
	a[1] += p[2*i+1];
    }
return( a );

}

int main() {
int n = 6;
double *dcof;
double *rcof;
	rcof = (double *)calloc( 2 * n, sizeof(double) );
	printf("rcof 0x%x \n",rcof);
	dcof = binomial_mult( n, rcof );
	free( rcof );

}
