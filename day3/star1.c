#include <stdio.h>

int main(void)
{
    int n = 10;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
}
