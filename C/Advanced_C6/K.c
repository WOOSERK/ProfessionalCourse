
#include <stdio.h>
#include <string.h>
// fgets : ���ۺ��� ���� ���� ���� ������ ������ ���Եǰ� �� ���� �η� ������.
// ������ ũ�⺸�� ���ų� ū ���� ������ ���� ���� �߰��Ѵ�.
int main()
{
	char buf[32];

	for (int i = 0; i < 32; i++)
		buf[i] = 'X';

	// fgets �Լ��� ������ ���, NULL�� ��ȯ�Ѵ�.
	if (fgets(buf, sizeof(buf), stdin))
	{
		// ��Ȳ�� ���� ������ �ƴ� ���� �Էµ� ���
		if (*buf) // ���� �ƴ� ���ڷ� ���۵Ǵ� ���
		{
			buf[strlen(buf) - 1] = '\0';  // �Էµ� ���ڿ����� ������ ����� �ڵ�
		}
		printf("%s", buf);
	}
	else
	{
		printf("fgets error\n");
		return -1;
	}
	return 0;
}