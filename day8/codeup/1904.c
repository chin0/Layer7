#include <stdio.h>

/*
start가 2로 나눠서 나머지가 있으면 홀수이기때문에
출력하고 start+1을 start에 넣고 재귀해서
start와 end가같으면 탈출한다.
*/

void solve(int start, int end)
{

    if(start % 2)
        printf("%d ",start);
    if(start == end){
        printf("\n");
        return;
    }
    solve(start+1,end);
}

int main(void)
{
    int a,b;

    scanf("%d %d",&a,&b);

    solve(a,b);

    return 0;
}
