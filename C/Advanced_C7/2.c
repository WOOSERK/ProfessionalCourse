
#include <stdio.h>

// 입출력 FILE 객체에 대하여 복사본을 사용하면 안된다.
int main()
{
	fputs("hello, world\n", stdout);

	FILE* fp = stdout; // 파일 포인터
	fputs("hello, world\n", fp);

	FILE file = *stdout;
	fputs("hello, world\n", &file);
}