#include<stdio.h>
#include<stdlib.h>

int main(){

    float *arr,ki;
    int row,col;

    printf("\nEnter the size of row :  ");
    scanf("%d",&row);
    col = row + 1;

    arr = (float*)malloc(row * col * sizeof(float));

    printf("\n\nEnter the equation :  \n\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col ; j++)
            scanf("%f",(arr + i * col + j));

    printf("\nMatrix :  \n\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%.2f  ",*(arr + i * col + j));
        printf("\n\n");    
    }

    printf("\nDiagonal Matrix :  \n\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++){

            ki = *(arr + j * col +i) / *(arr + i * col + i);

            for (int k = 0; k < col; k++)

                if(i != j)
                    *(arr + j * col + k) = *(arr + j * col + k) - *(arr + i * col + k) * ki;     
        }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%.2f  ",*(arr + i * col + j));
        printf("\n\n");
    }
    printf("\nBackward substitution :  \n");
    for (int i = 0; i < row; i++)
        printf("\n%d  =  %.2f\n",i+1,*(arr + i * col + row) / *(arr + i * col + i));

    free(arr);
    return 0;
}