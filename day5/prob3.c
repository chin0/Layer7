#include <stdio.h>

int main(void)
{
    int n,i=0,cnt=0;

    scanf("%d",&n);

    int map[n][n];

     for(int i = 0; i < n; i++){
         for(int j = 0; j <= i; j++){
             if(i % 2)
                 map[j][i-j] = cnt++;
             else
                map[i-j][j] = cnt++;
         }
     }
     for(int i = n; i > 0; i--){
         for(int j = 1; j < i; j++){
             if(i % 2 == 0)
                 map[n-j][n-i+j] = cnt++;
             else
                map[n-i+j][n-j] = cnt++;
         }
     }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%3d ",map[i][j]);
        printf("\n");
    }

}

