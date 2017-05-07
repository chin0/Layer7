#include <stdio.h>

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
