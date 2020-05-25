
#include <stdlib.h>

int* arr;

void create()
{
	arr = calloc(10, sizeof(int));
}

void destroy()
{
	free(arr);
}