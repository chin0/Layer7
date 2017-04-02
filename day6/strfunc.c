#include <stdio.h>
#define uint unsigned int

/* 
 * my_strlen(char* data)
 *
 * 인자로 넘겨진 문자열의 문자 개수를 리턴한다.
 */

uint my_strlen(char* data)
{
    int cnt;
    for(cnt=0; data[cnt] != '\0'; cnt++);

    return cnt;
}

/*
 * my_strcmp(char* data1, char* data2)
 *
 * data1과 data2를 비교하여 리턴된값이
 * == 0 : 두 문자열이 같다.
 * > 0 : 두 문자열이 다르다 -> 다른부분의 문자가 data1이 더 크다.
 * < 0 : 두 문자열이 다르다 -> 다른부분의 문자가 data2이 더 크다.
 */

int my_strcmp(char* data1, char* data2)
{
    int i,result,len = (my_strlen(data1) > my_strlen(data2)) ? my_strlen(data1) : my_strlen(data2);
    for(i=0; (result = data1[i] - data2[i]) == 0 && i < len; i++);
    return result;
}


/*
 * my_strcpy(char* dest, char* src)
 *
 * 문자열 src의 내용을 문자열 dest에 복사한다.(src문자열의 널바이트를 만날때까지.)
 * 이때, src의 길이를 검사하지 않기때문에 이 함수는 취약하다.
 *
 */
//unsafe strcpy
void my_strcpy(char* dest, char* src)
{
    int i;
    for(i=0; i < my_strlen(src); i++)
        dest[i] = src[i];
}



int main(void)
{
    char data[8] = "ABCDEFG";
    char buf[8];

    printf("strlen(%s) = %u\n",data,my_strlen(data));

    printf("input string: ");
    scanf("%7s",buf);
    printf("strcmp(%s,%s) = %d\n",data,buf,my_strcmp(data, buf));
    my_strcpy(data,buf);
    printf("after strcpy(data,buf): %s\n",data);
}
