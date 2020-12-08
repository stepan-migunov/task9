//
// Created by stepan on 30.10.2020.
//

#include "subtask4.h"
#include "stdio.h"

extern void swap_i(int* ,int*);

void subtask4()
{
    int M,N; scanf("%d%d",&M,&N); // NOLINT(cert-err34-c)
    int matrix[M][N];
    for(int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &matrix[i][j]); // NOLINT(cert-err34-c)

    int sums[N],
        sums_index[N];

    for(int i = 0; i < N; ++i)
        sums[i]=0;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            sums[i]+=matrix[j][i],
            sums_index[i]=i;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N-i-1; ++j)
            if(sums[j]>sums[j+1])
                swap_i(sums+j,sums+j+1),
                swap_i(sums_index+j,sums_index+j+1);
        
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N-1-i;++j)
            if(sums_index[j]>sums_index[j+1])
            {
                swap_i(sums_index+j,sums_index+j+1);
                for(int k = 0; k < M; ++k)
                    swap_i(&matrix[k][j],&matrix[k][j+1]);
            }

    printf("\n\n");

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%4d ", matrix[i][j]);
        printf("\n\n");
    }
}
