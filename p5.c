#include<stdio.h>
#include<math.h>

float it(float,float,float);
float f(float);
float phi(float);

int main(){

    float x1,x2,tol;

    printf("\nEnter the value of x1 :  ");
    scanf("%f",&x1);

    printf("\nEnter the value of x2 :  ");
    scanf("%f",&x2);

    printf("\nEnter the value of tol :  ");
    scanf("%f",&tol);

    if (f(x1) * f(x2) < 0)
        printf("\nTolerance limit reached\nf(x) = %f",it(x1,x2,tol));
    else 
        printf("\nEnter right value of x1 and x2\n");

    return 0;
}

float it(float x1,float x2,float tol){

    float xc,xp = (x1+x2)/2,tol_diff = 10;
    int i = 0;

    while (tol_diff > tol){

        xc = phi(xp);

        if (f(xc) == 0) return xc;

        tol_diff = fabs(f(xc) - f(xp));
        xp = xc;

        printf("\ni  = %d xc = %f\n",i++,xc);
    }

    return xc;
}

float f(float x){ return cos(x) - 3*x + 1;}
float phi(float x){ return (cos(x) + 1) / 3 ;}