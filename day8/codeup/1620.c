#include <stdio.h>

int solve(int a)
{
    if(a < 10)
        return a;
    int result = 0;
    for(int i = a; i ; result += i % 10, i /= 10);
    return solve(result);
}

int main(void)
{
    int a;

    scanf("%d",&a);

    printf("%d\n",solve(a));
}
