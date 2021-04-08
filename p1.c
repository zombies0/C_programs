#include<stdio.h>
#include<math.h>

float bi(float,float,float);
float f(float);

int main(){

    float x1,x2,tol;

    printf("\nEnter the value of x1 : ");
    scanf("%f",&x1);

    printf("\nEnter the value of x2 : ");
    scanf("%f",&x2);

    printf("\nEnter the Tol limit : ");
    scanf("%f",&tol);

    if (f(x1)*f(x2) < 0)
        printf("\nTolerance limit reached\nf(x) = %f",bi(x1,x2,tol));  
    
    else
        printf("\nEnter right value of x1 and x2\n");
    
    return 0;
}

float bi(float x1,float x2,float tol){

    float mid, tol_diff = 10;
    int i = 0;

    while(tol_diff > tol){

        mid = (x1 + x2) / 2;

        if (f(mid) == 0) return mid;
        else if (f(mid)*f(x1) < 0) x2 = mid;
        else x1 = mid;
        
        tol_diff = fabsf(f(x1) - f(x2));
        printf("\ni = %d\n",i++);

    }
    
    return  mid; 
}

float f(float x){ return pow(x,2) + 2*x - 15; }