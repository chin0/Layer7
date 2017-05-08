#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  서브스트링은 일정 구간의 문자열을 뽑아내는 함수이다.
  그러므로 count + 1만큼의 공간(널바이트 포함)을 확보해주고
  그 공간에 주어진 범위의 문자열을 넣고, 마지막에 NULL을 붙여준다.
*/

char *mysubstr(char *str,int start,int count)
{
    if(strlen(str + start) < count){
        printf("nope!\n");
        return NULL;
    }
    char *ret = (char*)malloc(count + 1);
    memcpy(ret,str+start,count);
    ret[count+1] = NULL;
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
