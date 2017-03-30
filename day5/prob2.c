#include <stdio.h>

int main(void)
{
    int n,cnt=1;
    scanf("%d",&n);

    int map[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i % 2)
                map[n-j-1][i] = cnt++;
            else
                map[j][i] = cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
}
    
