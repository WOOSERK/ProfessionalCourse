#if 0
#include <stdio.h>

int main(void)
{
	//int i = 0;
	//int* p = &i; // 포인터(pointer to integer)

	//*p = 10; // OK, 대상체는 변수
	//p = 0; // OK, 포인터는 변수

	//int i = 0;
	//// 선언된 포인터에 대하여 변수명을 제거하면 대상체의 타입을 의미한다.

	//const int* p = &i; // 상수 지시 포인터(pointer to constant)
	////*p = 10; // ERROR, 대상체는 상수
	//p = 0; // OK, 포인터는 변수

	//int i = 0;
	//int* const p = &i; // 상수 포인터(constant pointer to)
	//*p = 10; // OK, 대상체는 변수
	//p = 0; // ERROR, 포인터는 상수

	//int i = 0;
	//int const* p = &i;
	//// *p = 10; // ERROR, 대상체는 상수
	//p = 0; // OK, 포인터는 변수

	//int i = 0;
	//const int* const p = &i; // 상수 지시 상수 포인터(constant pointer to constant)
	//*p = 0; // ERROR, 대상체도 상수
	//p = 0; // ERROR, 포인터도 상수
}
// 정리! 포인터 기호를 중심으로 *가 왼쪽에 있으면 대상체가 상수화, 오른쪽에 있으면 포인터가 상수화됩니다.

#endif

#if 0
#include <stdio.h>

int main(void)
{
	//int i = 0; int *pI = 0;
	//float f = 0; float *pF = 0;
	//double d = 0; double *pD = 0;

	// 포인터 변수에서 포인터 타입의 의미
	// 컴파일러에게 대상체의 크기(offset) 정보를 알려주기 위함
	//int x = 300;
	//char* p = &x;
	//printf("%d", *p);

	// 2바이트 이상의 변수를 선언합니다.
	unsigned int x = 1; // 0x00000001
	unsigned char* p = (unsigned char*)&x;
	if (*p == 1)
		printf("little endian\n");
	else
		printf("big endian\n");
}
#endif


#include <stdio.h>

int main(void)
{
	// 배열의 선언 : 타입 배열명[크기]
	int arr[3];

	// 배열명의 의미 : 첫 번째 원소의 시작 주소를 의미하는 상수 포인터
	// arr = 0; // ERROR
	printf("%d\n", arr);
	printf("%d\n", &arr);

	// 배열 포인터 선언
	int* p1 = arr;
	int(*p2)[3] = &arr;

	printf("sizeof(arr) = %u\n", sizeof(arr));

}