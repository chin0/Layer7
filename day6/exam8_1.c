#include <stdio.h>
#include <string.h>

int myatoi(char *data)
{
    int b = 0;
    for(int i = 0; i < strlen(data); i++) {
        b = 10 * b + (data[i] - '0');
        printf("%d\n", b);
    }
    return b;
}
    
int main(void)
{
    char string[100];
    int arg1,arg2,result,i=0;
    char oper;

    fgets(string,80,stdin);
    string[strlen(string)-1] = '\0';
    while(string[i++] != ' ');
    string[i-1] = '\0';
    arg1 = myatoi(string);
    oper = string[i];
    arg2 = myatoi(&string[i+2]);

    printf("%d\n",arg2);

    switch(oper)
    {
        case '-':
            result = arg1 - arg2;
            break;
        case '*':
            result = arg1 * arg2;
            break;
        case '/':
            result = arg1 / arg2;
            break;
        case '+':
            result = arg1 + arg2;
            break;
        default:
            printf("error!\n");
    }
    printf("%d %c %d = %d\n",arg1, oper, arg2, result);
}
