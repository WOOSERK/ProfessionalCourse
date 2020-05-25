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

	// _asm 명령어를 사용하면 소스 코드 안에 어셈블리어를 삽입할 수 있다.
	// sqr(2); -> 매개변수는 오른쪽에서부터 스택에 저장된다.
	_asm
	{
		push 2
		call sqr
		mov n, eax
	}

	printf("%d\n", n);
}