
#include <stdio.h>

// fgets �Լ� ���н�, ���ڷ� ���޵� ���۴� �� �� ���� ���·� ���ǵǹǷ� ����ϸ� �ȵȴ�.
// �� ������ �ذ��Ϸ��� �ش� ���۸� �� ���ڿ��� �����ϸ� �ȴ�.
int main()
{
	char buf[5];
	if (fgets(buf, sizeof(buf), stdin) == NULL)
	{
		//return -1;
		fprintf(stderr, "fgets error\n");
		*buf = '\0';
	}


}