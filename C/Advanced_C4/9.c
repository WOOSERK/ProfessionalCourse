
#include <stdio.h>
#include <string.h>

// 결론 : 상수 타입의 객체를 비상수 타입으로 캐스팅하지 말자
int mystrlen(const char* str)
{
	const char* base = str;
	while (*str)
		str++;
	return str - base;
}

int main()
{
	printf("%d\n", strlen("hello"));
	printf("%d\n", mystrlen("hello"));
}
