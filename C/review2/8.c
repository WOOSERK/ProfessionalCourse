#include <stdio.h>

int __stdcall sqr(int x)
{
	int result = x * x;

	return result; // mov eax, result
}

int main()
{
	// int result = sqr(2);
	int n;

	// _asm ��ɾ ����ϸ� �ҽ� �ڵ� �ȿ� ������ ������ �� �ִ�.
	// sqr(2); -> �Ű������� �����ʿ������� ���ÿ� ����ȴ�.
	_asm
	{
		push 2
		call sqr
		mov n, eax
	}

	printf("%d\n", n);
}