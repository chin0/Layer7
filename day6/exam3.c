#include <stdio.h>

int mystrlen(char * data)
{
    int cnt = 0;
    while(data[cnt] != 0)
        cnt++;
    return cnt;
}

void myread(char *buf, int len)
{
    int cnt = 0;
    while(buf[cnt] = getchar()){
        if(cnt == len-1 || buf[cnt] == '\n'){
            buf[cnt] = '\0';
            return;
        }
        cnt++;
    }
}

int main(void)
{
    char c;
    char data[100];

    myread(data,100);

    for(int i = 0; i < mystrlen(data); i++)
        printf("%c:%#x ", data[i], data[i]);
    printf("\n");

    return 0;
}
