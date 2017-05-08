#include <stdio.h>

int table[10000];
/*
셀프넘버

셀프넘버는 제네레이터가 없는 숫자들을 말한다.
제네레이터는 d(n)을 각 자릿수 숫자들(여기서 n은 자연수)과 n자신을 더한
숫자라고 정의할때, d(n) = g일때, n을 g의 제네레이터라고
한다. 이 제네레이터가 없는 숫자들도 있는데, 이를 셀프 넘버라고 한다.

1은 제네레이터가 없기때문에 셀프넘버고, 2는
d(1) = 2이기때문에 제네레이터가 존재하기때문에
셀프넘버가 아니다.

그렇다면, 셀프넘버를 골라내는 방법은, 값의 범위
a,b가 주어졌을때, 1부터 b까지 d에 넣어서 나오는값을
위 table에 체크한다. 그래서 1부터 b까지 d에 넣어서
체크를 끝내면, 그 배열을 a부터 b까지 순회해서 체크되지
않은 인덱스를 찾는다(체크되지 않은 배열은 셀프넘버이기 때문이다). 그래서 찾으면 그 수를 더한다. */

int d(int a,int b)
{
    if(a / b == 0)
        return a;
    int cur = a % (b * 10) / b;
    return cur + d(a,b * 10);
}
int main(){
    int a,b,i = 0,result = 0;

    scanf("%d %d",&a,&b);

    for(i=1; i <= b;i++)
        table[d(i,1)] = 1; //check non self number

    for(i=a; i <= b; i++)
        if(table[i] == 0) //find self number
            result += i; 

    printf("%d\n",result);
    return 0;
}
