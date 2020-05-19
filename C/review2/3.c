#if 0
#define _CRT_SECURE_NO_WARNINGS

// 사용자의 이름을 저장하는 코드
#include <stdio.h>

int main()
{
	char name[3][32];

	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name[i]);
	}

	for (int i = 0; i < 3; i++)
		printf("your name : %s\n", name[i]);
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS

// 이전 코드는 대용량의 자료구조를 스택에 생성한다는 단점이 있다.
// 이제 이 데이터를 힙에 생성한다.
// 이전 코드는 힙 메모리에 대하여 낭비가 발생한다.
// 이를 해결하기 위해 문자열 포인터를 사용
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char* names[3];
	char name[32];

	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name);
		names[i] = malloc(sizeof(char) * strlen(name) + 1);
		strcpy(names[i], name);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("your name : %s\n", names[i]);
		free(names[i]);
	}
}
#endif


#if 1
#define _CRT_SECURE_NO_WARNINGS

// 이전 코드는 배열의 몸체가 스택에 저장된다는 단점이 있다.
// 이를 해결하기 위해 포인터 배열을 힙에 생성한다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char** names;
	char name[32];

	names = malloc(sizeof(char*) * 3);
	
	for (int i = 0; i < 3; i++)
	{
		printf("input name : ");
		scanf("%s", name);
		names[i] = malloc(sizeof(char) * strlen(name) + 1);
		strcpy(names[i], name);
	}

	// 메모리의 해제는 반드시 생성의 역순으로 해줘야 한다.
	for (int i = 0; i < 3; i++)
	{
		printf("your name : %s\n", names[i]);
		free(names[i]);
	}

	free(names);
}
#endif