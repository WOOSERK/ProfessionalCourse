
#include <stdio.h>

// char, signed char, unsigned char�� ��Ʋ�� ���� Ÿ���̶�� �Ѵ�.
// �� ��, char Ÿ���� C ǥ�ؿ��� ��ȣ �ִ� Ÿ������ ��ȣ ���� Ÿ��������
// ����ϰ� ���� �ʴ�.
// �ٸ� ���ڸ� ������ ���� char�� ��ȣ ���� ������ ������ ���� unsigned char��
// ��ȣ �ִ� ������ ������ ���� signed char�� ����϶�� �����ϰ� �ִ�.

// ���� ���� ������ ���� ��ȣ�� ������ ��Ȯ�ϰ� ����Ͽ� ����ؾ� �Ѵ�.

int main()
{
	unsigned char c = 200;
	int i = 1000;

	printf("%d\n", i / c);

	signed char x = -1; // 1111 1111
	printf("%u\n", x); // ??
}