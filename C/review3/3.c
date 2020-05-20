
// 매크로 연산자 이야기
// 1. a##b : ab 두개의 토큰을 연결하는 연산자
// 2. #x : 토큰을 문자열화하는 연산자
// 3. #@x : 길이가 1인 토큰을 문자화하는 연산자
#include <stdio.h>
#define CONCAT(x, y) x##y
#define TO_STRING(x) #x
#define TO_CHAR(x) #@x // 마이크로소프트 컴파일러 전용

int main()
{
	printf("%d\n", CONCAT(2020, 12));
	printf("%s\n", TO_STRING(hello));
	printf("%c\n", TO_CHAR(h));
}