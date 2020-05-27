
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
int main()
{
	const char* str = "10000000000"; // 100��
	char* endPtr = NULL;

	// LONG_MAX �Ǵ� LONG_MIN�� ���� ������ �����ϱ� ��ƴٴ� ������ �ִ�.
	// �̷��� ������ �ذ��ϱ� ���� ���� �ڵ带 �����Ѵ�.

	errno = 0; // �� ������ ���� �����̹Ƿ� �ٸ� ���� ����Ǿ� ���� �� �ִ�.
			// ���� ��� ������ �ݵ�� 0���� ��������� �Ѵ�.
	long num = strtol(str, &endPtr, 0); // 10���� : 0
	//if (endPtr == str || (num == LONG_MAX || num == LONG_MIN))
	if(endPtr == str || ((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE))
	{
		fprintf(stderr, "strtol error\n");
		return -1;
	}
	
	printf("%d\n", num);
}