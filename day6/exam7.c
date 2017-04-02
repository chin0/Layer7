#include <stdio.h>

int main(void)
{
    char buf1[] = "Hello";
    char buf2[6] = "Hello";
    char buf3[6] = "Hello";
    char buf4[] = "Secret_Password!";
    char buf5[8] = {'H','E','l','l','o','1','2','3'};

    printf("buf1 - %s\n", buf1);
    printf("buf2 - %s\n", buf2);
    printf("buf3 - %s\n", buf3);
    printf("buf5 - %s\n", buf5);

    return 0;
}
