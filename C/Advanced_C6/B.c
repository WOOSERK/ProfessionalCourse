#if 0
#include <stdio.h>
#include <stdlib.h>
#define ARR_SZ (10)

void Free(void** p)
{
	if (p == NULL)
		return;

	free(*p);
	*p = NULL;
}

int main()
{
	int* p = malloc(sizeof(int) * ARR_SZ);
	if (p == NULL)
	{
		fprintf(stderr, "malloc error\n");
		return -1;
	}

	free(p);
	//해야 할 것 : p=NULL을 하지 않아도 메모리를 두 번 해제 시 안전한 코드를 짜보자. 

	// 널을 해제하는 것은 안전하다.
	free(p);
}
#endif



#if 0
#include <stdio.h>
#include <stdlib.h>
#define ARR_SZ (10)

void Free(void** p)
{
	if (p == NULL)
		return;

	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

int main()
{
	int* p = malloc(sizeof(int) * ARR_SZ);
	if (p == NULL)
	{
		fprintf(stderr, "malloc error\n");
		return -1;
	}

	Free(&p);
	
	// 널을 해제하는 것은 안전하다.
	Free(&p);
}
#endif


#include <stdio.h>
#include <stdlib.h>
#define ARR_SZ (10)
#define SAFE_FREE(p)			\
	do							\
	{							\
		if((p))					\
		{						\
			free((p));			\
			(p) = NULL;			\
		}						\
	} while(0)

int main()
{
	int* p = malloc(sizeof(int) * ARR_SZ);
	if (p == NULL)
	{
		fprintf(stderr, "malloc error\n");
		return -1;
	}

	SAFE_FREE(p);
	// 널을 해제하는 것은 안전하다.
	SAFE_FREE(p);
}