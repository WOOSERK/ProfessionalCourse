#if 1
// ������ ũ�⸦ ����ϴ� �ڵ带 ������ ����.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ����� �Լ��� ��ȯ ���� ����� ���� int�� ����ؾ� �Ѵ�.
// fgetc, getc, getchar

int main()
{
	FILE* fp = fopen("c:\\���C\\a.c", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "fopen");
		return -1;
	}

	size_t fsize = 0;
	int ch = fgetc(fp);
	// 1. ���Ϸκ��� �о�� ����Ʈ�� ��ȣ ���� ���� Ÿ���� ����Ʈ�� ��ȯ�Ѵ�.
	// 0xFF -> unsigned char 
	
	// 2. �о�� ����Ʈ�� 4����Ʈ�� ������ Ȯ���Ѵ�.
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
	// ��ȣ ���� ���� Ÿ���� Ȯ��� ���, Ȯ�� ��Ʈ�� 0���� ä������ �ȴ�.
	//unsigned char sc = 0xFF; // 1111 1111
	//signed int si = sc;		 // 
	//printf("%d\n", sc);
	
	// ��ȣ �ִ� ���� Ÿ���� Ȯ��� ���, Ȯ�� ��Ʈ�� 1�� ä������ �ȴ�.
	signed char sc = 0xFF;		// 1111 1111
	signed int si = sc;			// 
	printf("%d\n", sc);
}
#endif