/*
	작성일자 : 16.10.28
	작성자 : 141060 이근원
	내용 : Stable Sort를 이용하여 Radix Sort 구현
	Edited by MS Visual Studio 2015
*/

#ifdef RadixSort

#include "RadixSort.h"

// TODO :: Counting Sort에서 소팅하면 transArr이 아니라 본체가 옮겨질 수 있도록하기.


int main(void)
{
	


	return 0;
}

/*
	MakeSampleArray
	사용자에게 size를 입력받아 랜덤하게 배열 원소를 집어넣어주는 함수.
	-1을 입력받을 시 프로그램을 종료하도록 바깥에서 제어해 줘야 한다.
*/

int Radix::MakeSampleArray()
{
	int UserInputForSize;
	cout << "몇 개의 원소를 Test Array에 넣으시겠습니까? (Exit for -1) : ";
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
	일의 자리 숫자부터 자리 수를 비교하여 소팅하는 함수.
	1. TransUnits
	2. 

*/


void Radix::RadixSort()
{

}


/*
	TransUnits
	arr 배열에 들어있는 값들의 1의 자리 숫자를 transArr에 넣어주는 함수.
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
	arr 배열에 들어있는 값들의 10의 자리 숫자를 transArr에 넣어주는 함수.
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
	arr 배열에 들어있는 값들의 100의 자리 숫자를 transArr에 넣어주는 함수.
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
// 카운팅 소트 재활용 함수들.

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