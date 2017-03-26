#include <stdio.h>

int main(void)
{
    int n = 10;
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
}
