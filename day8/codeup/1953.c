#include <stdio.h>

void triangle(int cur,int start,int n)
{
    if(start == n+1)
        return;
    if(cur == start+1){
        printf("\n");
        triangle(1,start+1,n);
    } else {
        printf("*");
        triangle(cur+1,start,n);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);

    triangle(1,1,n);
}
