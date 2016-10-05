/*
	�ۼ����� :  16.10.03
	�ۼ��� : 141060 �̱ٿ�
	���� : Insertion Sort �Լ��� �����Ѵ�.
	Edited by MS Visual Studio 2015.
*/

#include "InsertionSort.h"

int main(void)
{
	// case 1 : �Ѱ��� ������ ��.
	int test1[1] = { 0 };

	// case 2 : �ΰ��� �����̰� ���ĵǾ� ���� ��.
	int test2[2] = { 0, 1 };

	// case 3 : �ΰ��� �����̰� ���ĵǾ� ���� ���� ��.
	int test3[2] = { 1, 0 };

	// case 4 : ������ ���� ���� �����̰� ���ĵǾ� ���� ��.
	int test4[10] = { 0,1,2,3,4,5,6,7,8,9 };

	// case 5 : ������ ���� ���� �����̰� ������ ������ ��.
	int test5[10] = { 9,8,7,6,5,4,3,2,1,0 };

	// case 6 : ������ ���� ���� �����̰� ������ ���ĵǾ� ���� ���� ��.
	int test6[10] = { 2,6,8,3,4,7,1,5,9,0 };
	

	TestSorting(test1, sizeof(test1)/sizeof(test1[0]));
	TestSorting(test2, sizeof(test2)/sizeof(test2[0]));
	TestSorting(test3, sizeof(test3)/sizeof(test3[0]));
	TestSorting(test4, sizeof(test4)/sizeof(test4[0]));
	TestSorting(test5, sizeof(test5)/sizeof(test5[0]));
	TestSorting(test6, sizeof(test6)/sizeof(test6[0]));

	return 0;
}


void InsertionSort(int* arr, int length)
{
	if (!arr) {
		cout << "�̻��� �迭�� ���Գ׿�." << endl;
		return;
	}

	// �迭�� �ι�° ���ں��� �����ϴ� for����.
	for (int idx = 1; idx < length; ++idx)
	{
		// ������ ���鼭, �ڽ��� �����͸� �����ϰ�, �ڽ��� ���� �迭�� subIdx�� ���´�.
		int subIdx = idx - 1;
		int presentIdxVal = arr[idx];

		// subIdx�� -1�� �ɶ����� ���� while����.
		while (subIdx >= 0)
		{
			// ���� ���� �� �����Ͱ� �� ���� �����ͺ��� ũ�ٸ�, break�� �ϰ� �� �迭 �ڸ��� �����͸� ����ִ´�. (Line 62)
			if (arr[subIdx] < presentIdxVal) break;

			// �װ� �ƴ϶��, ������ �Ǿ����� ���� ���̹Ƿ� ���� �迭�� �� ĭ �ڷ� �δ�. �׸��� subIdx�� ������ ��ĭ �о� �� Ȯ���Ѵ�. 
			arr[subIdx + 1] = arr[subIdx];
			--subIdx;
		}
		
		arr[subIdx + 1] = presentIdxVal;

	}
	return;
}

bool IsSorted(int* arr, int length)
{
	for (int idx = 1; idx < length; ++idx)
	{
		if (arr[idx] < arr[idx - 1]) return false;
	}
	
	return true;
}

void TestSorting(int* arr, int length)
{
	cout << " * �Է¹��� �迭�� { ";
	
	for (int idx = 0; idx < length; ++idx)
	{
		cout << arr[idx] << " ";
	}

	cout << " } �Դϴ�. ������ �����մϴ�." << endl;

	InsertionSort(arr, length);

	if (IsSorted(arr, length)) {
		cout << "������ �������Դϴ�. ��� �迭�� { ";
		for (int idx = 0; idx < length; ++idx)
		{
			cout << arr[idx] << " ";
		}

		cout << " } �Դϴ�." << endl;
	}
	else {
		cout << "����? ���� �����߳׿�? ��� �迭�� { ";
		for (int idx = 0; idx < length; ++idx)
		{
			cout << arr[idx] << " ";
		}

		cout << " } �Դϴ�." << endl;
	
	}
	cout << endl;
	return;
}