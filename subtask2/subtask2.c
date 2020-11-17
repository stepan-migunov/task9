//
// Created by stepan on 27.10.2020.
//

#include "subtask2.h"
#include "stdio.h"

int abs_i(int alpha)
{
    return alpha > 0 ? alpha : -alpha;
}
int max_i(int a, int b)
{
    return a>b ? a : b;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void subtask2()
{
    int M, N;
    scanf("%d%d", &M, &N);
    int matrix1[M][N], matrix2[M][N];
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            matrix1[i][j] = 1 + abs_i(i - j),matrix2[i][j] = 0;

    {
        int counter = 1, x = 0, y = 0;
        while (counter <= M * N)
        {
            while(y < N - 1 && matrix2[x][y + 1] == 0)
                matrix2[x][y]=counter++,++y;
            while(x < M - 1 && matrix2[x + 1][y] == 0)
                matrix2[x][y]=counter++, ++x;
            while(0 < y && matrix2[x][y - 1] == 0)
                matrix2[x][y]=counter++,--y;
            while(0 < x && matrix2[x - 1][y] == 0)
                matrix2[x][y]=counter++,--x;
            if( matrix2[x+1][y] != 0
                &&
                matrix2[x][y+1] != 0
                &&
                matrix2[x-1][y] != 0
                &&
                matrix2[x][y-1] != 0
                &&
                matrix2[x][y] == 0)
            {
                matrix2[x][y]=counter++;
            }
        }
    }
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%4d ", matrix1[i][j]);
        printf("\n\n");
    }

}
#pragma clang diagnostic pop