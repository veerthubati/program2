#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main (int argc, char* argv)
{
    int niter = 0;
    double x,y,z,pi;
    int i, count = 0;
    printf("Enter the number of iterations used to estimate pi:");
    scanf("%d", &niter);
    srand(SEED);
    count = 0;
#pragma omp parallel for private(x,y,z) reduction(+:count)
    for ( i=0;i<niter;i++) {
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x*x+y*y;
        if (z<=1) count++;
    }
    pi = (double)count/niter*4;
    printf(" # of trails = %d , estimate of pi is %g \n",niter,pi);
    return 0;
}