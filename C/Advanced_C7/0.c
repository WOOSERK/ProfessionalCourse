
// fgets �Լ��� ����� ��, �׻� ���� ���ڰ� ������ �Ŷ�� �����ϸ� �ȵȴ�.
// fgets �Լ��� ���� �Է� ��Ʈ�����κ��� ���� ���ڷ� ����� ���ڿ��� �б� ���� ����Ѵ�.
// �� ��, ���ڿ��� ������ ����� ���� ���ԵǴµ� ���� �־��� ������ ũ�⸦ �Ѿ�� �Էµ� ���, ������ ���� �ηθ� ä������.

#include <stdio.h>
#include <string.h>

int main()
{
	char buf[5];

	fgets(buf, sizeof(buf), stdin);
	
	// �ش� ���ڿ��� Ư�� ���ڰ� �ִ��� Ȯ���ϴ� �Լ� : strchr
	char* p = strchr(buf, '\n');
	if (p)
	{
		buf[strlen(buf) - 1] = '\0';
	}

	for (int i = 0; i < 5; i++)
		printf("[%d]", buf[i]);
		
	printf("\n");

	return 0;
}