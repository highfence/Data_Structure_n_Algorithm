/*
	�ۼ����� : 16.10.27
	�ۼ��� : 141060 �̱ٿ�
	���� : Counting Sort ����
	Edited By MS Visual Studio 2015
*/

#ifdef CountingSort

#include "CountingSort.h"


int main(void)
{
	Test test;

	while (test.MakeSampleArray() != -1)
	{
		test.CountingSort();
		test.PrintAll();
	}


	return 0;
}



/*
	Test Class �ʱ�ȭ.
	����� ó������ -1�� ������ �ִ�.
*/
Test::Test() : size(-1) {}



/*
	MakeSampleArray
	����ڿ��� size�� �Է¹޾� �����ϰ� �迭 ���Ҹ� ����־��ִ� �Լ�.
	-1�� �Է¹��� �� ���α׷��� �����ϵ��� �ٱ����� ������ ��� �Ѵ�.
*/

int Test::MakeSampleArray()
{
	int UserInputForSize;
	cout << "�� ���� ���Ҹ� Test Array�� �����ðڽ��ϱ�? (Exit for -1) : ";
	cin >> UserInputForSize;

	if (UserInputForSize == -1)
	{
		return -1;
	}

	for (int i = 0; i < UserInputForSize; ++i)
	{
		arr[i] = rand() % RANDOM_RANGE;
	}

	size = UserInputForSize;

	return 0;
}



/*
	CountScore
	Counting Sort�� ���Ͽ� �����ϴ� �Լ�.
		1. ���� �迭 score�� 0���� �ʱ�ȭ �Ѵ�.
		2. Ŭ���� ���� �Է¹��� �迭 arr�� ó������ ������ ���� �ش��ϴ� ���� �ε����� score �迭�� ���������ִ� �Լ�. 
*/

void Test::CountScore()
{
	for (int i = 0; i < RANDOM_RANGE + 1; ++i)
	{
		score[i] = 0;
	}

	for (int j = 0; j < size; ++j)
	{
		score[arr[j]] += 1;
	}

	return;
}


/*
	AccumulateScore
	Counting Sort�� ���Ͽ� �����ϴ� �Լ�.

		���� �迭 score�� 1���� RANDOM_RANGE���� ���� �ڽź��� �� ĭ �� �ε����� �ڽſ��� ���Ѵ�. 
*/


void Test::AccumulateScore()
{
	for (int i = 1; i < RANDOM_RANGE + 1; ++i)
	{
		score[i] += score[i - 1];
	}

	return;
}



/*
	Counting Sort
	1. CountScore.
	2. AccumulateScore.
	
	for (�迭�� �� ������ ó������.)
		3. arr�� ��ĵ�Ѵ�.
		4. ��ĵ�� ���� score�� �ε����� �־� ���Ұ� �� �ڸ��� ã�´�.
		5. ��� �迭 outputArr�� ��ĵ�� ���� �־��ش�.
		6. �ش� score �ε����� 1 �ٿ��ش�. 
*/

void Test::CountingSort()
{
	CountScore();
	AccumulateScore();

	int outputIdx;

	for (int i = size - 1; i >= 0; --i)
	{
		outputIdx = score[arr[i]];
		outputArr[outputIdx - 1] = arr[i];
		--score[arr[i]];
	}

	return;
}


/*
	PrintAll
	�׽�Ʈ ���� �迭�� Ȯ���ϱ� ���� �����ϴ� ������ �Լ�.
	arr, outputArr, size�� ����Ѵ�.
*/

void Test::PrintAll()
{
	cout << "�Է��Ͻ� ���� ���� : " << size << endl;
	cout << "�������� ������ �迭 : { ";

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i != size - 1 )
		{
			cout << ", ";
		}
	}

	cout << " }" << endl;

	cout << "CountSorting �� �迭 : { ";

	for (int j = 0; j < size; ++j)
	{
		cout << outputArr[j];
		if (j != size - 1)
		{
			cout << ", ";
		}
	}

	cout << " }" << endl << endl;

	return;
}

#endif