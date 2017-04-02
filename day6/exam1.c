#include <stdio.h>

int main(int argc, char* argv[])
{
    char buf1[] = "Hello";
    char buf2[6] = "Hello";
    char buf3[6] = {'H','e','l','l','o',NULL};

    printf("buf1 - %s\n",buf1);
    printf("buf2 - %s\n",buf2);
    printf("buf3 - %s\n",buf3);
    return 0;
}
