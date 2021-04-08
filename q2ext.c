#include <stdio.h>
#include <math.h>

double find_nth_term(int, int);
int power(int, int);
int intfact(int);

double absl_err(double,double);
double real_err(double,double);
double pcnt_err(double);

int main() {

    int n = 0,x = 0,op = 0,N = 0,X = 0, k = 0;

    double e = 0,abs_err = 0,tr_v = 0,re_err = 0,perc_err = 0;

    double ee[10],abs_er[10],re_er[10],perc_er[10];

    opp:

    printf("\n\nEnter the option\n");
    printf("\n1 to find exponential expression\n2 to calculate absolute error\n3 to calculate realtive error\n4 calculate percentage error\n5 compare error\n6 for exit\n\n");
    
    scanf("%d",&op);
    
        switch (op)
        {
        case 1:
                printf("Enter the value of n\n");

                scanf("%d",&n);

                printf("Enter the value of x\n");

                scanf("%d",&x);

                e = find_nth_term(n,x);

                printf("Ans = %lf",e);

                abs_err = e;


            break;

        case 2:
                
                printf("Enter the true value\n");

                scanf("%lf",&tr_v);

                abs_err = absl_err(abs_err,tr_v);

                printf("absolute error = %lf\n",abs_err);

            break;

        case 3:

                re_err = real_err(abs_err,tr_v);

                printf("realtive error = %lf\n",re_err);

            break;

        case 4:

                perc_err = pcnt_err(re_err);

                printf("percentage error = %3.lf percent \n",perc_err);

            break;

        case 5:

            //printf("\nEnter the N to compare\n");
            //scanf("%d",&N);

            printf("\nEnter the X\n");
            scanf("%d",&X);

            while (k != -5)
            {
                N ++;
                ee[k] = find_nth_term(N,X);
                
                printf("Enter the true value for N = %d and X = %d\n",k+1,X);

                scanf("%lf",&tr_v);

                abs_er[k] = absl_err(ee[k],tr_v);

                re_er[k] = real_err(abs_er[k],tr_v);

                perc_er[k] = pcnt_err(re_er[k]);

                printf("\n%lf\n",perc_er[k]);

                if (perc_er[k] <= 1)
                {
                    goto ccc;
                }

                k++;
                
            }

            ccc:

            printf("\n Error            ");

            for (int j = 0; j < N; j++)
            {
                printf("| n = %d ",j+1);
            }

            printf("\n percentage Error ");

            for (int j = 0; j < N; j++)
            {
                printf("| %3.lf %% ",perc_er[j]);
            }

            break;

        case 6:

            printf("\n\nEXIT\n\n");

            return 0;

        default:

            printf("Enter the right option\n");

            break;
        }

        goto opp;

}

double find_nth_term(int n, int x){

    double e = 0;
    
    if (n == 1){  

        e = (double)(1) + x;  

        return e;

    }
    else{

         while (n != 0){

            e = e + (double)(power(x,n))/(double)(intfact(n));

            if (n == 2)

              return e + 3;
    
            n--;
        }
    }

     return e + 3;
}

int power(int b, int exp){

    int result = 1;

    while (exp != 0){
        result *= b;
        
        exp--;
    }

    return result;

}

int intfact(int n) {
    if (n>=1)
        return n*intfact(n-1);
    else
        return 1;
}

double absl_err(double app_v,double tr_v){

    return fabs(tr_v - app_v);
}

double real_err(double abs_err,double tr_v){

    return abs_err / tr_v;

}
double pcnt_err(double re_err){

    return re_err * 100;

}