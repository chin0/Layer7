#include <stdio.h>

int fuck(int *a)
{
    return sizeof(a);
}

int main(int argc, char* argv[])
{
    int arr[100] = {};
    printf("%d %d\n",sizeof(arr),fuck(arr));
}
