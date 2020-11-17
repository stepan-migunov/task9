//
// Created by stepan on 30.10.2020.
//

#include "subtask3.h"
#include "stdio.h"

extern int abs_i(int alpha);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void subtask3()
{
    int array[9][9];
    int sum = 0;
    for(int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            array[i][j]=1;//scanf("%d",&array[i][j]);
    for(int y = 0; y < 9; ++y)
        for (int x = 0; x < 9; ++x)
            if(abs_i(y-4) <= abs_i(x-4))
                sum += array[x][y];
    printf("%d",sum);
}
#pragma clang diagnostic pop