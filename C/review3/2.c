
// 인라인 키워드는 명령이 아니라 힌트이므로 상황에 따라 동작하지 않을 수 있다.

#if 0
// 인라인 키워드가 동작하지 않는 경우 1. 함수 포인터를 사용하는 경우
#include <stdio.h>

void foo() {}
inline void goo() {}

int main()
{
	foo();	// call foo
	goo();	// inline goo

	int n;
	scanf("%d", &n);

	void(*fp)();

	if (n == 0)
		fp = foo;
	else
		fp = goo;

	fp(); // call! no inline 컴파일러가 fp에 뭐가 들어갔는지 알 수 없으므로 inline으로 동작하지 않는다.
}
#endif



// 인라인 키워드가 동작하지 않는 경우 2. 함수의 크기가 큰 경우
// 때문에 함수의 라인 수가 2~3줄 이하인 함수의 경우에만 inline 키워드를 사용하기를 권장한다.

#include <stdio.h>
// 인라인 키워드가 동작하지 않는 경우 3.  재귀 호출
int fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}

int main()
{
	printf("%d\n", fact(5));
}

// 인라인 함수의 단점 : 자칫 목적 파일의 크기가 커질 수 있다.