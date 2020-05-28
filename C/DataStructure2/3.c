#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Array.h"

// 현재 자료구조는 내부 구조가 은닉되지 않아 코드가 올바르게 동작하지 않을 수 있다는 문제가 있다.
// 이를 해결하기 위해 구조체 멤버를 은폐하자
typedef struct {
	char name[32];
	int age;
} Person;

const char* toPerson(const void* data) {
	static char buf[32];
	const Person* person = (const Person*)data;
	sprintf(buf, "%s(%d)", person->name, person->age);
	return (const char*)buf;
}

int main() {
	Person people[5] = {
		{"daniel",20}, {"susan",30}, {"pororo", 40}, {"eddy", 50}, {"poby",60}
	};

	Array* arr = arrayCreate();
	arrayDisplay(arr, toPerson);
	for (int i = 0; i < 4; i++) {
		arrayAdd(arr, people + i);
		arrayDisplay(arr, toPerson);
	}

	arrayInsert(arr, 0, people + 4);
	arrayDisplay(arr, toPerson);

	arrayDestroy(arr);
}
