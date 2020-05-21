
#if 0
#include <stdio.h>
#include <stdarg.h>

// int average(int a, int b, int c) { return (a + b + c) / 3; }
// 가변인자를 사용하려면 반드시 첫 번째 매개변수는 고정되어 있어야 한다.
#define VA_END (-1)
int average(int a, ...)
{
	// 1. 가변인자 리스트 선언
	va_list args;
	
	// 2. 가변인자 리스트 초기화
	va_start(args, a);

	int cnt = 0;
	int sum = 0;

	int i = a;
	while (i != VA_END)
	{
		printf("%d\n", i);
		sum += i;
		++cnt;
		i = va_arg(args, int); // 3. 다음 매개 변수를 읽어옴
	}

	// 4. 가변인자 리스트 정리(cleanup)
	va_end(args);
	return cnt ? sum / cnt : 0;

	return 0;
}

int main()
{
	printf("%d\n", average(10, 20, 30, VA_END));
	//																		^--- 센티널

	// 센티널을 사용하지 않고도 평균을 올바르게 계산할 수 있도록 함수를 변경해 보자

}
#endif



// 이전 코드는 센티널 코드를 반드시 사용해야 하는 단점이 있다.
#include <stdio.h>
#include <stdarg.h>

int average(int cnt, ...)
{
	if (cnt == 0)
		return 0;
	else if (cnt < 0)
		return -1;

	va_list args;
	va_start(args, cnt);

	int sum = 0;

	for (int i = 0; i < cnt; i++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);
	return sum / cnt;
}

int main()
{
	printf("%d\n", average(3, 10, 20, 30));
}