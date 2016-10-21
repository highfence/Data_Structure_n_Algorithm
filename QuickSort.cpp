/*
	작성일자 : 16.10.22
	작성자 : 141060 이근원
	내용 : QuickSort와 그에 필요한 Partition 함수의 구현
	Edited by MS visual Studio 2015
*/

#include "QuickSort.h"

int main(void)
{
	testArr test;

	for (int i = 1; i <= REPEAT_COUNT; ++i)
	{
		test.MakeRandomArray(i);
		test.PrintArray();
	}


	return 0;
}

testArr::testArr() : size(0) {}

/*
	MakeRandomArray
	입력받은 사이즈 만큼 랜덤한 수로 채워진 배열을 만드는 간단한 함수.
*/

int testArr::MakeRandomArray(int size)
{
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % RANDOM_VAL_RANGE;
	}

	return 0;
}


/*
	PrintArray
	배열을 출력하는 간단한 함수.
*/

void testArr::PrintArray()
{
	cout << "원소 개수 " << size;
	cout << " 배열 출력 : { ";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	cout << " }" << endl;
	return;

}

/*
	Swap
	배열의 두 원소의 값을 서로 바꿔주는 간단한 함수.
*/

void testArr::Swap(int idx1, int idx2)
{
	if ((idx1 >= size) || (idx2 >= size))
	{
		return;
	}

	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;

	return;
}


/*
	Partition
	클래스 안의 랜덤한 숫자로 이루어진 배열을 맨 뒤의 숫자를 기준으로 큰 쪽과 작은 쪽으로 분리해주는 함수.

	1. 배열의 맨 뒤 값을 pivot으로 설정한다.
	2. 
*/

int testArr::Partition(int start, int end)
{

}