#include <stdio.h>

int main(void)
{
    int array[50][30];

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 30; j++)
            array[i][j] = (30 * i) + j;
    }

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 30; j++)
            printf("%4d ",array[i][j]);
        printf("\n");
    }
}

