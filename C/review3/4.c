
#if 0
// �̸� ���ǵ� ��ũ��
#include <stdio.h>

int main()
{
	printf("%s\n", __FILE__); // ���� ��ó������ ���� �̸�
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%d\n", __LINE__);
	printf("%s\n", __func__); // �Լ��� �̸�, �����Ϸ��� �����ϴ� �ɺ�
	printf("%s\n", __FUNCTION__); // �Լ��� �̸�, �����Ϸ��� �����ϴ� �ɺ� 
}
#endif


#include <stdio.h>
#define _TO_STR(x) #x
#define TO_STR(x) _TO_STR(x)
#define MSG(msg) \
do \
{ \
printf(__FILE__);\
printf("(" + __LINE__ + ")");\
printf(" : " + msg);\
} while(0)

int main()
{
	//x;
	// �Ʒ��� ����� ����Ͽ� �޽����� �����ϸ� ������ ���� �������� ��µǵ��� ��ũ�θ� �����غ���.
	
	// printf("hello" "world") // ���ڿ��� ���ڿ� ���̿� ������(����, ��, ����)�� ���� ��� �̸� �ϳ��� ���ڿ��� �ؼ��Ѵ�.

#pragma message(__FILE__ "(" TO_STR(__LINE__) "):" "hello, world") // C:\...\4.c(23) : hello, world
}