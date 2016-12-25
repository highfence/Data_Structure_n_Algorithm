/*
	�ۼ����� : 16.10.28
	�ۼ��� : 141060 �̱ٿ�
	���� : Stable Sort�� �̿��Ͽ� Radix Sort ����
	Edited by MS Visual Studio 2015
*/

#ifdef RadixSort

#include "RadixSort.h"

// TODO :: Counting Sort���� �����ϸ� transArr�� �ƴ϶� ��ü�� �Ű��� �� �ֵ����ϱ�.


int main(void)
{
	


	return 0;
}

/*
	MakeSampleArray
	����ڿ��� size�� �Է¹޾� �����ϰ� �迭 ���Ҹ� ����־��ִ� �Լ�.
	-1�� �Է¹��� �� ���α׷��� �����ϵ��� �ٱ����� ������ ��� �Ѵ�.
*/

int Radix::MakeSampleArray()
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
		arr[i] = rand() % RANDOM_RANGE + BASIC_INT;
	}

	size = UserInputForSize;

	return 0;
}


/*
	RadixSort
	���� �ڸ� ���ں��� �ڸ� ���� ���Ͽ� �����ϴ� �Լ�.
	1. TransUnits
	2. 

*/


void Radix::RadixSort()
{

}


/*
	TransUnits
	arr �迭�� ����ִ� ������ 1�� �ڸ� ���ڸ� transArr�� �־��ִ� �Լ�.
*/

void Radix::TransUnits()
{
	int units;

	for (int i = 0; i < size; ++i)
	{
		units = arr[i] % 10;
		transArr[i] = units;
	}

	return;
}

/*
	TransTens
	arr �迭�� ����ִ� ������ 10�� �ڸ� ���ڸ� transArr�� �־��ִ� �Լ�.
*/

void Radix::TransTens()
{
	int tens;

	for (int i = 0; i < size; ++i)
	{
		tens = (arr[i] / 10) % 10;
		transArr[i] = tens;
	}

	return;
}


/*
	TransHundreds;
	arr �迭�� ����ִ� ������ 100�� �ڸ� ���ڸ� transArr�� �־��ִ� �Լ�.
*/

void Radix::TransHundreds()
{
	int hundreds;

	for (int i = 0; i < size; ++i)
	{
		hundreds = (arr[i] / 100);
		transArr[i] = hundreds;
	}

	return;
}





//////////////////////////////////////////////
// ī���� ��Ʈ ��Ȱ�� �Լ���.

void Radix::CountScore()
{
	for (int i = 0; i < DIGIT_RANGE; ++i)
	{
		score[i] = 0;
	}

	for (int j = 0; j < size; ++j)
	{
		score[transArr[j]] += 1;
	}

	return;
}



void Radix::AccumulateScore()
{
	for (int i = 1; i < DIGIT_RANGE; ++i)
	{
		score[i] += score[i - 1];
	}

	return;
}



void Radix::CountingSort()
{
	CountScore();
	AccumulateScore();

	int outputIdx;

	for (int i = size - 1; i >= 0; --i)
	{
		outputIdx = score[transArr[i]];
		outPut[outputIdx - 1] = transArr[i];
		--score[transArr[i]];
	}

	return;
}


#endif