
// ��ũ�� ������ �̾߱�
// 1. a##b : ab �ΰ��� ��ū�� �����ϴ� ������
// 2. #x : ��ū�� ���ڿ�ȭ�ϴ� ������
// 3. #@x : ���̰� 1�� ��ū�� ����ȭ�ϴ� ������
#include <stdio.h>
#define CONCAT(x, y) x##y
#define TO_STRING(x) #x
#define TO_CHAR(x) #@x // ����ũ�μ���Ʈ �����Ϸ� ����

int main()
{
	printf("%d\n", CONCAT(2020, 12));
	printf("%s\n", TO_STRING(hello));
	printf("%c\n", TO_CHAR(h));
}