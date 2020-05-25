#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// strtok 함수 사용시 파싱되는 문자열이 보존된다는 가정을 하면 안된다.
// 따라서 원본을 보존하려면 복사하여 사용해야 한다.
int main()
{
	char str[] = "hello, world";
	char copy[32];
	strcpy(copy, str);

	char* token = strtok(copy, ",");
	printf("%s\n", token);
	printf("%s\n", str);

	return 0;
}