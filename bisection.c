#include <stdio.h>
#include <math.h>

float f(float);
float root(float,float,float);
float relative_diff(float,float);

int main(){

    float x1,x2,t,y;

    printf("\nEnter the value of x1\n");
    scanf("%f",&x1);
    printf("\nEnter the value of x2\n");
    scanf("%f",&x2);

    printf("\nEnter the tolarence value\n");
    scanf("%f",&t);

    y = root(x1,x2,t); 
    
    printf("\nx = %f \n\n",y);
    return 0;
    
}

float root(float x1, float x2, float t){

    float f1,f2 ;
    float m;
    float mm,mm2,tol_diff = 10;

    f1 = f(x1);
    f2 = f(x2);

    if (f1 == 0.0){
            
        printf("\nValue is found\n");
        return x1;
                
    }       
    else if(f2 == 0.0){
    
        printf("\nValue is found\n");
        return x2;
    }
    
    if ((f1*f2) < 0){

        while(tol_diff > t){
            
            mm2 = mm;
            m = (x1 + x2) / 2.00;           
            mm = f(m);
             
            tol_diff = relative_diff(mm,mm2);

            if (mm == 0.0)

                return m;
            
            else if((f1*mm) < 0)

                 x2 = m;                      
            
            else

               x1 = m;                      
        }
    }else{

        printf("\nEnter the right value b/w positive and negative\n");
        return 0;
    
    }
    
    printf("\nTolerance limit reached\n");        
    return m;
}

float f(float x){

    float k = pow(x,2)+(2.0*x)-15.0;
    return k;
   
}

float relative_diff(float a,float b){

    a = fabsf(a);
    b = fabsf(b);

    return fabsf(a-b);
}