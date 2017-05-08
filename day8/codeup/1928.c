#include <stdio.h>



/*
n이 홀수이면 3n + 1을 인자에 넣고 재귀하고,
짝수이면 n/2를 인자에 넣고 재귀한다.
이때 출력을 먼저해주면, 과정을 볼수있다.
*/
void solve(int n)
{
    printf("%d\n",n);
    if(n == 1)
        return;
    solve(n % 2 ? 3 * n + 1 : n / 2);
}
int main(void)
{
    int n;

    scanf("%d",&n);
    solve(n);

    return 0;
}
