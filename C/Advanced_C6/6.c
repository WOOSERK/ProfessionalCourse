#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// strtok �Լ� ���� �Ľ̵Ǵ� ���ڿ��� �����ȴٴ� ������ �ϸ� �ȵȴ�.
// ���� ������ �����Ϸ��� �����Ͽ� ����ؾ� �Ѵ�.
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