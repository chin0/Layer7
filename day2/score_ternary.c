#include <stdio.h>

int main(int argc, char *argv[])
{
    int score = 0;

    scanf("%d",&score);
    
    printf((score >= 90) ? "똑똑1\n":(score < 90 && score >= 80) ? "똑똑2\n" : 
            (score < 80 && score >= 70) ? "바보1\n" : 
            (score < 70 && score >= 60) ? "바보2\n" : "댕청\n");
    return 0;
}
