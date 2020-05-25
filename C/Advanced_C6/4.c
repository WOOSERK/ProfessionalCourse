#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// char, signed char, unsigned char는 문자 타입이다.
// 하지만 이는 서로 다른 타입으로 서로 호환 가능하지 않다.
// 따라서 문자 또는 문자열을 처리하려면 가급적 char 타입을 사용하는 것을 권장한다.

int main()
{
	char str1[] = "hello, world";
	char str2[] = "hello, world";
	char str3[] = "hello, world";

	printf("%d\n", strlen(str1));
	printf("%d\n", strlen(str2));
	printf("%d\n", strlen(str3));
}