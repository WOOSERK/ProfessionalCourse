#if 1
// 파일의 크기를 계산하는 코드를 생각해 보자.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 문자 입출력 함수의 반환 값을 사용할 때는 int를 사용해야 한다.
// fgetc, getc, getchar

int main()
{
	FILE* fp = fopen("c:\\고급C\\a.c", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen");
		return -1;
	}

	size_t fsize = 0;
	int ch = fgetc(fp);
	// 1. 파일로부터 읽어온 바이트를 부호 없는 정수 타입의 바이트로 변환한다.
	// 0xFF -> unsigned char 
	
	// 2. 읽어온 바이트를 4바이트의 정수로 확장한다.
	// 0x000000FF => 255

	while (ch != EOF)
	{
		++fsize;
		ch = fgetc(fp);
	}

	printf("%u\n", fsize);
	return 0;
}
#endif


#if 0
#include <stdio.h>

int main()
{
	// 부호 없는 정수 타입이 확장될 경우, 확장 비트는 0으로 채워지게 된다.
	//unsigned char sc = 0xFF; // 1111 1111
	//signed int si = sc;		 // 
	//printf("%d\n", sc);
	
	// 부호 있는 정수 타입이 확장될 경우, 확장 비트는 1로 채워지게 된다.
	signed char sc = 0xFF;		// 1111 1111
	signed int si = sc;			// 
	printf("%d\n", sc);
}
#endif