#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��谡 �Һи��� �ҽ��κ��� ������ ������ �迭�� �����ϴ� ���� �ſ� �����ϴ�.
// ���� �����÷ΰ� �߻��� �� �ִ�.

// �ذ� ���
// 1. ���� �Ҵ� -> �ӽ� ���ۿ��� �����÷ΰ� �߻��� �� �����Ƿ� �������� �ʴ´�.
// 2. ��� ������ ���̸� ����ϴ� �Լ�
// 3. ���� ������ ���

int main()
{
	char buf[32];
	// fgets(buf, sizeof(buf), stdin); // gets(buf); // scanf("%s", buf);

	scanf("%15s", buf);
	printf("%s\n", buf);

	return 0;
}