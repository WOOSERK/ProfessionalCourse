
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// �׻� ���ڿ��� ���� �� ���ڷ� ���� �� �ֵ��� ����
// ����� ���ڿ� ó�� �� �������� �� ���ڸ� �����ϴ� ���̴�.
#define STR_SZ (5)

int main()
{
	const char str[] = "abcdefghijklmnopqrstuvwxyz";

	char dst[STR_SZ] = { 0, };
	// ...
	// dst[sizeof(dst) - 1] = '\0';
	strcpy(dst, str, sizeof(dst));
	dst[sizeof(dst) - 1] = '\0';
	printf("%s\n", dst);
}