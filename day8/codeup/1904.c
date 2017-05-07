#include <stdio.h>

void solve(int start, int end)
{
    if(start == end+1){
        printf("\n");
        return;
    }
    if(start % 2)
        printf("%d ",start);
    solve(start+1,end);
}

int main(void)
{
    int a,b;

    scanf("%d %d",&a,&b);

    solve(a,b);

    return 0;
}
