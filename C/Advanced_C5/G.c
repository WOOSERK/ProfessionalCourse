
// ���� ī���ͷ� �ε� �Ҽ����� ������� ����
#include <stdio.h>

int main()
{
	int cnt = 0;
	for (float f = 0.0f; f <= 1.0f; f += 0.1f)
		++cnt;

	printf("%d\n", cnt);
}