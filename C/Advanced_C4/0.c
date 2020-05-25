
#if 0
// 오류 처리 이야기
#include <stdio.h>

int div(int a, int b)
{
	return a / b;
}

int main()
{
	int ret = div(4, 2);
	printf("%d\n", ret);
}
#endif



#if 
// step 1. 아래의 함수는 치명적인 문제가 존재한다.
// 제수가 0일 경우, 미정의 동작이기 때문이다.
#include <stdio.h>

// C언어에서는 관례적으로 함수의 리턴에 종료 코드를 반환한다.
// 0 : 함수 호출이 성공한 경우(오류가 발생하지 않은 경우)
// 0 이외의 나머지 -> 일반적으로 -1을 사용 : 함수 호출이 실패한 경우(오류가 발생한 경우)
int div(int a, int b)
{
	if (b == 0)
		return -1;
	return a / b;
}

int main()
{
	// 함수가 호출된 이후에는 함수의 반환값을 확인해야 한다.
	int ret = div(4, 0);
	if (ret == -1)
	{
		fprintf(stderr, "divide by zero\n");
	}
	printf("%d\n", ret);
}
#endif



#if 0
// step 2. 이전의 코드에서는 함수의 리턴에 결과와 오류 코드가 혼재되어 있다는 문제가 있다.
// 이를 해결하기 위해 결과와 오류 코드를 분리한다.

// 해결 방법
// 1. 오류 코드를 함수의 반환으로 처리한다.
// 2. 연산 결과는 인자로 전달한다.
#include <stdio.h>
#define OUT
int div(int a, int b, OUT int* ret)
{
	// 실패한 경우
	if (b == 0 || ret == NULL)
		return -1;

	// 성공한 경우
	*ret = a / b;
	return a / b;
}

int main()
{
	// 함수가 호출된 이후에는 함수의 반환값을 확인해야 한다.
	int ret;
	if (div(4, 0, &ret) == -1)
	{
		fprintf(stderr, "divide by zero\n");
		return -1;
	}
	printf("%d\n", ret);
}
#endif



#if 1
// step 3. 이전의 코드는 함수가 오류 코드 또는 에러 정보를 반환하는지 알 수 없다는 단점이 있다.
// 이를 해결하기 위해 typedef를 사용한다.

typedef int error_t;
#include <stdio.h>
error_t div(int a, int b, int* ret)
{
	// 실패한 경우
	if (b == 0 || ret == NULL)
		return -1;

	// 성공한 경우
	*ret = a / b;
	return a / b;
}

int main()
{
	// 함수가 호출된 이후에는 함수의 반환값을 확인해야 한다.
	int ret;
	if (div(4, 0, &ret) == -1)
	{
		fprintf(stderr, "divide by zero\n");
		return -1;
	}
	printf("%d\n", ret);
}
#endif
 
// 결론 : 에러 코드를 반환하는 함수의 반환 타입을 인코딩하여 사용자에게 알려주는 것이 좋다.