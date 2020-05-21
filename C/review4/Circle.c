#include "Circle.h"

static int square(int x)
{
	return x * x;
}

double getCircleArea(int r)
{
	return square(r) * 3.14;
}