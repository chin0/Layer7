#include <stdio.h>

/*처음 아이디어 안됐다고 그 아이디어를 버리지 말자. 
 * 그리고 침착하게 규칙을 찾자.
 * 하.. 한강각 */

int main(void)
{
    int n = 10;
    int k = 3;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == 0 || j == n-1 || i == 0 || i == n-1)
                printf("*");
            else if((j-i) % k == 0) //나머지만큼의 간격으로 한서클당 앞으로 가야되니까 j-i
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

