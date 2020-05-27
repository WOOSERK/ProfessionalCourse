
#include <stdio.h>
#include <windows.h>
// step 1. ������ �����ϴ� �迭�� �����غ���.
int arr[5];
int size = sizeof(arr) / sizeof(*arr);
int count; // �迭 ���� ������ ���� & ������ ���� ��ġ

// �ٸ� ���̺귯���� �ɺ��� �浹�� ���� ���� ���������� ���̺귯�� �̸���
// ���ξ�� ����Ѵ�.

int arrayAdd(int data)
{
	if (size == count)
	{
		fprintf(stderr, "���� ���忡 �����Ͽ����ϴ�.\n");
		return 0;
	}

	arr[count++] = data;
	printf("���� ���忡 �����Ͽ����ϴ�.\n");

	return 1;
}

void arrayDisplay()
{
	system("cls"); // cls : �����쿡�� ȭ���� ����� ��ɾ�
	// clear : ���������� ȭ���� ����� ��ɾ�

	for(int i=0; i<size; i++)
	{
		if (i < count)
			printf("[%2d]", arr[i]);
		else
			printf("[%2c]", ' ');
	}
	getchar();
}


int main()
{
	arrayDisplay();
	for(int i=0; i<size; i++)
	{
		arrayAdd(i);
		arrayDisplay();
	}
}


