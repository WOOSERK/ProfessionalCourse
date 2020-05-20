#if 0
#include <stdio.h>
#include <assert.h>
#pragma pack(1)
// assert: ��༺�� �� �� �ִ� ����Ʈ������ ������ ã�Ƴ��µ� ȿ������ ����
// ����
// 1. abort �Լ��� ȣ���ϹǷ� ������ �Ӻ���� �ý��ۿ��� ����ϱⰡ ��������
//2. �Լ��̹Ƿ� �ݵ�� ���α׷��� �����Ǿ�߸� �˻� �����ϴ�.(��Ÿ�� ������尡 �߻�)
//3. ��쿡 ���󼭴� �������� ���� ���� �ִ�.


typedef struct
{
	char cmd; // ��Ŷ�� ����
	int len; // ��Ŷ�� ����
	// ������
} Header;

void foo(int* p)
{
	// if(p==NULL) return;
	assert(p != NULL);
}

int main()
{
/*	if (sizeof(Header) != 5)
	{
		fprintf(stderr, "header size is not 5\n");
		return -1;
	}*/
	assert(sizeof(Header) == 5); // ����� ũ��� 5�̾�� �մϴ�.(����)
}
#endif


#if 1
#include <stdio.h>
#include <assert.h>
#define __JOIN(x, y) x##y
#define JOIN(x, y) __JOIN(x, y)
#define STATIC_ASSERT(e)	typedef char JOIN(assertion_failed_at_line_, __LINE__)[(e) ? 1 : -1]
typedef struct
{
	char cmd; // ��Ŷ�� ����
	int len; // ��Ŷ�� ����
	// ������
} Header;

int main()
{
	STATIC_ASSERT(sizeof(Header) == 8);
}
#endif