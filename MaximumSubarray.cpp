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

void printResult(idxAndSum* input1, idxAndSum* input2, int* arr, int size)
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
	cout << "BruteWay : " << endl;
	cout << "�����ε��� : " << input1->startIdx << " �� �ε��� : " << input1->endIdx << " ��� �� : " << input1->sumVal << endl;

	cout << "FindMaximumSubarray : " << endl;
	cout << "�����ε��� : " << input2->startIdx << " �� �ε��� : " << input2->endIdx << " ��� �� : " << input2->sumVal << endl;

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

void copyArray(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; ++i) {
		arr2[i] = arr1[i];
	}
	return;
}


/*
	testInterface
	�׽�Ʈ�� ���� �ϱ� ���Ͽ� �����ϴ� �Լ�.
*/

void testInterface(void)
{
	int size;
	int* arr1;
	int* arr2;
	idxAndSum* result1;
	idxAndSum* result2 = new idxAndSum;

	cout << "���̰� �� �� �迭�� ����ϱ�? (exit for -1) : ";
	cin >> size;
	
	if (size == -1) {
		exit(1);
	}

	arr1 = makeRandArray(size);
	arr2 = new int[size];
	copyArray(arr1, arr2, size);

	result1 = BruteWayFunc(arr1, size);
	FindMaximumSum(arr2, 0, size - 1, &result2->startIdx, &result2->endIdx, &result2->sumVal);
	printResult(result1, result2, arr1, size);
	cout << endl;

	delete result1;
	delete result2;
	delete[] arr1;
	delete[] arr2;

	return;
}

/*
	FindMaxCrossingSubarray
	FindMaximumSum �Լ��� ����ϱ� ���� mid�� �����ϴ� �ִ밪�� ã�� �Լ�.
*/


void FindMaxCrossingSubarray(int* arr, int low, int mid, int high, int* resStart, int* resEnd, int* resSum)
{
	int leftSum = INIT_MINUS_INFINIT;
	int rightSum = INIT_MINUS_INFINIT;
	int sumVal = 0;
	int leftIdx, rightIdx;

	for (leftIdx = mid; leftIdx >= low; --leftIdx)
	{
		sumVal += arr[leftIdx];
		if (sumVal > leftSum)
		{
			leftSum = sumVal;
			*resStart = leftIdx;
		}
	}

	sumVal = 0;
	for (rightIdx = mid + 1; rightIdx <= high; ++rightIdx)
	{
		sumVal += arr[rightIdx];
		if (sumVal > rightSum)
		{
			rightSum = sumVal;
			*resEnd = rightIdx;
		}
	}

	*resSum = leftSum + rightSum;

	return;
}

void FindMaximumSum(int *arr, int low, int high, int* resStart, int* resEnd, int* resSum)
{
	int length = high - low;
	int mid = low + (high - low) / 2;
	int leftStart, leftEnd, leftSum;
	int rightStart, rightEnd, rightSum;
	int midStart, midEnd, midSum;


	if (!length)
	{
		*resStart = low;
		*resEnd = high;
		*resSum = arr[low];
		return;
	}

	FindMaximumSum(arr, low, mid, &leftStart, &leftEnd, &leftSum);
	FindMaximumSum(arr, mid + 1, high, &rightStart, &rightEnd, &rightSum);
	FindMaxCrossingSubarray(arr, low, mid, high, &midStart, &midEnd, &midSum);	

	if ((leftSum > rightSum) && (leftSum > midSum))
	{
		*resStart = leftStart;
		*resEnd = leftEnd;
		*resSum = leftSum;
	}
	else if ((rightSum > leftSum) && (rightSum > midSum))
	{
		*resStart = rightStart;
		*resEnd = rightEnd;
		*resSum = rightSum;
	}
	else
	{
		*resStart = midStart;
		*resEnd = midEnd;
		*resSum = midSum;
	}

	return;
}
