//
// Created by stepan on 30.10.2020.
//

#include "subtask6.h"
#include "stdio.h"

extern void diagonalise_up(int height, int width, int matrix[height][width]);
extern void diagonalise_down(int height, int width, int matrix[height][width]);
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void subtask6()
{
    int N; scanf("%d",&N); // NOLINT(cert-err34-c)
    int doubledMatrix[N][2 * N], matrix[N][N], result[N][N];
    double xirtam[N][N];

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &matrix[i][j]);
            doubledMatrix[i][N + j]=(i == j);
            doubledMatrix[i][j] = matrix[i][j];
        }
    }
    diagonalise_up(N, 2*N, doubledMatrix);
    diagonalise_down(N,2*N, doubledMatrix);

    printf("\n****** xirtam ******\n\n");

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0, divisor = doubledMatrix[i][i]; j < N; ++j)
            printf("%3lf ", xirtam[i][j] = doubledMatrix[i][j + N]/(1.0*divisor));
        printf("\n");
    }

    printf("\n****** Multiplication of matrix and xirtam ******\n\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; ++j)
                for(int k = result[i][j] = 0; k < N; ++k)
                    result[i][j]+=matrix[i][k]*xirtam[k][j];

    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%3d ", result[i][j]);
        printf("\n");
    }
}
#pragma clang diagnostic pop