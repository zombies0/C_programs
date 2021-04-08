#include <stdio.h>
#include <math.h>

float ne(float,float,float);
float f(float);
float fd(float);

int main(){

    float x1,x2,tol;

    printf("\nEnter the value of x1 :  ");
    scanf("%f",&x1);

    printf("\nEnter the value of x2 :  ");
    scanf("%f",&x2);

    printf("\nEnter the Tol limit :  ");
    scanf("%f",&tol);

    if (f(x1) * f(x2) < 0)
        printf("\nTolerance limit reached\nf(x) = %f",ne(x1,x2,tol));

    else
        printf("\nEnter right value of x1 and x2\n");

    return 0;
}

float ne(float x1,float x2,float tol){

    float xc,xp = (x1 + x2) / 2,tol_diff = 10;
    int i = 0;

    while(tol_diff > tol){

        xc = xp - f(xp)/fd(xp);
        tol_diff = fabs(f(xc) - f(xp));

        if (f(xc) == 0) return xc;
        else xp = xc;

        printf("\ni = %d\n",i++);
    }
    
    return xc;
}

float f(float x){ return x * log10(x) - 1.2; }
float fd(float x){ return log10(x) + 0.43429; }