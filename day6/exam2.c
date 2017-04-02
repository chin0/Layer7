#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%d %d %d\n", 'A', 'S', NULL);

    if(NULL == 0)
        printf("NULL == 0\n");
    if('A' == 0x41)
        printf("A == 0x41\n");

    return 0;
}

