#include <stdio.h>
#include <math.h>

float f(float);
float fd(float);
float new_root(float,float,float);

int main(){

    float x1,x2,tol,y = 9;

    printf("\nEnter the value of x1\n");
    scanf("%f",&x1);
    printf("\nEnter the value of x2\n");
    scanf("%f",&x2);

    printf("\nEnter the tolarence limit\n");
    scanf("%f",&tol);

    y = new_root(x1,x2,tol);

    printf("\nx = %f\n\n",y);

    return 0;

}

float f(float x){

    return x * log10(x) - 1.2;
}

float fd(float x){

    return log10(x) + 0.43429;
}

float new_root(float x1,float x2,float tol){

   printf("\nflag 1 \n");

    if ( f(x1) == 0.0 )

        return x1;       

    else if(f(x2) == 0.0)

        return x2;
    
    printf("\nflag 2 \n");

    if ( (f(x1) * f(x2) ) < 0){

        float xp = ( x1 + x2 ) / 2.0;
        float xc = xp;

        do{
            xp = xc;

            xc = xp - (f(xp))/(fd(xp));

            if (f(xc) == 0.0)

                return xc;
            

        }while (fabsf(xc-xp) > tol);

        return xc;
        
    }else
    
        printf("\n\nError: Enter the rigth value b/w\n\n");
        
    return 0;
}