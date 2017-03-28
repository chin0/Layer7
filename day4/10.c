#include <stdio.h>

int main(void)
{
    int a[10];

    int size = sizeof(a) / sizeof(a[0]);

    for(int i = 0; i < size; i++)
        scanf("%d",&a[i]);

    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
