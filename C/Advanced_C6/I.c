
#include <stdio.h>

#define LOG_FILE "log.txt"
// ���ÿ� ���� ������ ���� �� ���� �ʴ� ���� ����.
// �ϳ��� ������ ���ÿ� �� ���, �̿� ���� ������ ����(�����Ϸ�)���� �ٸ��� ���ǵǾ� �־�
// ��� ������ �� ������ �� ����.
void foo()
{
	FILE* log = fopen(LOG_FILE, "a");
	// ...
}

int main()
{
	FILE* log = fopen(LOG_FILE, "a");

	foo(log);

	// ... 
}