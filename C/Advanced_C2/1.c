
#if 0
// 2���� �迭 : ���Ұ� 1���� �迭�� 1���� �迭
// N���� �迭 : ���Ұ� N-1������ �迭�� ���� 1���� �迭

#include <stdio.h>

int main(void)
{
	int arr1[3] = { 1,2,3 };
	int* pArr1 = arr1;

	int arr2[2][3] = { {1,2,3}, {4,5,6} };
	int (*pArr2)[3] = arr2;
}
#endif

#if 0
// �迭�� ���� �Ҵ�
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ���̰� 6�̰� int Ÿ���� �迭 ����
	// int arr[6]; // ���ÿ� ����
	// malloc(sizeof(int) * 6);
	
}
#endif


#if 0
// �������� ����
#include <stdio.h>

int main()
{
	int *p = 0;
	int *q = 0;
	
	// �����Ϳ� �����͸� ���� �� ����.
	// p + q;
	// p - q;
	// p * q;
	// p / q;

	//p + 1; // ������ + ���� = ������
	//p - 1; // ������ - ���� = ������
	//p * 1; // ������ * ���� = �Ұ���
	//p / 1; // ������ / ���� = �Ұ���
}
#endif


#if 0
// �����Ϳ� ��� ����
#include <stdio.h>

int main()
{
	int i = 0;
	printf("%d\n", i + 1);

	// �����Ϳ� ������ ���� ����� ���ü ũ���� �����ŭ ���ȴ�.
	int* p = 0;
	printf("%d\n", p + 1); // p + sizeof((*p) * 1)
}
#endif


#if 0
#include <stdio.h>

int main()
{
	int arr[2][3] = { {1,2,3},{4,5,6} };
	int(*p)[3] = 0;
	printf("%d\n", arr);
	printf("%d\n", (arr+1)[2]);

}
#endif