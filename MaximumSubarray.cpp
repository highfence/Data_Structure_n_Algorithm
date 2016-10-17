/*
	�ۼ����� : 16.10.18
	�ۼ��� : 141060 �̱ٿ� (highfence@naver.com)
	���� : MaximumSubArray�� �� ���� ������� �����ϰ� �׽�Ʈ�غ���.
	Edited by MS Visual Studio 2015.
*/

#include "MaximumSubArray.h"




int main(void)
{


	return 0;
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
		return;
	}

	// Setting returnStruct and initializing.
	returnStruct = (idxAndSum*)malloc(sizeof(idxAndSum));
	returnStruct->startIdx = 0;
	returnStruct->endIdx = 0;
	returnStruct->sumVal = 0;

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