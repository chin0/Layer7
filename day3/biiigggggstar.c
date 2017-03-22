#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n-i) - 1; j++)
            printf(" ");
        for(int j = 0; j < (1 + i * 2); j++)
            printf(" ");
        for(int j = 0; j < (n-i); j++)
            printf(" ");
        for(int j = 0; j < (n-i) - 1; j++)
            printf(" ");
        for(int j = 0; j < (1 + i * 2); j++)
            printf("*");
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            printf(" ");
        for(int k = 0; k < 2; k++){
            for(int j = 0; j < ((n*2-1) - i * 2); j++)
                printf("*");
            for(int j = 0; j < (1 + i * 2); j++)
                printf("*");
        }
        for(int j = 0; j < ((n*2-1) - i * 2); j++)
            printf("*");
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n-i) - 1; j++)
            printf(" ");
        for(int j = 0; j < (1 + i * 2); j++)
            printf("*");
        for(int k = 0; k < 2; k++){
            for(int j = 0; j < ((n*2-1) - i * 2); j++)
                printf("*");
            for(int j = 0; j < (1 + i * 2); j++)
                printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n-i) - 1; j++)
            printf(" ");
        for(int j = 0; j < (1 + i * 2); j++)
            printf(" ");
        for(int j = 0; j < (n-i) - 1; j++)
            printf(" ");
        for(int j = 0; j < i; j++)
            printf(" ");
        for(int j = 0; j < ((n * 2 - 1) - i * 2); j++)
            printf("*");
        printf("\n");
    }
}
