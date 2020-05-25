
#if 0
// 2차원 배열 : 원소가 1차원 배열인 1차원 배열
// N차원 배열 : 원소가 N-1차원의 배열을 갖는 1차원 배열

#include <stdio.h>

int main(void)
{
	int arr1[3] = { 1,2,3 };
	int* pArr1 = arr1;

	int arr2[2][3] = { {1,2,3}, {4,5,6} };
	int (*pArr2)[3] = arr2;
}
#endif

#if 0
// 배열의 동적 할당
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 길이가 6이고 int 타입인 배열 생성
	// int arr[6]; // 스택에 생성
	// malloc(sizeof(int) * 6);
	
}
#endif


#if 0
// 포인터의 연산
#include <stdio.h>

int main()
{
	int *p = 0;
	int *q = 0;
	
	// 포인터와 포인터를 더할 수 없다.
	// p + q;
	// p - q;
	// p * q;
	// p / q;

	//p + 1; // 포인터 + 정수 = 포인터
	//p - 1; // 포인터 - 정수 = 포인터
	//p * 1; // 포인터 * 정수 = 불가능
	//p / 1; // 포인터 / 정수 = 불가능
}
#endif


#if 0
// 포인터와 산술 연산
#include <stdio.h>

int main()
{
	int i = 0;
	printf("%d\n", i + 1);

	// 포인터와 정수의 연산 결과는 대상체 크기의 배수만큼 계산된다.
	int* p = 0;
	printf("%d\n", p + 1); // p + sizeof((*p) * 1)
}
#endif


#if 0
#include <stdio.h>

int main()
{
	int arr[2][3] = { {1,2,3},{4,5,6} };
	int(*p)[3] = 0;
	printf("%d\n", arr);
	printf("%d\n", (arr+1)[2]);

}
#endif