#include <stdio.h>

int main(void)
{
    int i,j,c=0;

    int n;

    scanf("%d",&n);

    int map[n][n];
    for(i=0; i < n/2; i++)
    {
        for(int j = 0; j < n - (2 * i + 1);j++)
            map[i][j+i] = c++;
        for(int j = 0; j < n - (2 * i+1);j++)
            map[j+i][n-(i+1)] =c++ ;
        for(int j = 0; j < n - (2 * i+1);j++)
            map[n-(i+1)][n - (j+1)-i] = c++;
        for(int j = 0; j < n - (2 * i+1); j++)
            map[n-(j+1)-i][i] = c++;
    }
    if(n % 2)
        map[n/2][n/2] = n * n - 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%3d ", map[i][j]);
        printf("\n");
    }
}
            
