
#include <stdio.h>

// ����� FILE ��ü�� ���Ͽ� ���纻�� ����ϸ� �ȵȴ�.
int main()
{
	fputs("hello, world\n", stdout);

	FILE* fp = stdout; // ���� ������
	fputs("hello, world\n", fp);

	FILE file = *stdout;
	fputs("hello, world\n", &file);
}