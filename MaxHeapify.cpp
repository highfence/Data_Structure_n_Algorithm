/*
	�ۼ����� : 16.10.21
	�ۼ��� : 141060 �̱ٿ�
	���� : MaxHeapify �Լ��� �׸� ���� �μ��Լ��� ����.
	Edited By MS visual Studio 2015
*/

#include "MaxHeapify.h"



int main(void)
{
	Heap testHeap;

	while (testHeap.MakeSampleHeap() != -1)
	{
		cout << "�ʱ� ���� �迭";
		testHeap.PrintHeap();

		testHeap.BuildMaxHeap();
		cout << "Heap ��ȯ�� ";
		testHeap.PrintHeap();
		cout << "MaxHeap�� �³���? : ";
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
	���ͳ� ����� ���� rightChild�� ������ ������ �� �� �����Ƿ� ���� ���θ� Ȯ���� �� ���Ѵ�.
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


