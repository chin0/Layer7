# Layer7 8일차 보고서

## 포인터

### 기본

- 기본 개념

  포인터의 기본은 포인터는 어떤 변수의 '주소'를 담는다는 것이다. 그리고 포인터는 그 주소를 참조하여 특정 메모리의 있는 값을 조작할수있다.

  ![pointer](https://raw.githubusercontent.com/chin0/Layer7/master/day8/img/pointer.png)

  위와같이 Yptr은 100이라는 주소를 갖고있고, 이 주소를 역참조연산자(\*)를 이용해 해당 주소에 있는 값에 접근해서 읽거나 수정할수있다.

  포인터변수의 선언은 아래와 같다.

  `type *variable_name`

  type에는 자료형, variable_name에는 변수이름을 넣는다. 그러면 type형을 가리키는 포인터변수를 선언할수있다. 예를들어:

  `int *ptr`

  이 구문은, int형 변수를 가리키는 ptr이라는 포인터 변수를 생성하라! 라는 의미가 된다.

  이 변수를 쓰려면, 어떠한 주소가 필요하다. 이는 변수의 주소가 될수도있고, 아니면 임의의 주소를 넣어줄수도 있지만, 보통 임의의 변수를 가리키게 한다. 하지만 아래와 같이 선언하면 문제가 생긴다.

  ```
  int a = 50;
  int *ptr = a;
  ```
  위 코드에서, 포인터 변수는 a의 값을 갖는것이지, a의 주소를 갖고있는것이 아니다. 우리는 어떤 변수의 주소를 구하기 위해서 주소연산자(&)를 사용한다.

  ```
  int a = 50;
  int *ptr = &a;
  또는
  int *ptr;
  ptr = &a;
  ```
  위 코드를 보면, &를 이용해서 a의 주소를 포인터 변수에 넣어주는것을 확인할수있다.

  위와같이 선언된 포인터 변수는 기본적으로 어떤 변수의 주소를 담기때문에 그대로 사용할수는 없다. 다음 코드를 보자.

  ```
  int a = 50;
  int *ptr = &a;

  printf("%d\n",ptr);
  ```
  위 코드를 컴파일해보면, 어떤 이상한 값이 출력되는것을 알수있다. 이 출력되는 주소가 a의 실제 주소값이며, 이를 통해 우리는 포인터 변수를 그냥 사용할수는 없다는것을 알수있다. 그래서, 우리는 갖고있는 주소에 접근할수 있게해주는 역참조연산자(\*)를 이용해서 주소에 접근해 값을 쓰거나 읽을수있다.

  ```
  int a = 50;
  int *ptr = &a;
  printf("%d\n",*ptr);
  ```
  위 코드를 보면 정상적으로 50이 출력된다. 이는 ptr이 가지고있는 a의 주소에 역참조 연산자를 이용해서 그 주소의 값을 읽어왔기때문에 가능한일이다.

  ```
  int a = 50;
  int *ptr = &a;

  *ptr = 60;
  printf("%d\n",a);
  ```
  위 코드를 보면, 60이 출력될것이다. 이는 ptr이 가지고있는 주소에 '접근'해서 값을 덮어씌웠기때문이다.

  여기서 `ptr = &a`와 `*ptr = &a`의 차이를 알수있다.

  전자는 'ptr에' a의 주소를 넣겠다는것이고 후자는 ptr이 가리키는곳에 a의 주소를 넣는다는 의미다. 이 둘을 확실히 구분해야한다. 선언과 동시에 초기화를 할때는 `int *ptr = &a`와 같은 방식이 가능하지만, 선언후 대입은 저 둘을 확실히 구분해야한다.

- 포인터 상수

  포인터에도 const를 붙여 상수화할수있다. 포인터는 가리키는곳을 상수화하는것과 포인터 변수 자체를 상수화시키는것이 있다. 일단 전자는 아래와 같이 선언한다.

  `const int *a`

  일단 const가 자료형 앞에 붙었을때는 참조연산자를 통해서 가리키는 주소를 수정할수 없게된다. 즉, 아래 코드는 에러를 발생시킨다.

  ```
  int a = 50;
  const int *const_ptr = &a;
  *const_ptr = 60; //error!
  ```

  `int * const ptr = &a`
  위 코드는 포인터 자체를 상수화시킨다. 즉, 포인터가 가리키는 주소를 변경할수없다. 그리고 이 경우에는 무조건 선언과 동시에 초기화가 이루어져야한다. 그러므로, 아래 두 예제는 에러를 일으키게된다.

  ```
  int a = 50;
  int * const ptr;
  ptr = &a //error!
  ```
  ```
  int a = 50;
  int b = 60;
  int * const ptr = &a;
  ptr = &b; //error!
  ```
- call by value vs call by reference

  포인터의 가장 대표적인 예시중 하나다. 자, 아래와 같은 코드가 있다.

  ```
  void swap(int a, int b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
  ```
  위 함수를 이용해 아래와 같은 main함수를 구현한다.
  ```
  int main(void)
  {
    int a = 50, b = 60;
    swap(a,b);
    printf("%d %d\n",a,b);
  }
  ```
  위 코드에서 a와 b의 값이 서로 바뀌었을까?

  변하지 않았다. 왜냐하면, 함수가 인자를 받을때는 기본적으로 넘겨진 인자의 값을 '복사'하여 들어가기 때문이다. 즉 swap의 인자는 그냥 인자로 넘겨진 변수의 복사된 값으로 처리를 하기때문에 실제 a와 b의 값은 변하지 않는다.

  더 쉽게 설명하자면, a와 b라는 컵이 있는데, 이 a와 b컵을 가져가서 처리를 하는것이 아니라, 다른 c와 d컵을 만들고, 거기에 a컵과 b컵의 내용물을 넣어서 c와 d끼리만 처리하는것과 같다.

  그럼, 어떻게 a와 b의 값을 함수내에서 바꿀수있을까?
  이는 포인터가 해결해준다. 위 swap 코드를 살짝만 수정해보자.

  ```
  void swap(int *a,int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  ```
  그리고 main함수도 살짝만 수정해보자.
  ```
  int main(void)
  {
    int a = 50, int b = 60;
    swap(&a,&b);
    printf("%d %d\n",a,b);
  }
  ```
  이러면 swap함수는 a와 b의 값이 아닌 '주소'를 가져가서 그 주소에 접근해 처리를 하게된다. 이렇게 변수의 값이 아닌 변수의 주소를 받는것을 call by reference라고 한다. 이렇게 포인터는 함수내에서 인자로 넘겨진 변수의 값을 수정할때 쓰일수도 있다.

### 포인터와 배열의 관계

배열은 포인터와 밀접한 관계를 가지고있다.

자, 아래와 같은 코드를 작성해보자.

```
#include <stdio.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};

    printf("%p\n",a);
}
```
위 코드를 실행하면 a가 기본적으로 어떤값을 가지고있는지 알수있다. 출력된 값을
보면 어떤 주소값을 가지고있다. 이는 a[0]의 주소다. 즉, a도 어떤 연속된 데이터를
가리키는 포인터라는것을 알수있다. 그러면, 포인터처럼 가리키는곳을 바꿀수도 있지않을까?
```
#include <stdio.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {5,6,7,8,9};

    a = b;
    printf("%p\n",a);
}
```
하지만 이를 컴파일하면 컴파일 에러를 일으킨다. 즉, 컴파일러에서 배열이 가리키고있는곳은
변경할수없도록 막아둔것이다. 즉, 배열은 일종의 상수형 포인터다.

그러면, 포인터를 이용해서 배열에 접근할수있을까?
```
#include <stdio.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};

    int *b = a;

    printf("%d\n",*b);
}
```
위 코드를 실행시키면 배열의 첫번째 요소를 출력한다. 이제, 두번째 요소도 출력해보자.
```
#include <stdio.h>

int main(void)
{
    int a[5] = {1,2,3,4,5};

    int *b = a;

    printf("%d\n",*(b+1));
}
```
이러면 배열의 두번째 요소를 얻어올수있다. 이를통해 []연산자는 \*(ptr + i)를 줄인것이라는것을
알수있다.

### 더블포인터

이제 더블포인터에 대해서 알아보자. 더블포인터는 포인터를 가리키는 포인터다. 아래 그림을 보자.

![doublepointer](https://raw.githubusercontent.com/chin0/Layer7/master/day8/img/img5.png)

더블포인터는 위와같이 포인터를 가리킨다. 아래 코드를 보자.

```
#include <stdio.h>

int main(void)
{
    int a = 5;
    int *ptr = &a;
    int **pptr = &ptr;

    printf("ptr's value: %p, *pptr's value : %p\n",ptr,*pptr);
    printf("**pptr's value : %d\n",**pptr);
    return 0;
}
```
위 코드에서 보았듯이 ptr이 가리키는 주소와 \*pptr이 가지고있는값이 동일하다는것을 알수있다.
여기에 \*를 한번 더 붙여주면 연산자 결합에 의해서 다음과 같이 변환이 된다.
\*(\*ptr) 이렇게 되면, 일단 \*ptr이 가지고있는 값을 가지고 한번 더 참조를 해 a의 값이 출력되는것이다.

그럼 이 포인터를 가리키는 포인터는 어디에 사용될까?

전 예제와 같이 swap하는 함수를 만든다고하자. 하지만 이번엔
교환을 수행하는 a,b가 포인터다. 기존의 swap 함수는, 이번에는
서로가 갖고있는 주소를 교환해야한다. 이 경우에도 swap(a,b)와 같이 호출을 하게 될거고, 그러면 a와 b가
가지고있는 주소를 복사해서 함수 내에서만 교환이 일어나게된다. 그러면 결국, 전과 같은 문제가
생기게된다. 이때, 더블 포인터를 사용해주면, 포인터변수 a와 포인터변수 b의 '주소'를 가지고 교환을
수행하기때문에 서로 갖고있는 주소가 교환이 된다. 아래 코드를 보자.

```
#include <stdio.h>

void swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 50,b = 60;

    int *a_ptr = &a, *b_ptr = &b;

    swap(&a_ptr,&b_ptr);

    printf("%d %d\n",*a_ptr, *b_ptr);
}
```

### 다차원 배열

이제, 다차원 배열에 대해서 알아보자.

먼저 이차원 배열에 대해서 알아보겠다

이렇게 이차원 배열은 열과 행으로 이루어져있다.

이차원 배열은 아래와 같이 선언한다.

`int two_dim[n][m]`

저걸 분석해보자면, m개의 요소를 담을수있는 배열을 n개를 묶어놓은 것이다. 그리고 아래와 같이 초기화할수있다.

`int two_dim[3][3] = {{1,2,3},{4,5,6},{7,8,9}};``

즉, 바둑판? 구조라고 생각하면 된다. 즉, 아래 그림과 같은 구조다.
![two_dim_arr](https://raw.githubusercontent.com/chin0/Layer7/master/day8/img/two_dimensional_arrays.jpg)

하지만, 실제로 메모리에는 아래와 같은 구조를 가지고있다.

![mul_dim_allocation](http://beginnersbook.com/wp-content/uploads/2014/01/memory-2D-diagram.png)

즉, 실제로 메모리에 적재되는 구조는, 이차원 배열이나 삼차원 배열이나 일차원 배열이나 갖다는 의미이다. 즉, 아래와 위의 two_dim을 아래와 같이 초기화할수도 있다.

`int two_dim[3][3] = {1,2,3,4,5,6,7,8,9};`

삼차원 배열도 마찬가지다. 아래와 같이 선언&초기화 할수있다.
```
int three_dim[3][3][3] = {
  {
    {1,1,1},
    {1,1,1},
    {1,1,1}
  },
  {
    {2,2,2},
    {2,2,2},
    {2,2,2}
  },
  {
    {3,3,3},
    {3,3,3},
    {3,3,3}
  }
};
```
삼차원배열 `int a[x][y][z]`는 z개의 요소를 담을수있는 배열을 y개 묶어놓은 배열을 x개 묶어놓은것과 같다고 생각하면 된다. 즉, 큐브구조다.

사차원 배열도 존재는 하지만, 그림으로는 표현할수없다.(4차원)

### 이차원 배열과 포인터

자, 그럼 이제 이차원 배열의 포인터를 알아보자.

배열은 일종의 상수형 포인터다. 그러면 이차원 배열은 어떤 형태의 포인터일까?

`int two_dim[n][m]`

위와 같은 n개의 행과 m개의 열을 가진 배열이 있다고 하자. 그러면 two_dim은 기본적으로 two_dim[0][0]의 주소를 가리키고있을것이다.

그러면, two_dim의 의미로 봤을때 two_dim은 m개의 요소를 담을수있는 배열을 n개 묶어놓은 배열이다.

그러면 two_dim의 포인터형은 m개의 크기를 가진 배열을 가리키는 포인터가 된다. 이를 c언어로 표현하면

`int (*ptr)[m]`

이된다. 아래 예제를 보자.

```
#include <stdio.h>

int main(void)
{
    int two_dim[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*two_dim_ptr)[3] = two_dim;

    printf("%d\n",two_dim_ptr[2][2]);
}
```

위코드는 two_dim[2][2]의 값을 출력하게된다.

함수에서 이차원 배열을 받을때도 위 포인터형과 같이

```
int two_dim_func(int (*arr)[m])
{
  ~~~
}
```
이런식으로 사용하면 된다.

### 배열포인터
배열 포인터는 배열을 요소로 갖는 포인터를 말한다.
선언은

`type *arr[n]`이다.

일단 배열포인터는 각 요소가 포인터인점을 이용해서 여러개의 포인터변수를 담아야할때나, 다음에 다룰 문자열의 배열로 사용된다.

```
#include <stdio.h>

int main(void)
{
    int a=1,b=2,c=3;

    int *arr[3] = {&a,&b,&c};
    char *string_arr[3] = {"hello","world","!!!"};

    for(int i = 0; i < 3; i++)
        printf("%d:%s\n",*arr[i],string_arr[i]);

    return 0;
}
```

### 문자열

문자열은 널문자를 포함한 문자들의 배열이다. 문자열을 선언하는 방법에는 두가지가 있다. 첫번째는 포인터를 이용한 선언과 두번째는 배열을 이용한 선언이다. 두개의 차이점을 알아보자.

일단 공통적인것은, 문자열은 쌍따옴표로 감싸서 넣는다.

`char *string = "abcdef";`

쌍따옴표는 임의의 메모리에 abcdef와 끝에 널문자를 넣고 그 주소를 리턴한다. string은 그 주소를 가리키게 된다.

여기서 char형 포인터로 선언된 문자열은 수정할수없다. 이유는 포인터로 선언된 문자열은 코드섹션에 문자열이 존재하는데 코드섹션은 읽기전용이기때문에 수정이 불가능하다.

반대로, 배열로 선언한 문자열은 수정이 가능하다. 다만, 꼭 문자열의 길이 + 1만큼 배열크기를 확보하자. (널바이트의 공간때문)

```
#include <stdio.h>

int main(void)
{
    char *ptr_string = "abcdef";
    char arr_string[7] = "hijklm";

    //포인터로 선언된 문자열은 수정할수없다.
    //ptr_string[3] = "B";
    arr_string[1] = 'I';

    printf("%s\n%s\n",ptr_string,arr_string):
}
```
### 문자열 처리 함수

문자열을 다루는 함수들을 알아보기전에 잠깐 입출력 스트림에 대해서 알아보자.

스트림에 대해서 이해하기전에 입출력에대해서 알아보자.

입출력이란 입력과 출력을 묶어서 말하는건데,

입력이란 데이터가 프로그램으로 들어오는것을 뜻하고 출력은 데이터가 프로그램에서 나가는것을 뜻한다.

여기서, 이 입출력의 대상은 네트워크의 소켓, 키보드와 모니터, 파일이 될수도 있다.

스트림은 프로그램과 모니터,키보드와 같은 장치들의 중간다리라고 보면된다. 이 스트림들은 기본적으로 3가지 종류가 있다.

- stdin - (키보드)정보를 입력하는데 사용하는 표준 입출력 스트림이다.
- stdout - (모니터)정보를 출력하는데 사용하는 표준 입출력 스트림이다.
- stderr - (모니터)에러정보를 출력한다

그리고 추가적으로 EOF는 파일의 끝을 의미한다. 더 정확히는 읽어올 데이터가 더이상 없음을 뜻한다.

키보드에서는 Ctrl + Z를 누르면 EOF신호를 보낸다.

이제 문자열을 처리하는 함수들에 대해서 알아보자.

(입출력 관련 함수는 stdio에 선언되어있다.)

일단 putchar과 fput은 아래와 같은 원형을 가지고있다.

`int putchar(int c)`

`int fputc(int c, FILE \*stream)`

두 함수 다 화면에 문자하나를 출력하고, 문제가 생기면 EOF를 리턴한다.

여기서 문자하나를 fputc를 이용해서 화면 출력하려면, stdout를 스트림 인자로 넘겨주면 된다.

문자하나를 입력받는 getchar와 fgetc의 원형은 아래와같다.
`int getchar(void)`

`int fgetc(FILE* stream)`

fgetc는 스트림에서 문자하나를 읽어오고(키보드에서 입력받고싶으면 stdin을 넘겨주면된다.) 그 문자를 리턴한다. getchar는 기본적으로 stdin으로부터 문자를 받는다. 문제가 생가면 EOF를 리턴한다.

문자열을 입출력하는 함수들도 있다.

`int puts(const char *s)`

`int fputs(const char *s, FILE *stream)`

두 함수 모두 문자열을 출력한다.(정확히는 널바이트를 만날때까지)
다만 입출력스트림을 받느냐 안받느냐, 그 차이다. 문제가 생기면 EOF를 리턴한다.

문자열을 입력받고 싶다면 아래 함수들을 사용하면된다.

`char* gets(char *s)`

`char* fgets(char *s, int n, FILE *stream) `

아래 함수는 문자열을 받을 배열을 받고, 거기에 입력된 값을 넣는다. 다만 fgets는 n만큼 문자열을 읽는다.

나중에 다룰 버퍼오버플로우에서 알겠지만, 길이를 검사하는 fgets가 gets보다 더 안전한 함수라고 할수있다.

그리고 입출력 스트림은 각각 성능향상을 위해 임시버퍼를 두고있는데, 이 버퍼에 데이터를 모아서 한꺼번에 전송한다.

fflush는 이 입출력 스트림에 있는 임시버퍼를 비워주는 역할을한다.

`int fflush(FILE *stream)`

성공하면 0 실패하면 1을 반환한다.

연속된 fgets나 fputs에서는 모아서 데이터를 보내기때문에 이때문에 입력이나 출력이 제대로 안이루어질수있다. 이때 fflush를 사용하는것이다.

이제 입출력말고 문자열에 관한 함수들을 다뤄보자.

일단 문자열에 관한 함수는 string.h에 선언되어있다.

문자열의 길이를 구하는 함수부터 알아보자.

`size_t strlen(const char* s)`

위 함수는 문자열 s를 널바이트까지 카운팅해서 리턴하는함수이다. 즉, 문자열의 길이를 리턴한다. 실패시 eof를 리턴한다.

문자열을 복사하는 함수도 있다.

`char* strcpy(char* dest, const char* src)`

`char* strncpy(char* dest, const char* src, size_t n)`

위 함수는 dest에 src의 내용을 복사한다. 다만 위의 함수는 널바이트까지, 아래의 함수는 n만큼 복사한다. 이도 마찬가지로 길이검사를 하는 strncpy가 보안면에서 훨씬 낫다.

그리고 문자열을 이어주는 함수도 있다.

`char* strcat(char* dest, const char* src)`

`char* strncat(char* dest,const char* src, size_t n)`

위 함수는 dest에 src문자열을 이어준다. 여기서 dest의 기존 널문자를 지워주고 src랑 이어준다.

위 복사함수와 마찬가지로 널바이트까지냐, n바이트만큼이냐 이 차이밖에 없다.

문자열을 비교하는 함수는 아래와 같다.

`int strcmp(const char *s1, const char *s)`
`int strcmp(const char *s1, const char *s, size_t n)`

리턴값은

- s1이 더 크면 0보다 큰값,
- s2가 더 크면 0보다 작은값,
- 내용이 같으면 0을 반환한다.

여기서 문자열의 대소비교는 틀린부분의 아스키코드의 차로 한다.

## 구조체와 typedef

### 기본

구조체는 서로 다른 타입의 변수들을 하나로 묶어놓은것을 말한다.

구조체 선언은 아래와 같이 한다.

```
struct point
{
    int x;
    int y;
};
```
여기서 각 요소를 멤버라고 한다.

중요한건 마지막에 꼭 세미콜론을 붙여줘야한다.

위와같이 선언한 구조체는 아래와 같이 선언하고 초기화해줄수있다.

방법1:

```
struct point a = {1,2}
```

방법2:

```
struct point a;
a.x = 5;
a.y = 6;
```

위와같이 선언된 구조체는 기본적으로 구조체의 가장 첫번째 멤버를 담고있다.

여기서 .은 구조체 멤버에 접근할수 있게 해주는 연산자다.

```
#include <stdio.h>

typedef struct point
{
    int x;
    int y;
};
int main()
{
    point a = {1,2};
    printf("%d\n",a.y);
}
```

그리고 구조체에 대한 포인터도 만들수있다.

구조체에 대한 포인터도 일반 포인터 선언과 매우 유사하다.

`struct point *a`

위와 같이 선언하면 된다. 다만 멤버의 접근하는 방식이 조금 다르다. 한번 보다.

```
#include <stdio.h>

struct point
{
    int x;
    int y;
} ;

int main()
{
    struct point a = {1,2};
    struct point *pa = &a;

    //1. 멤버 연산자를 이용한 접근
    printf("%d\n",(*pa).y);

    //2. 포인터 멤버 연산자를 이용한 접근
    printf("%d\n",pa->y);
}
```
보통 가독성이 더 좋은 2번을 많이 사용한다.

### typedef
typedef는 프로그래머가 기존의 자료형에 새 이름을 붙여주는 예약어다. 예를들어

`typedef unsigned long long int ull`

이렇게 하면 매우 긴 이름을 가진 unsigned long long int를 더 간편하게 사용할수있다. 구조체에서도 비슷하게

```
typedef struct point{
  int x;
  int y;
} point;
```

이런식으로 선언해서 struct point가 아닌, point로 더 간편하게 사용할수있다.

주로 복잡한 이름을 가진 자료형에서 많이 쓰인다.

### 중첩 구조체

중첩 구조체는 말그대로 구조체안에 구조체가 들어가있는것이다.

밑에 예제코드를 보자.

```
#include <stdio.h>

typedef struct point
{
    int x;
    int y;
} point;

typedef struct line
{
    point p1;
    point p2;
} line;

int main()
{
    struct line a = {{1,2}, {2,3}};

    printf("line's p1: %d %d\n",a.p1.x, a.p1.y);
    printf("line's p2: %d %d\n",a.p2.x, a.p2.y);
}
```
위와 같이 이차원 배열과 비슷하게 초기화를 해주면 된다.

구조체를 사용하는 이유는 무엇일까?
- 데이터의 분류
- 재사용

### 공용체

공용체는 흔히 사용되지 않지만, 어쨌든 공간을 공유하는 구조체! 정도로 이해하면 된다. 그림을 보자.

![union](https://raw.githubusercontent.com/chin0/Layer7/master/day8/img/union-and-structure-storage-comparison.gif)

위 그림과 같이 가장 큰 크기를 가진 멤버의 공간을 공유한다.

코드를 보자.
```
#include <stdio.h>

union a{
    unsigned int x;
    unsigned short int y;
    unsigned char z;
};
int main()
{
    union a uni;

    uni.x = 0x12345678;
    uni.y = 0xdead;
    uni.z = 0xff;


    printf("uni.x: %x\n",uni.x);
    printf("uni.x's address: %p\n",&uni.x);
    printf("uni.y's address: %p\n",&uni.y);
    printf("uni.z's address: %p\n",&uni.z);
}
```
각 x,y,z멤버의 주소가 같고, 각 멤버의 값이 변할때마다 x의 값이 바뀐다. 다만 뒤에서부터 변하는걸 확인할수있는데 이는 컴퓨터가 데이터를 저장하는 방식이 리틀엔디언이기 때문이다.

## 열거형
이름을 갖는 정수형의 상수를 정의한다. 열거형은 예약어 enum을 사용하여 정의한다.

```
enum test_enum
{
  열거리스트;
};
```

이와 같이 선언해서 사용할곳에(전역이든 지역이든)

`enum test_enum name`으로 선언후 상수를 사용하듯이 쓰면 된다.

그리고 enum은 기본적으로 초기화를 안했을시 0부터 시작하고 만약 아래와 같이

```
enum test_enum{a=10,b,c=20,d};
```

이런식으로 선언하면 b는 전요소 + 1의 값을 갖게된다. 그러므로 b는 11이다.

그리고 d도 마찬가지로 전요소 + 1의 값을 갖게되니까 d는 21이다.