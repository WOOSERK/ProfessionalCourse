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
	//�ؾ� �� �� : p=NULL�� ���� �ʾƵ� �޸𸮸� �� �� ���� �� ������ �ڵ带 ¥����. 

	// ���� �����ϴ� ���� �����ϴ�.
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
	
	// ���� �����ϴ� ���� �����ϴ�.
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
	// ���� �����ϴ� ���� �����ϴ�.
	SAFE_FREE(p);
}