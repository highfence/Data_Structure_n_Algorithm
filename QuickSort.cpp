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

	for (int i = 1; i <= 32; ++i)
	{

		test.MakeRandomArray(i);
		test.TestPartition(i);
	}

	test.MakeAscendingArr();
	test.TestPartition(MAKING_ELEMENT_COUNT);

	test.MakeDescendingArr();
	test.TestPartition(MAKING_ELEMENT_COUNT);

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
	2. pivot보다 작은 값들의 끝 인덱스를 나타낼 변수 endOfLowBlock을 만든다. (초기값은 start - 1)
	3. pivot보다 큰 값들 뒤의 인덱스를 나타낼 변수 posToBeChecked를 만든다. 이 변수를 이용하여 pivot과 비교대조를 시행한다.

	for (posToBeChecked가 start부터 end까지 1씩 증가)
		if (posToBeChecked가 pivot보다 값이 작다면)
			4. endOfLowBlock을 한 칸 증가시킨다.
			5. endOfLowBlock자리와 posToBeChecked를 Swap한다.
		else (값이 큰 경우에는 그대로 진행)

	6. 루프가 끝난 후, endOfLowBlock + 1은 pivot이 들어갈 자리이므로 서로 Swap해준다.
	7. 증가된 endOfLowBlock을 반환해준다. (pivot 반환)
*/

int testArr::Partition(int start, int end)
{
	int pivot = arr[end];
	int endOfLowBlock = start - 1;
	int posToBeChecked;

	for (posToBeChecked = start; posToBeChecked < end; ++posToBeChecked)
	{
		if (arr[posToBeChecked] < pivot)
		{
			Swap(++endOfLowBlock, posToBeChecked);
		}
	}

	Swap(++endOfLowBlock, end);
	return endOfLowBlock;
}

/*
	IsPartitionRight
	Partition 결과 나온 pivot인덱스 값을 받아 Partition이 제대로 되었는지 확인해보는 함수.
	제대로 되었다면 true을, 아니라면 false을 반환.
*/

bool testArr::IsPartitionRight(int pivotIdx)
{
	int pivotVal = arr[pivotIdx];

	// 작은 값 확인
	for (int i = pivotIdx - 1; i >= 0; --i)
	{
		if (arr[i] > pivotVal)
		{
			return false;
		}
	}

	// 큰 값 확인
	for (int i = pivotIdx + 1; i < size; ++i)
	{
		if (arr[i] < pivotVal)
		{
			return false;
		}
	}

	return true;
}

/*
	TestPartition
	파티션 기능을 테스트하기 위하여 만든 간단한 함수.
	QuickSort 기능도 여기서 테스트.
*/

void testArr::TestPartition(int elementVal)
{

	cout << "원소 개수 " << size;
	PrintArray();

	// 맨 뒤 원소를 기준으로 Partition
	int pivotIdx = Partition(0, size - 1);
	cout << "Pivot 값 : " << arr[pivotIdx] << endl;
	cout << "파티션 후 ";
	PrintArray();

	// IsPartitionRight?
	cout << "IsPartitionRight? : ";
	bool judgeVal = IsPartitionRight(pivotIdx);

	if (judgeVal)
	{
		cout << "Yes!" << endl;
	}
	else
	{
		cout << "No..." << endl;
	}

	cout << endl;

	return;
}


/*
	MakeAscendingArr / MakeDescendingArr
	테스트를 하기 위해 오름 차순 / 내림 차순 배열을 클래스 내의 배열에 할당하는 함수. 
*/


void testArr::MakeAscendingArr()
{
	int inputVal = 0;
	for (int i = 0; i < MAKING_ELEMENT_COUNT; ++i)
	{
		inputVal += rand() % RANDOM_PLUS_RANGE;
		arr[i] = inputVal;
	}

	size = MAKING_ELEMENT_COUNT;

	return;
}

void testArr::MakeDescendingArr()
{
	int inputVal = RANDOM_VAL_RANGE;
	for (int i = 0; i < MAKING_ELEMENT_COUNT; ++i)
	{
		inputVal -= rand() % RANDOM_PLUS_RANGE;
		arr[i] = inputVal;
	}

	size = MAKING_ELEMENT_COUNT;

	return;
}