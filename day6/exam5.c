#include <stdio.h>

void mystrcpy(char *dest,char *src)
{
    int cnt = 0;
    while(dest[cnt++] = src[cnt]);
    src[cnt+1] = '\0';
}


int main()
{
    char str[]="Sample string";
    char str2[40];
    char str3[40];
    mystrcpy(str2,str);
    printf("str2:%s\n",str2);
}

