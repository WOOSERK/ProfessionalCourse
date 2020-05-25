
#include <stdio.h>

// 문자열 상수에 대한 포인터를 선언할 경우, 반드시 상수 지시 포인터를 사용해야 한다.

int main()
{
	char s1[] = "hello, world";
	const char* s2 = "hello, world"; // char* s2 = 0x12FF60;

	s1[0] = ' '; // stack영역(rw)의 값을 변경하는 것이므로 가능
	s2[0] = ' '; // read only data의 값을 변경하는 것이므로 런타임에 오류.
				 // 컴파일러는 rodata인지 모르므로 컴파일 타임에는 정상 동작

	printf("%s\n", s1);
	printf("%s\n", s2);
}