#include <stdio.h>

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

    printf("%.10g\n",abs(a));
    return 0;
}
