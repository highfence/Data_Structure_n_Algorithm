/*
	작성일자 : 16.10.21
	작성자 : 141060 이근원
	내용 : MaxHeapify 함수와 그를 위한 부속함수의 구현.
	Edited By MS visual Studio 2015
*/

#ifdef MaxHeapify

#include "MaxHeapify.h"



int main(void)
{
	Heap testHeap;
	testHeap.TestHeapify();

	return 0;
}


Heap::Heap()
{
	size = 0;
	element[0] = { INIT_MIN_VAL };
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
	인터널 노드의 끝 노드는 rightChild가 있을지 없을지 알 수 없으므로 존재 여부를 확인한 뒤 비교한다.
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


/*
	TestHeapify
	힙과 관련한 여러 함수들을 테스트 해보기 위해 구조를 잡는 일종의 인터페이스 함수.
*/

void Heap::TestHeapify()
{
	while (this->MakeSampleHeap() != -1)
	{
		// 배열 초기 생성
		cout << "초기 생성 배열";
		PrintHeap();

		// MaxHeap 변환
		BuildMaxHeap();
		cout << "MaxHeap 변환후 ";
		PrintHeap();
		cout << "MaxHeap이 맞나요? : ";
		if (IsMaxHeap())
		{
			cout << "Yes!";
		}
		else
		{
			cout << "No!";
		}

		// HeapSort
		HeapSort();
		cout << endl << "Sorting 후 ";
		PrintHeap();
		
		// ExtractMax
		MaxHeapify(1);
		int maxVal = ExtractMax();
		cout << "최대값 :" << maxVal << endl;
		cout << "최대값 제거 후 MaxHeap ";
		PrintHeap();

		// MaxHeapInsert
		cout << "랜덤 값 삽입 : ";
		MaxHeapInsert();
		PrintHeap();
		cout << endl << endl;
	}

	return;
}


/*
	HeapSort
	MaxHeap상태의 Heap을 소팅하는 함수.

	for (배열의 맨 끝부터 2까지)
		1. MaxHeap의 최대값 (root노드)를 맨 뒤 노드와 바꿔준다.
		2. 멤버 변수 size의 값을 1 감소 시킨다.
		3. 최대값을 제외한 element들을 Heapify한다.
*/

void Heap::HeapSort()
{
	int preserveSize = size;
	int tmp;

	for (int i = preserveSize; i >= 2; --i)
	{
		tmp = element[1];
		element[1] = element[i];
		element[i] = tmp;
		--size;
		MaxHeapify(1);
	}

	size = preserveSize;
	return;
}

/*
	ExtractMax
	MaxHeap에서 최대값을 빼내어 반환한다. 반환 이후에도 배열은 MaxHeap을 유지해야한다.

	1. MaxHeap 상태에서 최대값은 element[1]이므로 이를 우선 반환 값으로 저장한다.
	2. 최대값을 element의 마지막 원소와 바꾸어준다.
	3. 사이즈를 하나 줄여 최대값을 배열에서 없앤다.
	4. 그 이후 root노드에 대하여 MaxHeapify 함수를 실행한다.
*/

int Heap::ExtractMax()
{
	if (!size)
	{
		return 0;
	}

	int returnVal = element[1];
	
	element[1] = element[size];
	element[size--] = returnVal;

	MaxHeapify(1);

	return returnVal;
}

/*
	HeapIncreaseKey
	element의 어떤 노드의 값을 증가시키는 함수. 증가가 끝난 뒤에도 MaxHeap이 유지되어야 한다.
	입력으로 인덱스 값과 key값을 받는다.
	
	1. 만약 입력받은 인덱스 값이 key값 보다 크다면, 함수를 종료한다.
	2. 정상적인 값이 들어왔다면, 인덱스 값에 key값을 저장한다.

	3. 인덱스의 parent를 구한다.
	
	while (인덱스가 MaxHeap일 때까지)
		4. 인덱스와 parent를 교환한다.
*/

void Heap::HeapIncreaseKey(int idx, int key)
{
	// Exception Handling
	if (element[idx] > key)
	{
		return;
	}

	element[idx] = key;
	int parent = idx / 2;
	int currentIdx = idx;

	// 인덱스를 포함하지 않은 다른 한 Subtree는 이미 MaxHeap조건에 부합하므로, parent의 값이 인덱스 값보다 크다면 MaxHeap조건 만족.
	// 혹은 인덱스 값이 원소 중 가장 커서 root가 되었을 경우 조건을 만족.
	while ((currentIdx > 1) && (element[parent] < element[currentIdx]))
	{
		int tmp = element[currentIdx];
		element[currentIdx] = element[parent];
		element[parent] = tmp;
		
		currentIdx = parent;
		parent /= 2;
	}

	return;
}


/*
	MaxHeapInsert
	완성되어 있는 MaxHeap에 하나의 값을 추가시키는 함수. 값이 추가된 후에도 MaxHeap은 유지되어야 한다.
	HeapIncreaseKey 함수를 이용하여 구현.  
	
	1. Heap의 Size를 하나 증가시킨다.
	2. 그 자리에 INT_MIN값을 집어넣는다. (HeapIncreaseKey가 무조건 작동하게 함)
	3. 삽입하고자 하는 값과 증가시킨 인덱스의 사이즈를 HeapIncreaseKey에 집어넣는다.
	( 테스트의 편의성을 위해 랜덤값을 집어넣는다. )
*/

void Heap::MaxHeapInsert()
{

	element[++size] = INIT_MIN_VAL;
	int inputVal = rand() % RANDOM_VAL_RANGE;

	cout << inputVal;
	HeapIncreaseKey(size, inputVal);

	return;
}


#endif
