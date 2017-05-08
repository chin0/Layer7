#include <stdio.h>

/*
n/2가 0이될때까지 재귀호출 깊이를 늘린다.
n/2가 0이되면 그때의 n%2결과를 출력하고 리턴한다.
그러면 재귀호출 깊이가 1씩 줄어들면서
재귀호출 전의 n % 2를 출력하게 된다.
*/
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
