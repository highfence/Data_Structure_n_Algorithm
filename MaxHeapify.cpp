/*
	작성일자 : 16.10.21
	작성자 : 141060 이근원
	내용 : MaxHeapify 함수와 그를 위한 부속함수의 구현.
	Edited By MS visual Studio 2015
*/

#include "MaxHeapify.h"



int main(void)
{
	Heap testHeap;

	while (testHeap.MakeSampleHeap() != -1)
	{
		cout << "초기 생성 배열";
		testHeap.PrintHeap();

		testHeap.BuildMaxHeap();
		cout << "Heap 변환후 ";
		testHeap.PrintHeap();
		cout << "MaxHeap이 맞나요? : ";
		if (testHeap.IsMaxHeap())
		{
			cout << "Yes!";
		}
		else
		{
			cout << "No!";
		}

		cout << endl;
	}

	return 0;
}


Heap::Heap()
{
	size = 0;
	element[0] = { FIRST_ARRAY_VAL };
}


/*
	PrintHeap
	Heap의 element를 1부터 size까지 돌면서 출력해주는 함수.
*/

void Heap::PrintHeap()
{
	cout << " 출력 : { ";
	for (int i = 1; i <= size; ++i)
	{
		cout << element[i];
		if (i != size)
		{
			printf(", ");
		}
	}
	cout << " }" << endl;
	return;
}


/*
	MakeSampleHeap
	사용자에게 size를 입력받아 랜덤하게 배열 원소를 집어넣어주는 함수.
	-1을 입력받을 시 프로그램을 종료한다.
*/

int Heap::MakeSampleHeap()
{
	int UserInputForSize;
	cout << "몇 개의 원소를 Heap에 넣으시겠습니까? (Exit for -1) : ";
	cin >> UserInputForSize;

	if (UserInputForSize == -1)
	{
		return -1;
	}

	for (int i = 1; i <= UserInputForSize; ++i)
	{
		element[i] = rand() % 100;
	}

	size = UserInputForSize;

	return 0;
}


/*
	BuildMaxHeap
	랜덤하게 배치되어있는 배열을 MaxHeapify함수를 이용하여 MaxHeap으로 바꾸어 주는 함수. O(N)

	1. 리프노드가 아닌 노드(Internal Node) 중 배열의 가장 뒤에 있는 노드를 찾는다. ( size / 2 의 인덱스 )
	2. 가장 뒤에 있는 노드부터 루트노드까지 돌며 MaxHeapify를 수행한다.
*/


void Heap::BuildMaxHeap()
{
	int lastInternalNode;

	lastInternalNode = size / 2;

	for (int i = lastInternalNode; i >= 1; --i)
	{
		MaxHeapify(i);
	}
	return;
}


/*
	MaxHeapify
	노드 번호를 받아 그 노드를 root로 하는 전체 tree를 Heap으로 변형시켜주는 함수.
	이를 위해 각 Subtree는 MaxHeap의 형태여야만 한다.

	1. 받은 노드의 rightChild와 leftChild가 있는지 확인하고 그 값을 구한다.
	1-1. root가 리프노드라면 함수를 종료한다.

	2. if, rightChild, leftChild 둘 중 하나가 root보다 크다면 그 값을 바꾼다.
		3.  바꾼 노드를 root로 하는 MaxHeapify를 다시 호출한다.

	4. root가 가장 크다면 함수를 종료한다.
*/

void Heap::MaxHeapify(int rootIdx)
{
	int leftChild = 0;
	int rightChild = 0;
	int largestIdx = 0;

	if (rootIdx < 1)
	{
		return;
	}

	// 1. rightChild와 leftChild가 있는지 확인.
	if (size >= rootIdx * 2)
	{
		leftChild = rootIdx * 2;

		if (element[leftChild] > element[rootIdx])
		{
			largestIdx = leftChild;
		}
		else
		{
			largestIdx = rootIdx;
		}
	}
	if (size >= rootIdx * 2 + 1)
	{
		rightChild = rootIdx * 2 + 1;

		if (element[rightChild] > element[largestIdx])
		{
			largestIdx = rightChild;
		}
	}

	// 리프노드라면 함수를 종료한다.
	if (!leftChild && !rightChild)
	{
		return;
	}

	// 만약 루트가 가장 크다면, 함수를 종료. (이미 MaxHeapify)
	if (largestIdx == rootIdx)
	{
		return;
	}
	// 루트가 가장 크지 않다면, 가장 값이 큰 Idx와 root의 값을 바꾼 뒤 바꾼 Idx로 재귀 호출.
	else
	{
		int tmp = element[largestIdx];
		element[largestIdx] = element[rootIdx];
		element[rootIdx] = tmp;
		MaxHeapify(largestIdx);
	}

	return;

}


/*
	IsMaxHeap
	element 배열을 돌며 힙이라면 1을, 아니라면 0을 반환하는 간단한 함수.
	인터널 노드의 끝 인덱스를 구한 뒤, 그 직전까지 leftChild, rightChild를 root와 비교하여 MaxHeap여부를 확인한다.
	인터널 노드의 끝은 rightChild가 있을지 없을지 알 수 없으므로 존재 여부를 확인한 뒤 비교한다.
*/

int Heap::IsMaxHeap()
{
	int endOfInternalNode = size / 2;
	int leftChild;
	int rightChild;

	// Exception Handling
	if (size <= 1)
	{
		return 1;
	}

	for (int i = 1; i < endOfInternalNode; ++i)
	{
		leftChild = i * 2;
		rightChild = i * 2 + 1;

		if (element[leftChild] > element[i])
		{
			return 0;
		}
		else if (element[rightChild] > element[i])
		{
			return 0;
		}
	}

	leftChild = endOfInternalNode * 2;
	
	if (element[leftChild] > element[endOfInternalNode])
	{
		return 0;
	}
	if (size >= endOfInternalNode * 2 + 1)
	{
		rightChild = endOfInternalNode * 2 + 1;
		if (element[rightChild] > element[endOfInternalNode])
		{
			return 0;
		}
	}

	return 1;
}


