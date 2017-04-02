#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    int arg1,arg2,i=0;
    char oper;

    fgets(string,80,stdin);

    sscanf(string,"%d %c %d",&arg1, &oper, &arg2);

    switch(oper)
    {
        case '-':
            printf("%d %c %d = %d\n",arg1, oper, arg2, arg1 - arg2);
            break;
        case '*':
            printf("%d %c %d = %d\n",arg1, oper, arg2, arg1 * arg2);
            break;
        case '/':
            printf("%d %c %d = %d\n",arg1, oper, arg2, arg1 / arg2);
            break;
        case '+':
            printf("%d %c %d = %d\n",arg1, oper, arg2, arg1 + arg2);
            break;
        default:
            printf("error!\n");
    }
}
