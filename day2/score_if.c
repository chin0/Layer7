#include <stdio.h>

int main(int argc, char *argv[])
{
    int score = 0;

    scanf("%d",&score);

    if(score >= 90){
        printf("똒똒1\n");
        return 0;
    }
    if(score >= 80 && score < 90){
        printf("똒똒2\n");
        return 0;
    }
    if(score >= 70 && score < 80){
        printf("바보1\n");
        return 0;
    }
    if(score >= 60 && score < 70){
        printf("바보2\n");
        return 0;
    }
    if(score < 60)
        printf("댕청\n");

    return 0;
}

