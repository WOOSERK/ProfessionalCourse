
#include <stdio.h>
#include <string.h>

// ��� : ��� Ÿ���� ��ü�� ���� Ÿ������ ĳ�������� ����
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
