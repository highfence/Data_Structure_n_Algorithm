/*
	�ۼ����� : 16.10.18
	�ۼ��� : 141060 �̱ٿ� (highfence@naver.com)
	���� : MaximumSubArray�� �� ���� ������� �����ϰ� �׽�Ʈ�غ���.
	Edited by MS Visual Studio 2015.
*/

#include "MaximumSubArray.h"



int main(void)
{
	while (1)
	{
		testInterface();
	}

	return 0;
}



/*
	printResult
	������� ���� ����ü idxAndSum�� �ּҰ��� �޾� ������ִ� �Լ�.
*/

void printResult(idxAndSum* input, int* arr, int size)
{
	if (!size) return;
	cout << "�Է� �迭 : { ";

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i != size - 1)
		{
			cout << ", ";
		}
	}
	cout << " } " <<endl;
	cout << "�����ε��� : " << input->startIdx << " �� �ε��� : " << input->endIdx << " ��� �� : " << input->sumVal << endl;
	return;
}


/*
	makeRandArray
	size�� �޾� �迭�� ����� �� �ȿ� ������ int���� �־��ִ� �Լ�.
*/

int* makeRandArray(int size)
{
	int* returnArr;
	int i;

	if (!size)
	{
		return NULL;
	}

	returnArr = new int[size];
	for (i = 0; i < size; ++i)
	{
		returnArr[i] = rand() % RAND_RANGE - RAND_MINUS_VAL;
	}

	return returnArr;
}


/*
	BruteWayFunc
		O(n^2)�� �ð����⵵�� ���� ���� �ذ� �Լ�.

		for (i = 0 to size)
			1. arr�� �� ������ ��´�.

			for (j = i to size)
			2. arr[j] ���� sumResult���� �����ش�.
			3. sumResult�� sumVal���� ���Ѵ�.

				if (sumResult > sumVal)
				4. sumVal�� sumResult ���� ����Ѵ�.
				5. i�� struct�� startIdx��, j�� struct�� endIdx�� �������ش�.
*/


idxAndSum* BruteWayFunc(int* arr, int size)
{
	int i, j;
	int sumResult = 0;
	idxAndSum* returnStruct;

	// Exception handling
	if (!arr) {
		cout << "There is a problem in input Array. \n";
		return NULL;
	}

	// Setting returnStruct and initializing.
	returnStruct = new idxAndSum;
	returnStruct->startIdx = 0;
	returnStruct->endIdx = 0;
	returnStruct->sumVal = INIT_MINUS_INFINIT;

	for (i = 0; i < size; ++i)
	{
		sumResult = 0;
		for (j = i; j < size; ++j)
		{
			sumResult += arr[j];
			if (sumResult > returnStruct->sumVal)
			{
				returnStruct->sumVal = sumResult;
				returnStruct->startIdx = i;
				returnStruct->endIdx = j;
			}
		}
	}

	return returnStruct;

}

/*
	testInterface
	�׽�Ʈ�� ���� �ϱ� ���Ͽ� �����ϴ� �Լ�.
*/

void testInterface(void)
{
	int size;
	int* arr;
	idxAndSum* result;

	cout << "���̰� �� �� �迭�� ����ϱ�? (exit for -1) : ";
	cin >> size;
	
	if (size == -1) {
		exit(1);
	}

	arr = makeRandArray(size);
	result = BruteWayFunc(arr, size);
	printResult(result, arr, size);
	cout << endl;

	delete result;
	delete[] arr;

	return;
}