
#include <stdio.h>

// ���ڿ� ����� ���� �����͸� ������ ���, �ݵ�� ��� ���� �����͸� ����ؾ� �Ѵ�.

int main()
{
	char s1[] = "hello, world";
	const char* s2 = "hello, world"; // char* s2 = 0x12FF60;

	s1[0] = ' '; // stack����(rw)�� ���� �����ϴ� ���̹Ƿ� ����
	s2[0] = ' '; // read only data�� ���� �����ϴ� ���̹Ƿ� ��Ÿ�ӿ� ����.
				 // �����Ϸ��� rodata���� �𸣹Ƿ� ������ Ÿ�ӿ��� ���� ����

	printf("%s\n", s1);
	printf("%s\n", s2);
}