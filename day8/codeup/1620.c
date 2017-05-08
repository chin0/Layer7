#include <stdio.h>

/*
각 자릿수의 합을 구해서, 그 값을 solve의 인자에 넣고
재귀해서 인자가 만약 10 이하이면 그 값을 리턴한다.
*/
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
