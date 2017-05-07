#include <stdio.h>

void bin(int n)
{
    if(n / 2 == 0){
        printf("%d",n%2);
        return;
    }
    bin(n/2);
    printf("%d",n%2);
}


int main(void)
{
    int chino;

    scanf("%d",&chino);

    bin(chino);
    printf("\n");
}
