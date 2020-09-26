# "libft.h" 

------

1. #### ft_memset.c

- ```c
  void  *ft_memset(void *dest, int c, size_t n)
  ```

##### : dest(어떤 메모리의 시작 주소)부터 연속된 n바이트 만큼 c로 모두 초기화할때 사용.

+a _ 메모리에 접근할 때 signed char형이 아닌 unsigned char형을 사용하는 이유.

- unsigned char 외 다른 type의 경우, 내부 비트의 일부를 값을 표현하기 위한 용도 외에 다른 용도(부호비트)로 사용할 수 있으나, unsigned char는 그렇지 않음. 따라서, 임의의 메모리에 byte단위로 접근하여 값을 다룰 때에는 unsigned char를 사용해야 full portability(이식성)를 얻을 수 있다.

- memset은 byte 단위로 쓰기때문에"0, -1, 0x3f, 0x7f, 문자열 초기화 문자" 만 2번째 인자로 가능.

2. #### ft_bzero.c

- ```c
  void  ft_bzero(void *dest, size_t n)
  ```

: dest(어떤 메모리의 시작주소)부터 연속된 n바이트 만큼 0으로 모두 초기화할때 사용.



3. #### ft_memcpy.c

- ```c
  void  *ft_memcpy(void *dest, const void *src, size_t size)
  ```

##### : src메모리를 dest로 n바이트만큼 복사한다. 메모리 영역은 겹치지 않으며, 만약 겹쳐서 사용한다면 memmove를 사용한다.

+a _ 메모리를 겹쳐서 사용할 경우, 복사된 이후의 데이터가 복사됨. 예를 들어 자기 자신의 내용을 copy하여 자기 자신에게 한칸 뒤부터 덮어쓰는 경우, 인접한 메모리에 의해 overlap이 발생. 결국 원하지 않는 결과를 야기한다. 안전하지 않음. 정리하자면, memcpy는 메모리 내용을 직접 copy하기 때문에 메모리 영역이 겹치지 않는다면 속도가 빠름. memmove는 copy할 내용을 임시 공간에 저장한 후 copy하기때문에 속도는 느리지만 안전함.

4. #### ft_memccpy.c

- ```c
  void *ft_memccpy(void *dest, const void *src, int c, size_t n)
  ```

##### : src 의 데이터를 n바이트 만큼 dest에 복사. 복사하는 도중 src에서 c를 만나면 c까지 복사 후 복사를 중단하고, 복사된 dest에서 복사가 끝난 다음 주소를 return. 만약 c를 만나지 않으면 n바이트 복사 후 null을 return.

+a _ 복사되어 나온 dest문자열 끝부분의 주소값을 return하기 때문에,

​		*주소 = '\0';	의 방법으로 특정 문자 뒤의 문자열을 잘라낼 수 있는 기능으로 쓸 수 있다.

