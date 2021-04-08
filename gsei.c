// Gauss Jordan Method

#include<stdio.h>
#include<stdlib.h>

int main(){

    float *arr,ki;
    int row = 0, col = 0;

    printf("\nEnter the size of row :  ");
    scanf("%d",&row);
    col = row + 1;

    arr = (float*)malloc(row * col * sizeof(float));

    printf("\n\nEnter the equation in array\n\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%f",((arr + i*col) +j ));

    printf("\nMatrics\n\n========================================\n\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
    
            if(j > row-1)
                printf(" =   ");

            printf("%.2f   ",*(arr + i*col +j ));
    
        }
        printf("\n\n\n");
    }

    // Converting matrix into Diagonal Matrix

    for (int i = 0; i < row; i++) 

        for (int j = 0; j < row; j++) {

            ki =*(arr + j*col +i ) / *(arr + i*col + i );

            for (int k = 0; k < col; k++) 

                if(i != j)

                    *(arr + j*col + k ) = *(arr + j*col + k ) - ( *(arr + i*col + k ) * (ki) );
        }

    printf("========================================\n\n");
    // Printing Diagonal Matrix
    printf("Diagonal MATRICS\n\n========================================\n\n");

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){

            if(j > row-1)
                printf(" =   ");

            printf("%.2f   ",*(arr + i*col +j ));

        }

        printf("\n\n\n");
    }

    printf("========================================\n\n");
    // Reverse substitution of Diagonal Matrix
    printf("=============");

    for (int i = 0;i < row ;i++)

        printf("\n\n%d  =  %.2f",i+1,*(arr + i*col + row) / *(arr + i*col + i) );
    
    printf("\n\n=============\n\n");
    free(arr);
    return 0;

}