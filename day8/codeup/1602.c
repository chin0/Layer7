#include <stdio.h>

/**************************
* 절댓값 구하기             *
* 절댓값은 무조건 양수여야한다 *
* 정수가 0 이하이면 -로      *
*부호를 바꿔 양수로 만든다.   *
***************************/

double abs(double a)
{
    if(a < 0)
        return -a;
    return a;
}

int main(void)
{
    double a;
    scanf("%lf",&a);
    /*g는 기본적으로 6자리 이상이면 지수로
      표현하기때문에 표현할수있는 자리수를 늘려준다. (.10g)*/
    printf("%.10g\n",abs(a));
    return 0;
}
