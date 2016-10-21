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
	�����ϰ� ��ġ�Ǿ��ִ� �迭�� MaxHeapify�Լ��� �̿��Ͽ� MaxHeap���� �ٲپ� �ִ� �Լ�.

*/


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
	}
	if (size >= rootIdx * 2 + 1)
	{
		rightChild = rootIdx * 2 + 1;
	}

	// ��������� �Լ��� �����Ѵ�.
	if (!leftChild && !rightChild)
	{
		return;
	}

	// leftChild�� rightChild, root�� ��. 
	if (element[leftChild] > element[rootIdx])
	{
		largestIdx = leftChild;
	}
	else
	{
		largestIdx = rootIdx;
	}

	if (element[rightChild] > element[largestIdx])
	{
		largestIdx = rightChild;
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