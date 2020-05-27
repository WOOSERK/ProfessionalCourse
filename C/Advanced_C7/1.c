
#include <stdio.h>

// fgets 함수 실패시, 인자로 전달된 버퍼는 알 수 없는 상태로 정의되므로 사용하면 안된다.
// 이 문제를 해결하려면 해당 버퍼를 널 문자열로 설정하면 된다.
int main()
{
	char buf[5];
	if (fgets(buf, sizeof(buf), stdin) == NULL)
	{
		//return -1;
		fprintf(stderr, "fgets error\n");
		*buf = '\0';
	}


}