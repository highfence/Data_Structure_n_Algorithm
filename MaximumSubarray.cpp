/*
	작성일자 : 16.10.18
	작성자 : 141060 이근원 (highfence@naver.com)
	내용 : MaximumSubArray를 두 가지 방법으로 구현하고 테스트해보기.
	Edited by MS Visual Studio 2015.
*/

#include "MaximumSubArray.h"




int main(void)
{


	return 0;
}


/*
	BruteWayFunc
		O(n^2)의 시간복잡도를 가진 문제 해결 함수.

		for (i = 0 to size)
			1. arr의 한 지점을 잡는다.

			for (j = i to size)
			2. arr[j] 값을 sumResult값에 더해준다.
			3. sumResult와 sumVal값을 비교한다.

				if (sumResult > sumVal)
				4. sumVal에 sumResult 값을 기록한다.
				5. i를 struct의 startIdx로, j를 struct의 endIdx로 갱신해준다.
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