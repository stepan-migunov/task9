//
// Created by stepan on 30.10.2020.
//

#include "subtask5.h"
#include "stdio.h"

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else
        return gcd(b%a,a);
}
int lcf(int a, int b)
{
    return (a*b)/gcd(a,b);
}
void swap_i(int* alpha, int* beta)
{
    int temp = *alpha;
    *alpha = *beta,
    *beta = temp;
}
void diagonalise_up(int height, int width, int matrix[height][width])
{
    if(height==1)
        return;
    int rowWithStartingNonZero = 0;
    for(int i = 0; i < height; ++i)
        if (matrix[i][0] != 0)
        {
            rowWithStartingNonZero = i;
            break;
        }
    if (rowWithStartingNonZero != 0)
        for(int i = 0; i < width; ++i)
            swap_i(&matrix[0][i],&matrix[rowWithStartingNonZero][i]);

    for(int i = 1; i < height; ++i)
    {
        if(matrix[i][0] == 0)
            continue;
        int mult_I = lcf(matrix[i][0],matrix[0][0])/matrix[i][0];
        for(int j = 0; j < width; ++j)
            matrix[i][j]*=mult_I;
        int mult_0 = lcf(matrix[0][0],matrix[i][0])/matrix[0][0];
        for (int j = 0; j < width; ++j)
            matrix[i][j]-=matrix[0][j]*mult_0;
    }

    int matrix_prime[height-1][width-1];
    for(int i = 1; i < height; ++i)
        for (int j = 1; j < width; ++j)
            matrix_prime[i-1][j-1]=matrix[i][j];
    diagonalise_up(height - 1, width - 1, matrix_prime);
    for(int i = 1; i < height; ++i)
        for (int j = 1; j < width; ++j)
            matrix[i][j]=matrix_prime[i-1][j-1];
}
void diagonalise_down(int height, int width, int matrix[height][width])
{
    if(height==1)
        return;

    int rowWithStartingNonZero = height-1;
    for(int i = height-1; i >= 0; --i)
        if (matrix[i][height-1] != 0)
        {
            rowWithStartingNonZero = i;
            break;
        }

    if (rowWithStartingNonZero != height-1)
        for(int i = 0; i < width; ++i)
            swap_i(&matrix[height-1][i],&matrix[rowWithStartingNonZero][i]);

    for(int i = 0; i < height-1; ++i)
    {
        if(matrix[i][height-1] == 0)
            continue;
        int mult_I = lcf(matrix[i][height-1],matrix[height-1][height-1])/matrix[i][height-1];
        for(int j = 0; j < width; ++j)
            matrix[i][j]*=mult_I;
        int mult_0 = lcf(matrix[height-1][height-1],matrix[i][height-1])/matrix[height-1][height-1];
        for (int j = 0; j < width; ++j)
            matrix[i][j]-=matrix[height-1][j]*mult_0;
    }

    int matrix_prime[height-1][width];
    for(int i = 0; i < height-1; ++i)
        for (int j = 0; j < width; ++j)
            matrix_prime[i][j]=matrix[i][j];

    diagonalise_down(height - 1, width, matrix_prime);

    for(int i = 0; i < height-1; ++i)
        for (int j = 0; j < width; ++j)
            matrix[i][j]=matrix_prime[i][j];
}
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void subtask5()
{
    int N; scanf("%d",&N);
    int matrix[N][N+1];
    for(int i = 0; i < N; ++i)
        for (int j = 0; j < N+1; ++j)
            scanf("%d", &matrix[i][j]);
    
    diagonalise_up(N, N + 1, matrix);

    printf("\n************\n\n");
    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N+1; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n************\n\n");
    diagonalise_down(N,N+1,matrix);

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N+1; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\n************\n\n");
    for(int i = 0; i < N; ++i)
        printf("x%d = %lf\n",i,matrix[i][N]*1.0/matrix[i][i]);
}
#pragma clang diagnostic pop
