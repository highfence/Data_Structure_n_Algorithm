/*
	작성일자 : 16.10.05
	작성자 : 141060 이근원 (highfence@naver.com)
	내용 : Merge Sort 함수를 구현한다.
	Edited By MS Visual Studio 2015.
*/


#include "mergeSort.h"

int main(void)
{
	// case1 : 원소가 없는 배열
	testSet case1;
	case1.test();

	// case2 : 원소가 1개 있는 배열
	int arr2[1] = { 0 };
	testSet case2(arr2, 1);
	case2.test();

	// case3 : 원소가 2개 있고, 정렬되어 있는 배열
	int arr3[2] = { 0,1 };
	testSet case3(arr3, 2);
	case3.test();

	// case4 : 원소가 2개 있고, 정렬되어 있지 않은 배열
	int arr4[2] = { 1, 0 };
	testSet case4(arr4, 2);
	case4.test();

	// case5 : 원소가 2개 있고, 중복 숫자가 들어있는 배열
	int arr5[2] = { 1, 1 };
	testSet case5(arr5, 2);
	case5.test();

	// case6 : 원소가 20개 있고, 정렬되어 있는 배열
	int arr6[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	testSet case6(arr6, 20);
	case6.test();

	// case7 : 원소가 20개 있고, 완전히 역순인 배열
	int arr7[20] = { 19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	testSet case7(arr7, 20);
	case7.test();

	// case8 : 원소가 20개 있고, 무작위인 배열
	int arr8[20] = { 9, 5, 1, 3, 2, 6, 7, 11, 15, 0, 20, -1, 10, 8, 16, 25, 4, 30, 50, 12 };
	testSet case8(arr8, 20);
	case8.test();

	// case9 : 원소가 20개 있고, 무작위 중복 숫자가 들어있는 배열
	int arr9[20] = { 9, 5, 1, 3, 2, 6, 7, 11, 15, 0, 20, 4, 7, 8, 16, 25, 4, 30, 50, 12 };
	testSet case9(arr9, 20);
	case9.test();

	return 0;
}


/*
	MergeSort

	if ( 마지막 인덱스가 begin보다 클 때 ) -> 재귀함수의 종료조건
		1. 배열을 나눌 중간 인덱스를 구한다.
		2. 앞의 배열에 대하여 재귀함수를 호출한다.
		3. 뒤의 배열에 대하여 재귀함수를 호출한다.
		4. 두 배열에 대하여 Merge함수를 호출한다.
*/

void MergeSort(int* arr, int* bufferArr, int begin, int last)
{
	if (last <= begin) return;
	int middle = begin + (last - begin) / 2;

	if (!arr) return;

	MergeSort(arr, bufferArr, begin, middle);
	MergeSort(arr, bufferArr, middle + 1, last);
	Merge(arr, bufferArr, begin, middle, last);

	return;
}


/*
	Merge

	1. 배열을 받아 두 개로 나눈다.
	2. 나눈 배열들을 버퍼에 복사한다. ( 이 때, 나눈 배열들은 각각 정렬된 상태 )
	3. 나눈 배열들의 첫 번째 배열을 각각 인덱스의 인자로 지정한다.
	
	while ( 원래 배열이 꽉 찰때 까지 )
		4. 어떤 인덱스가 배열의 끝을 가리키고 있다면, 다른 인덱스를 원래 배열에 채워넣는다.
		5. 끝을 가리키고 있지 않다면, 인덱스를 비교하여 작은 쪽을 배열에 채워넣는다.
		6. 채워넣은 쪽의 인덱스를 1 증가한다.
*/

void Merge(int* inputArr, int* bufferArr, int firstBegin, int firstLast, int secondLast)
{
	int mainIdx;
	int idx1;
	int idx2;

	CopyBlock(inputArr, bufferArr, firstBegin, secondLast + 1);
	
	idx1 = firstBegin;
	idx2 = firstLast + 1;

	for (mainIdx = firstBegin; mainIdx <= secondLast; ++mainIdx)
	{
		if (idx1 > firstLast) inputArr[mainIdx] = bufferArr[idx2++];
		else if (idx2 > secondLast) inputArr[mainIdx] = bufferArr[idx1++];

		else if (bufferArr[idx1] < bufferArr[idx2]) inputArr[mainIdx] = bufferArr[idx1++];
		else inputArr[mainIdx] = bufferArr[idx2++];
	}

	return;
}


/*
	CopyBlock
	원래 배열의 시작에서 끝까지의 배열을 버퍼에 복사한다.
*/

void CopyBlock(int* arr, int* bufferArr, int beginIdx, int endIdx)
{
	for (int idx = beginIdx; idx < endIdx; ++idx)
	{
		bufferArr[idx] = arr[idx];
	}

	return;
}


/*
	IsSorted
	정렬이 잘 되어있는지 확인해주는 함수.
*/

bool IsSorted(int* arr, int length)
{
	if (length == 0) return false;

	for (int idx = 1; idx < length; ++idx)
	{
		if (arr[idx] < arr[idx - 1]) return false;
	}

	return true;
}

/*
	testSet
	테스트를 편하게 하기 위한 클래스.
*/

testSet::testSet() : m_array(NULL), m_buffer(NULL), m_length(0)
{}

testSet::testSet(int* arr, int length)
{
	m_array = new int[length];
	m_buffer = new int[length];
	
	for (int i = 0; i < length; ++i) 
	{
		m_array[i] = arr[i];
	}
	this->m_length = &length;
}

testSet::~testSet()
{
	if (!m_array) return;
	delete[] m_array;
	delete[] m_buffer;
}

void testSet::printArray()
{
	cout << " { ";

	for (int i = 0; i < *m_length; ++i)
	{
		cout << m_array[i];
		if (i + 1 != *m_length) cout << ", ";
	}

	cout << " } ";
}

void testSet::test()
{
	if (!m_array)
	{
		cout << "입력받은 배열에 원소가 없습니다." << endl;
		cout << "정렬을 종료합니다 :)" << endl << endl;
		return;
	}

	cout << "입력받은 배열은";
	printArray();
	cout << "입니다. 머지 소팅을 진행합니다." << endl;

	MergeSort(m_array, m_buffer, 0, *m_length - 1);

	if (IsSorted(m_array, *m_length))
	{
		cout << "소팅은 성공적입니다. 결과 배열은";
		printArray();
		cout << "입니다." << endl;
	}
	else
	{
		cout << "소팅이 실패했습니다. 결과 배열은";
		printArray();
		cout << "입니다." << endl;
	}

	cout << endl;
	return;
}
