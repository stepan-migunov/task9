//
// Created by stepan on 30.10.2020.
//

#include "subtask7.h"
#include "stdio.h"

extern void swap_i(int*,int*);
extern int lcf(int,int);

int determinant(int height, int width, int matrix[height][width])
{
    int determinant_ = 1;
    if(height==1)
        return matrix[0][0];

    int rowWithStartingNonZero = 0;
    for(int i = 0; i < height; ++i)
        if (matrix[i][0] != 0)
        {
            rowWithStartingNonZero = i;
            break;
        }

    if (rowWithStartingNonZero != 0 && (determinant_*=-1))
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
    determinant_*= determinant(height - 1, width - 1, matrix_prime)*matrix[0][0];
    for(int i = 1; i < height; ++i)
        for (int j = 1; j < width; ++j)
            matrix[i][j]=matrix_prime[i-1][j-1];
    return determinant_;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void subtask7()
{
    int N; scanf("%d",&N);
    int matrix[N][N];

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            scanf("%d", &matrix[i][j]);
    }

    printf("%d",determinant(N,N,matrix));
}
#pragma clang diagnostic pop