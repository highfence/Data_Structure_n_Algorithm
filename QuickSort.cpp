/*
	�ۼ����� : 16.10.22
	�ۼ��� : 141060 �̱ٿ�
	���� : QuickSort�� �׿� �ʿ��� Partition �Լ��� ����
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
	�Է¹��� ������ ��ŭ ������ ���� ä���� �迭�� ����� ������ �Լ�.
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
	�迭�� ����ϴ� ������ �Լ�.
*/

void testArr::PrintArray()
{
	cout << "���� ���� " << size;
	cout << " �迭 ��� : { ";
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
	�迭�� �� ������ ���� ���� �ٲ��ִ� ������ �Լ�.
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
	Ŭ���� ���� ������ ���ڷ� �̷���� �迭�� �� ���� ���ڸ� �������� ū �ʰ� ���� ������ �и����ִ� �Լ�.

	1. �迭�� �� �� ���� pivot���� �����Ѵ�.
	2. 
*/

int testArr::Partition(int start, int end)
{

}