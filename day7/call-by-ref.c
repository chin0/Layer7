#include <stdio.h>

void swap(int n1, int n2) //n1, n2의 값만 복사되서 넣어진다.
{
    int temp = n1; 
    n1 = n2; //n1이라는 '값'만 복사된 변수에 n2의 값을 넣는다.
    n2 = temp; //동일
    //결과적으로 넘겨진 변수의 실질적인 값은 변하지않는다.
}

void swap2(int *n1, int *n2) //n1, n2의 주소가 넘어간다.
{
    int temp = *n1; //n1이 가지고있는 주소에 접근해서 값을 읽어 temp에 넣는다.
    *n1 = *n2; //n2가 가지고있는 주소에 접근해서 값을 읽어와 n1이 가리키고있는 주소에 접근해서 읽어온 데이터를 쓴다.
    *n2 = temp; //n2가 가지고있는 주소에 접근해서 그곳에 temp의 값을 쓴다.

    //인자로 넘겨진 변수의 주소를 가지고 값을 쓰기때문에 정상적으로 작동한다.
}

//just-for-fun (64bit gcc inline assembly)
void swap_asm(int *n1, int *n2)
{
    __asm__("mov (%rdi), %eax\n\t"
            "mov (%rsi), %ecx\n\t"
            "mov %ecx, (%rdi)\n\t"
            "mov %eax, (%rsi)");
}


int main(void)
{
    int a=3,b=5;

    swap(a,b);

    printf("%d %d\n",a,b);

    swap2(&a,&b);

    printf("%d %d\n",a,b);

    swap_asm(&a,&b);

    printf("%d %d\n",a,b);
}
