
#include <stdio.h>
#include <limits.h>

// C99 ǥ�ؿ� ������ ��ȣ ���� ������ ���Ͽ� ����� �����ϸ� ���� �����÷ΰ� �߻����� �ʴ´ٰ� �Ѵ�.
// �� ������ ��� ���� ����� �� ���� Ÿ������ ǥ���� ���, ������ �������� ���� �ٿ� ǥ���ϱ� �����̴�.
int main()
{
	// ���� ������ �߻��ϱ� ���� �̸� �׽�Ʈ�Ѵ�.
	unsigned int uint1, uint2, sum = 0;
	uint1 = UINT_MAX;
	uint2 = 1;

	if (uint1 > UINT_MAX - uint2)
	{
		fprintf(stderr, "���� ������ �߻��Ͽ����ϴ�.\n");
		return -1;
	}
	
	sum = uint1 + uint2;
	printf("%d\n", sum);
}