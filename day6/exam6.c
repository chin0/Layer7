#include <stdio.h>

int mystrcmp(char* str1, char* str2)
{
    int cnt = 0;
    while(str1[cnt] != str2[cnt])
        cnt++;
    return cnt;
}
int main(void)
{
    char key[] = "apple";
    char buffer[80];

    do {
        printf("Guess my favorite fruit? ");
        fflush(stdout);
        scanf("%79s",buffer);
    } while(mystrcmp(key,buffer));

    printf("Right!\n");

    return 0;
}
