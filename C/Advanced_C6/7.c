
#include <stdio.h>
#define ARR_SIZE (6)

// 문자열을 위한 공간이 널 종료 문자를 담기에 충분함을 보장해야 한다.
int main()
{
	char src[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
		src[i] = 'A' + 1;

	char dst[ARR_SIZE];
	int i;
	for (i = 0; src[i] && i < sizeof(dst); i++); // 버퍼 오버플로 발생
		dst[i] = src[i];

	dst[i] = '\0';
	printf("%s\n", dst);

	return 0;
}