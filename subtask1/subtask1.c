//
// Created by stepan on 27.10.2020.
//

#include <stdio.h>
#include "subtask1.h"

void subtask1()
{
    int M,N;
    scanf("%d%d",&M,&N); // NOLINT(cert-err34-c)
    int matrix1[M][N];
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d",&matrix1[i][j]); // NOLINT(cert-err34-c)
    int array[M*N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            array[N*j + i] = matrix1[j][i];

    int matrix2[M][N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            matrix2[j][i] = array[N*j + i];

    for(int k = 0; k < M*N-1; ++k)
        matrix2[k%M][k%N] = array[k];
}