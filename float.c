#include<stdio.h>

int main()
{
    float num;
    int nm;
    
    printf("enter the no.\n");

    scanf("%f",&num);

    printf("enter the no. rounf off\n");

    scanf("%d",&nm);

    printf("the no = ");

    switch (nm)
    {
    case 1:
            printf("%.1f",num);
        break;

    case 2:
            printf("%.2f",num);
        break;

    case 3:
            printf("%.3f",num);
        break;

    case 4:
            printf("%.4f",num);
        break;

    }
    
    return 0;
}