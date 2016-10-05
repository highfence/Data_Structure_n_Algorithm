/*
	작성일자 :  16.10.03
	작성자 : 141060 이근원
	내용 : Insertion Sort 함수를 구현한다.
	Edited by MS Visual Studio 2015.
*/

#include "InsertionSort.h"

int main(void)
{
	// case 1 : 한개의 원소일 때.
	int test1[1] = { 0 };

	// case 2 : 두개의 원소이고 정렬되어 있을 때.
	int test2[2] = { 0, 1 };

	// case 3 : 두개의 원소이고 정렬되어 있지 않을 때.
	int test3[2] = { 1, 0 };

	// case 4 : 적당히 많은 수의 원소이고 정렬되어 있을 때.
	int test4[10] = { 0,1,2,3,4,5,6,7,8,9 };

	// case 5 : 적당히 많은 수의 원소이고 완전히 역순일 때.
	int test5[10] = { 9,8,7,6,5,4,3,2,1,0 };

	// case 6 : 적당히 많은 수의 원소이고 적당히 정렬되어 있지 않을 때.
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
		cout << "이상한 배열이 들어왔네요." << endl;
		return;
	}

	// 배열의 두번째 숫자부터 시작하는 for루프.
	for (int idx = 1; idx < length; ++idx)
	{
		// 루프를 돌면서, 자신의 데이터를 저장하고, 자신의 앞의 배열을 subIdx로 놓는다.
		int subIdx = idx - 1;
		int presentIdxVal = arr[idx];

		// subIdx가 -1이 될때까지 도는 while루프.
		while (subIdx >= 0)
		{
			// 만약 내가 쥔 데이터가 내 앞의 데이터보다 크다면, break를 하고 그 배열 자리에 데이터를 집어넣는다. (Line 62)
			if (arr[subIdx] < presentIdxVal) break;

			// 그게 아니라면, 소팅이 되어있지 않은 것이므로 앞의 배열을 한 칸 뒤로 민다. 그리고 subIdx를 앞으로 한칸 밀어 또 확인한다. 
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
	cout << " * 입력받은 배열은 { ";
	
	for (int idx = 0; idx < length; ++idx)
	{
		cout << arr[idx] << " ";
	}

	cout << " } 입니다. 소팅을 시작합니다." << endl;

	InsertionSort(arr, length);

	if (IsSorted(arr, length)) {
		cout << "소팅은 성공적입니다. 결과 배열은 { ";
		for (int idx = 0; idx < length; ++idx)
		{
			cout << arr[idx] << " ";
		}

		cout << " } 입니다." << endl;
	}
	else {
		cout << "어라라? 뭔가 실패했네요? 결과 배열은 { ";
		for (int idx = 0; idx < length; ++idx)
		{
			cout << arr[idx] << " ";
		}

		cout << " } 입니다." << endl;
	
	}
	cout << endl;
	return;
}