
#include <stdio.h>
#define ARR_SIZE (6)

// ���ڿ��� ���� ������ �� ���� ���ڸ� ��⿡ ������� �����ؾ� �Ѵ�.
int main()
{
	char src[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		src[i] = 'A' + 1;

	char dst[ARR_SIZE];
	int i;
	for (i = 0; src[i] && i < sizeof(dst); i++); // ���� �����÷� �߻�
		dst[i] = src[i];

	dst[i] = '\0';
	printf("%s\n", dst);

	return 0;
}