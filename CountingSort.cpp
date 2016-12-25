/*
	작성일자 : 16.10.27
	작성자 : 141060 이근원
	내용 : Counting Sort 구현
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
	Test Class 초기화.
	사이즈가 처음에는 -1을 가지고 있다.
*/
Test::Test() : size(-1) {}



/*
	MakeSampleArray
	사용자에게 size를 입력받아 랜덤하게 배열 원소를 집어넣어주는 함수.
	-1을 입력받을 시 프로그램을 종료하도록 바깥에서 제어해 줘야 한다.
*/

int Test::MakeSampleArray()
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
		arr[i] = rand() % RANDOM_RANGE;
	}

	size = UserInputForSize;

	return 0;
}



/*
	CountScore
	Counting Sort를 위하여 구현하는 함수.
		1. 점수 배열 score를 0으로 초기화 한다.
		2. 클래스 안의 입력받은 배열 arr를 처음부터 끝까지 돌며 해당하는 점수 인덱스의 score 배열을 증가시켜주는 함수. 
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
	Counting Sort를 위하여 구현하는 함수.

		점수 배열 score를 1부터 RANDOM_RANGE까지 돌며 자신보다 한 칸 앞 인덱스를 자신에게 더한다. 
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
	
	for (배열의 맨 끝부터 처음까지.)
		3. arr를 스캔한다.
		4. 스캔한 값을 score의 인덱스로 넣어 원소가 들어갈 자리를 찾는다.
		5. 출력 배열 outputArr에 스캔한 값을 넣어준다.
		6. 해당 score 인덱스를 1 줄여준다. 
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
	테스트 이후 배열을 확인하기 위해 구현하는 간단한 함수.
	arr, outputArr, size를 출력한다.
*/

void Test::PrintAll()
{
	cout << "입력하신 원소 개수 : " << size << endl;
	cout << "랜덤으로 생성된 배열 : { ";

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i != size - 1 )
		{
			cout << ", ";
		}
	}

	cout << " }" << endl;

	cout << "CountSorting 후 배열 : { ";

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