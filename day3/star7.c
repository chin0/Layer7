#include <stdio.h>

int main(void)
{
    int n = 5;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i; j++)
            printf("_");
        for(int j = 0; j < (n-i);j++)
            printf("*");
        printf("\n");
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 0; j < (n-i); j++)
            printf("_");
        for(int j = 0; j < i;j++)
            printf("*");
        printf("\n");
    }
}
