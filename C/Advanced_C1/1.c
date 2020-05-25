#if 0
#include <stdio.h>

int main(void)
{
	//int i = 0;
	//int* p = &i; // ������(pointer to integer)

	//*p = 10; // OK, ���ü�� ����
	//p = 0; // OK, �����ʹ� ����

	//int i = 0;
	//// ����� �����Ϳ� ���Ͽ� �������� �����ϸ� ���ü�� Ÿ���� �ǹ��Ѵ�.

	//const int* p = &i; // ��� ���� ������(pointer to constant)
	////*p = 10; // ERROR, ���ü�� ���
	//p = 0; // OK, �����ʹ� ����

	//int i = 0;
	//int* const p = &i; // ��� ������(constant pointer to)
	//*p = 10; // OK, ���ü�� ����
	//p = 0; // ERROR, �����ʹ� ���

	//int i = 0;
	//int const* p = &i;
	//// *p = 10; // ERROR, ���ü�� ���
	//p = 0; // OK, �����ʹ� ����

	//int i = 0;
	//const int* const p = &i; // ��� ���� ��� ������(constant pointer to constant)
	//*p = 0; // ERROR, ���ü�� ���
	//p = 0; // ERROR, �����͵� ���
}
// ����! ������ ��ȣ�� �߽����� *�� ���ʿ� ������ ���ü�� ���ȭ, �����ʿ� ������ �����Ͱ� ���ȭ�˴ϴ�.

#endif

#if 0
#include <stdio.h>

int main(void)
{
	//int i = 0; int *pI = 0;
	//float f = 0; float *pF = 0;
	//double d = 0; double *pD = 0;

	// ������ �������� ������ Ÿ���� �ǹ�
	// �����Ϸ����� ���ü�� ũ��(offset) ������ �˷��ֱ� ����
	//int x = 300;
	//char* p = &x;
	//printf("%d", *p);

	// 2����Ʈ �̻��� ������ �����մϴ�.
	unsigned int x = 1; // 0x00000001
	unsigned char* p = (unsigned char*)&x;
	if (*p == 1)
		printf("little endian\n");
	else
		printf("big endian\n");
}
#endif


#include <stdio.h>

int main(void)
{
	// �迭�� ���� : Ÿ�� �迭��[ũ��]
	int arr[3];

	// �迭���� �ǹ� : ù ��° ������ ���� �ּҸ� �ǹ��ϴ� ��� ������
	// arr = 0; // ERROR
	printf("%d\n", arr);
	printf("%d\n", &arr);

	// �迭 ������ ����
	int* p1 = arr;
	int(*p2)[3] = &arr;

	printf("sizeof(arr) = %u\n", sizeof(arr));

}