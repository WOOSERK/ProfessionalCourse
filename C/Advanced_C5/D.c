
#include <stdio.h>

int main()
{
	double sum = 0.0f;
	
	// 99.999046
	for (int i = 0; i < 1000; i++)
		sum += 0.1L;

	printf("%f\n", sum);
}