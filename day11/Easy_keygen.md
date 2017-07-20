# Easy_keygen

1. **개요**

문제는 시리얼값이 5B134977135E7D13가 나올때의 이름값을 찾는것이다.

입력부분이다. 여기서 ESP+10과 ESP+11, ESP+12에 각각 10과 20과 30을 넣어주는데, 나중에 중요한부분이니까 일단 보고가자. 그리고 Input Name:을 출력한다.

그 다음에 scanf로 입력을 받는다.

- REPNE SCAS BYTE PTR ES:[EDI]

- - EDI와 AL이 같지 않으면 EDI++ ECX—를 수행하고 반복한다.
  - 만약 같으면 반복을 멈춘다.
  - 여기서 EAX는 0이므로 널바이트를 찾는것이 된다.(EDI는 이때 문자열을 가리킴.)

- 이때 ECX를 0xFFFFFFFF로 설정해놓고 뺀다.

- 그다음에 비트반전을 하는데, 결국 문자열의 길이를 구하는 연산이 된다.

그 뒤에는 키젠연산인데, 입력받은 문자열을 아스키코드로 바꿔 0x10,0x20,0x30순으로 XOR한다.

즉,

1번째 문자 ^ 0x10

2번째문자 ^ 0x20

3번째문자 ^ 0x30

4번째문자 ^ 0x10

이런식으로 된다.

그리고 이 아스키값을 sprintf로 추정되는 함수로 메모리에 출력해서 키젠을 한다.

이를 복호화하는 코드는 다음과 같다.

```python
encrypt = [0x10,0x20,0x30]

data = raw_input()

key = ''

if not len(data) % 2 == 0:

    print "wrong format!"

for i in range(0,len(data)/2):

    print hex(int(data[i2:i2+2],16))

    key += chr(int(data[i2:i2+2],16) ^ encrypt[i % 3])

print key

```



