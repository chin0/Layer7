#include <stdio.h>

int table[10000];
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
        table[d(i,1)] = 1;

    for(i=a; i <= b; i++)
        if(table[i] == 0)
            result += i;

    printf("%d\n",result);
    return 0;
}
