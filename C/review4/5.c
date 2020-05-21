
#if 0
#include <Windows.h> // CreateThread
#include <stdio.h>

unsigned long __stdcall threadMain(void* p)
{
	for (int i = 0; i < 10; i++)
	{
		Sleep(1000);
		printf("\t\t[worker thread]\n");
	}
	return 0;
}

int main()
{
	CreateThread(0, 0, threadMain, 0, 0, 0); // �� ���� �����尡 �����ǰ� �����Ѵ�.

	while (1)
	{
		Sleep(1000);
		printf("[main thread]\n");
	}

	return 0;
}
#endif


#include <Windows.h> // CreateThread
#include <stdio.h>

// volatile : ���� ���α׷��� �ƴ� �ܺ����� ���ο� ���Ͽ� �� ���� ����� �� �ִٰ� �����Ϸ����� �˷� ĳ���� ������ �� ����ϴ� Ű����
// ���� ĳ�õǾ�� �ȵǴ� �����Ϳ� ���ؼ��� �ݵ�� volatile�� ����ؾ� �Ѵ�.
volatile int flag = 1;
unsigned long __stdcall threadMain(void* p)
{
	Sleep(5000);
	flag = 0;
	return 0;
}

int main()
{
	CreateThread(0, 0, threadMain, 0, 0, 0); // �� ���� �����尡 �����ǰ� �����Ѵ�.

	while (flag)
		;

	return 0;
}