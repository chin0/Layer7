#include <stdio.h>

int main(int argc, char *argv[])
{
    int score = 0;

    scanf("%d",&score);
    
    switch(score / 10)
    {
        case 8:
            printf("똒똒2\n");
            break;
        case 7:
            printf("바보1\n");
            break;
        case 6:
            printf("바보2\n");
            break;
        default:
            if(score >= 9){
                printf("똒똒1\n");
                break;
            }
            printf("댕청\n");
    }
    return 0;
}
