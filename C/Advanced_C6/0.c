
#include <stdio.h>

// 배열의 크기를 얻을 때, 포인터를 sizeof의 피연산자로 사용하지 않는 것이 좋다.

void print_arr(int arr[], int len) // void print_arr(int *arr)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { 1,2,3,4,5 };

	for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		printf("%d ", arr[i]);
	
	// 배열에는 크기 정보가 없으므로 함수로 전달 시, 크기 정보를 같이 전달해야 한다.
	print_arr(arr, sizeof(arr)/sizeof(*arr)); // print_arr(0x12FF60);
}