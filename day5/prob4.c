#include <stdio.h>

int main(void)
{
    int n = 0, cnt = 1;

    scanf("%d",&n);
    
    int map[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(n % 2)
                map[i][n-j-1] = cnt++;
            else
                map[i][j] = cnt++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%3d",map[i][j]);
        printf("\n");
    }
}

