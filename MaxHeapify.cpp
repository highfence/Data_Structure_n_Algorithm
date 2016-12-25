/*
	�ۼ����� : 16.10.21
	�ۼ��� : 141060 �̱ٿ�
	���� : MaxHeapify �Լ��� �׸� ���� �μ��Լ��� ����.
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
	Heap�� element�� 1���� size���� ���鼭 ������ִ� �Լ�.
*/

void Heap::PrintHeap()
{
	cout << " ��� : { ";
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
	����ڿ��� size�� �Է¹޾� �����ϰ� �迭 ���Ҹ� ����־��ִ� �Լ�.
	-1�� �Է¹��� �� ���α׷��� �����Ѵ�.
*/

int Heap::MakeSampleHeap()
{
	int UserInputForSize;
	cout << "�� ���� ���Ҹ� Heap�� �����ðڽ��ϱ�? (Exit for -1) : ";
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
	�����ϰ� ��ġ�Ǿ��ִ� �迭�� MaxHeapify�Լ��� �̿��Ͽ� MaxHeap���� �ٲپ� �ִ� �Լ�. O(N)

	1. ������尡 �ƴ� ���(Internal Node) �� �迭�� ���� �ڿ� �ִ� ��带 ã�´�. ( size / 2 �� �ε��� )
	2. ���� �ڿ� �ִ� ������ ��Ʈ������ ���� MaxHeapify�� �����Ѵ�.
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
	��� ��ȣ�� �޾� �� ��带 root�� �ϴ� ��ü tree�� Heap���� ���������ִ� �Լ�.
	�̸� ���� �� Subtree�� MaxHeap�� ���¿��߸� �Ѵ�.

	1. ���� ����� rightChild�� leftChild�� �ִ��� Ȯ���ϰ� �� ���� ���Ѵ�.
	1-1. root�� ��������� �Լ��� �����Ѵ�.

	2. if, rightChild, leftChild �� �� �ϳ��� root���� ũ�ٸ� �� ���� �ٲ۴�.
		3.  �ٲ� ��带 root�� �ϴ� MaxHeapify�� �ٽ� ȣ���Ѵ�.

	4. root�� ���� ũ�ٸ� �Լ��� �����Ѵ�.
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

	// 1. rightChild�� leftChild�� �ִ��� Ȯ��.
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

	// ��������� �Լ��� �����Ѵ�.
	if (!leftChild && !rightChild)
	{
		return;
	}

	// ���� ��Ʈ�� ���� ũ�ٸ�, �Լ��� ����. (�̹� MaxHeapify)
	if (largestIdx == rootIdx)
	{
		return;
	}
	// ��Ʈ�� ���� ũ�� �ʴٸ�, ���� ���� ū Idx�� root�� ���� �ٲ� �� �ٲ� Idx�� ��� ȣ��.
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
	element �迭�� ���� ���̶�� 1��, �ƴ϶�� 0�� ��ȯ�ϴ� ������ �Լ�.
	���ͳ� ����� �� �ε����� ���� ��, �� �������� leftChild, rightChild�� root�� ���Ͽ� MaxHeap���θ� Ȯ���Ѵ�.
	���ͳ� ����� �� ���� rightChild�� ������ ������ �� �� �����Ƿ� ���� ���θ� Ȯ���� �� ���Ѵ�.
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
	���� ������ ���� �Լ����� �׽�Ʈ �غ��� ���� ������ ��� ������ �������̽� �Լ�.
*/

void Heap::TestHeapify()
{
	while (this->MakeSampleHeap() != -1)
	{
		// �迭 �ʱ� ����
		cout << "�ʱ� ���� �迭";
		PrintHeap();

		// MaxHeap ��ȯ
		BuildMaxHeap();
		cout << "MaxHeap ��ȯ�� ";
		PrintHeap();
		cout << "MaxHeap�� �³���? : ";
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
		cout << endl << "Sorting �� ";
		PrintHeap();
		
		// ExtractMax
		MaxHeapify(1);
		int maxVal = ExtractMax();
		cout << "�ִ밪 :" << maxVal << endl;
		cout << "�ִ밪 ���� �� MaxHeap ";
		PrintHeap();

		// MaxHeapInsert
		cout << "���� �� ���� : ";
		MaxHeapInsert();
		PrintHeap();
		cout << endl << endl;
	}

	return;
}


/*
	HeapSort
	MaxHeap������ Heap�� �����ϴ� �Լ�.

	for (�迭�� �� ������ 2����)
		1. MaxHeap�� �ִ밪 (root���)�� �� �� ���� �ٲ��ش�.
		2. ��� ���� size�� ���� 1 ���� ��Ų��.
		3. �ִ밪�� ������ element���� Heapify�Ѵ�.
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
	MaxHeap���� �ִ밪�� ������ ��ȯ�Ѵ�. ��ȯ ���Ŀ��� �迭�� MaxHeap�� �����ؾ��Ѵ�.

	1. MaxHeap ���¿��� �ִ밪�� element[1]�̹Ƿ� �̸� �켱 ��ȯ ������ �����Ѵ�.
	2. �ִ밪�� element�� ������ ���ҿ� �ٲپ��ش�.
	3. ����� �ϳ� �ٿ� �ִ밪�� �迭���� ���ش�.
	4. �� ���� root��忡 ���Ͽ� MaxHeapify �Լ��� �����Ѵ�.
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
	element�� � ����� ���� ������Ű�� �Լ�. ������ ���� �ڿ��� MaxHeap�� �����Ǿ�� �Ѵ�.
	�Է����� �ε��� ���� key���� �޴´�.
	
	1. ���� �Է¹��� �ε��� ���� key�� ���� ũ�ٸ�, �Լ��� �����Ѵ�.
	2. �������� ���� ���Դٸ�, �ε��� ���� key���� �����Ѵ�.

	3. �ε����� parent�� ���Ѵ�.
	
	while (�ε����� MaxHeap�� ������)
		4. �ε����� parent�� ��ȯ�Ѵ�.
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

	// �ε����� �������� ���� �ٸ� �� Subtree�� �̹� MaxHeap���ǿ� �����ϹǷ�, parent�� ���� �ε��� ������ ũ�ٸ� MaxHeap���� ����.
	// Ȥ�� �ε��� ���� ���� �� ���� Ŀ�� root�� �Ǿ��� ��� ������ ����.
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
	�ϼ��Ǿ� �ִ� MaxHeap�� �ϳ��� ���� �߰���Ű�� �Լ�. ���� �߰��� �Ŀ��� MaxHeap�� �����Ǿ�� �Ѵ�.
	HeapIncreaseKey �Լ��� �̿��Ͽ� ����.  
	
	1. Heap�� Size�� �ϳ� ������Ų��.
	2. �� �ڸ��� INT_MIN���� ����ִ´�. (HeapIncreaseKey�� ������ �۵��ϰ� ��)
	3. �����ϰ��� �ϴ� ���� ������Ų �ε����� ����� HeapIncreaseKey�� ����ִ´�.
	( �׽�Ʈ�� ���Ǽ��� ���� �������� ����ִ´�. )
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
