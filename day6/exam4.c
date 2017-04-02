#include <stdio.h>

void mygets(char *data)
{
    int cnt;
    while((data[cnt] = getchar()) != '\n');
}
unsigned int mystrlen(char *data)
{
    unsigned int cnt=0;
    while(data[cnt++] != '\n');

    return cnt;
}

int main(void)
{
    char data[100];
    printf("Enter a sentence: ");
    mygets(data);
    printf("The sentence entered is %u characters long.\n", (unsigned)mystrlen(data));
    return 0;
}
