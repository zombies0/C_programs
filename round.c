#include <stdio.h>
#include <math.h>

double roun(double , int);
int power(int,int);

int main(){
    
    double decimal_no = 0;
    int decimal_place = 1;

    printf("Enter the decimal No.\n");
    scanf("%lf",&decimal_no);

    printf("Enter the Decimal places\n");
    scanf("%d",&decimal_place);

    decimal_no = roun(decimal_no,decimal_place);

    printf("round off = %lf\n",decimal_no);

    return 0;
    
}

double roun(double x, int n){

    int c;

    x = x * power(10,n);

    c = x;

    c = c % 10;

    if (c < 5)
    {
        x = (double)(x - 1);
    }
    else{
        
        x = (double)(x + 1);
    }
    

    printf("\nval of x = %lf\n",x);

    x = floor(x) / power(10,n);

    return x;
}

int power(int base,int exp){

    int result = 1;

    while (exp != 0){

        result = result * base;

        --exp;

    }

    return result;
}
