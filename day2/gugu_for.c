#include <stdio.h>

int main(void)
{
    int cnt = 0;
    for(int i = 1; i<=5; i++)
        for(int j = 1; j<=9; j++){
            if(cnt % 3 == 0)
                printf("\n");
            printf("|%1d * %1d = %2d  | ",i,j,i*j);
            cnt++;
        }
    printf("\n");

}      
