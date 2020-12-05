
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //A[3][4][5]

    int ***a = (int ***)malloc(3*sizeof(int **));
    for(int i=0;i<3;i++)
    {
        a[i]= (int **)malloc(4*sizeof(int *));
        for(int j=0;j<4;j++)
            a[i][j]= (int *)malloc(5*sizeof(int));
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<5;k++)
                a[i][j][k]=i*100+j*10+k;

    printf("Just Simple Printing :--\n\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<5;k++)
                printf("%d\t",a[i][j][k]);
            printf("\n");
        }
        printf("\n\n");
    }

    printf("Printing using Pointer :--\n\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<5;k++)
                printf("%d\t",*(*(*(a+i)+j)+k));
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}