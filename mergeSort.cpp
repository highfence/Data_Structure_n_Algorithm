/*
	�ۼ����� : 16.10.05
	�ۼ��� : 141060 �̱ٿ� (highfence@naver.com)
	���� : Merge Sort �Լ��� �����Ѵ�.
	Edited By MS Visual Studio 2015.
*/


#include "mergeSort.h"

int main(void)
{
	// case1 : ���Ұ� ���� �迭
	testSet case1;
	case1.test();

	// case2 : ���Ұ� 1�� �ִ� �迭
	int arr2[1] = { 0 };
	testSet case2(arr2, 1);
	case2.test();

	// case3 : ���Ұ� 2�� �ְ�, ���ĵǾ� �ִ� �迭
	int arr3[2] = { 0,1 };
	testSet case3(arr3, 2);
	case3.test();

	// case4 : ���Ұ� 2�� �ְ�, ���ĵǾ� ���� ���� �迭
	int arr4[2] = { 1, 0 };
	testSet case4(arr4, 2);
	case4.test();

	// case5 : ���Ұ� 2�� �ְ�, �ߺ� ���ڰ� ����ִ� �迭
	int arr5[2] = { 1, 1 };
	testSet case5(arr5, 2);
	case5.test();

	// case6 : ���Ұ� 20�� �ְ�, ���ĵǾ� �ִ� �迭
	int arr6[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	testSet case6(arr6, 20);
	case6.test();

	// case7 : ���Ұ� 20�� �ְ�, ������ ������ �迭
	int arr7[20] = { 19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	testSet case7(arr7, 20);
	case7.test();

	// case8 : ���Ұ� 20�� �ְ�, �������� �迭
	int arr8[20] = { 9, 5, 1, 3, 2, 6, 7, 11, 15, 0, 20, -1, 10, 8, 16, 25, 4, 30, 50, 12 };
	testSet case8(arr8, 20);
	case8.test();

	// case9 : ���Ұ� 20�� �ְ�, ������ �ߺ� ���ڰ� ����ִ� �迭
	int arr9[20] = { 9, 5, 1, 3, 2, 6, 7, 11, 15, 0, 20, 4, 7, 8, 16, 25, 4, 30, 50, 12 };
	testSet case9(arr9, 20);
	case9.test();

	return 0;
}


/*
	MergeSort

	if ( ������ �ε����� begin���� Ŭ �� ) -> ����Լ��� ��������
		1. �迭�� ���� �߰� �ε����� ���Ѵ�.
		2. ���� �迭�� ���Ͽ� ����Լ��� ȣ���Ѵ�.
		3. ���� �迭�� ���Ͽ� ����Լ��� ȣ���Ѵ�.
		4. �� �迭�� ���Ͽ� Merge�Լ��� ȣ���Ѵ�.
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

	1. �迭�� �޾� �� ���� ������.
	2. ���� �迭���� ���ۿ� �����Ѵ�. ( �� ��, ���� �迭���� ���� ���ĵ� ���� )
	3. ���� �迭���� ù ��° �迭�� ���� �ε����� ���ڷ� �����Ѵ�.
	
	while ( ���� �迭�� �� ���� ���� )
		4. � �ε����� �迭�� ���� ����Ű�� �ִٸ�, �ٸ� �ε����� ���� �迭�� ä���ִ´�.
		5. ���� ����Ű�� ���� �ʴٸ�, �ε����� ���Ͽ� ���� ���� �迭�� ä���ִ´�.
		6. ä������ ���� �ε����� 1 �����Ѵ�.
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
	���� �迭�� ���ۿ��� �������� �迭�� ���ۿ� �����Ѵ�.
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
	������ �� �Ǿ��ִ��� Ȯ�����ִ� �Լ�.
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
	�׽�Ʈ�� ���ϰ� �ϱ� ���� Ŭ����.
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
		cout << "�Է¹��� �迭�� ���Ұ� �����ϴ�." << endl;
		cout << "������ �����մϴ� :)" << endl << endl;
		return;
	}

	cout << "�Է¹��� �迭��";
	printArray();
	cout << "�Դϴ�. ���� ������ �����մϴ�." << endl;

	MergeSort(m_array, m_buffer, 0, *m_length - 1);

	if (IsSorted(m_array, *m_length))
	{
		cout << "������ �������Դϴ�. ��� �迭��";
		printArray();
		cout << "�Դϴ�." << endl;
	}
	else
	{
		cout << "������ �����߽��ϴ�. ��� �迭��";
		printArray();
		cout << "�Դϴ�." << endl;
	}

	cout << endl;
	return;
}
