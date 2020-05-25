
#include <stdio.h>

// 포맷 문자열 사용시, 정확한 문자열을 사용해야 한다.
// 잘못된 포맷 문자열 사용시, 이는 미정의 동작이다.

int main()
{
	const char* msg = "not enough memory";
	int err_code = 3;

	//printf("Report : %d(%s)\n", msg, err_code);
	printf("Report : %s(%d)\n", msg, err_code);

}