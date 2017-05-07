#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mysubstr(char *str,int start,int count)
{
    if(strlen(str + start) < count){
        printf("nope!\n");
        return NULL;
    }
    char *ret = (char*)malloc(count);
    memcpy(ret,str+start,count);
    return ret;
}

int main(void)
{
    int i,j;
    char asdf[100];
    char *substr;

    scanf("%s",asdf);
    scanf("%d %d",&i,&j);

    substr = mysubstr(asdf,i,j);
    printf("%s\n",substr);
    return 0;
}
