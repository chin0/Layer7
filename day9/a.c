#include <stdio.h>
#include <string.h>

int idol_master(char* mem1, char* mem2, char* producer)
{
    int ret = 0;
    int mem1_len = strlen(mem1);
    int mem2_len = strlen(mem2);
    int producer_len = strlen(producer);

    if(mem1_len == mem2_len && mem2_len == producer_len){
        printf("we are the one!\n");
        ret = 1;
    }

    for(int i = 0; i < mem1_len; i++)
        printf("%c",mem1[i]);
    printf("\n");
    for(int i = 0; i < mem2_len; i++)
        printf("%c",mem2[i]);
    printf("\n");
    for(int i = 0; i < producer_len; i++)
        printf("%c",producer[i]);
    printf("\n");

    return ret;
}


    
    
    
int main(void)
{
    char a[100], b[100], c[100];

    scanf("%100s %100s %100s",a,b,c);

    int r = idol_master(a,b,c);

    if(r)
        printf("yeah!\n");
    return 0;
}
