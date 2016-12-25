/*
	Red-BlackTree
	�ۼ��� : 141060 �̱ٿ�
	�����ۼ����� : 16.12.06
	�ֱټ������� : 16.12.08
	���� : Red-Black Tree�� �׿� �ʿ��� ���� �Լ��� ����.

		1. Red-Black Tree �⺻ ���� ����.
		2. Right/Left Rotate ����.
		3. InsertNode ����.
*/

#define Red_BlackTree

#ifdef Red_BlackTree

#include "Red-BlackTree.h"

/*
	RightRotate / LeftRotate
	���� � ����� �����͸� �޾Ƽ� Rotate�����ִ� �Լ�.
	
		�Է³�尡 ���ٸ� ������ INVALID_INPUT�� ��ȯ.
		���� �Է³���� leftChild / RightChild�� ���ų�, ������ ���������� ����Ǹ� PERFORM_WELL�� ��ȯ.

		RightRotate
		1. �Է� ��尡 ���ٸ�, ������ ��ȯ.
		2. LeftChild�� �������� �ʴ´ٸ�, �Լ��� ������ ����. (PERFORM_WELL)
		3. LeftChild�� yNode�� ���.
		4. yNode�� parent�� xNode�� parent�� ���� ��, xNode�� parent�� yNode�� ����.
		5. yNode�� rightChild�� �����Ѵٸ�, xNode�� leftChild�� ����.
		6. yNode�� rightChild�� xNode�� ����.
		7. xNode�� ���� parent���̿� ���� yNode�� ���� parent������ ���踦 ����.
		end.
		
		LeftRotate
		1. RightRotate�� ����� x / y ��带 �ݴ�� ����.
*/


STATE RedBlackTree::RightRotate(node_t* xNode)
{
	if (!xNode) return ERROR_INVALID_INPUT;
	if (!xNode->leftChild) return PERFORM_WELL;

	node_t* yNode = xNode->leftChild;

	yNode->parent = xNode->parent;
	xNode->parent = yNode;

	if (yNode->rightChild)
	{
		xNode->leftChild = yNode->rightChild;
		yNode->rightChild->parent = xNode;
	}
	yNode->rightChild = xNode;

	if (!yNode->parent) this->root = yNode;
	else if (yNode->parent->leftChild == xNode) yNode->parent->leftChild = yNode;
	else yNode->parent->rightChild = yNode;

	return PERFORM_WELL;

}

STATE RedBlackTree::LeftRotate(node_t* yNode)
{

	if (!yNode) return ERROR_INVALID_INPUT;
	if (!yNode->rightChild) return PERFORM_WELL;

	node_t* xNode = yNode->rightChild;
	xNode->parent = yNode->parent;
	yNode->parent = xNode;

	if (xNode->leftChild)
	{
		yNode->rightChild = xNode->leftChild;
		xNode->leftChild->parent = xNode;
	}
	xNode->leftChild = yNode;

	if (!xNode->parent) this->root = xNode;
	else if (xNode->parent->leftChild == yNode) xNode->parent->leftChild = xNode;
	else xNode->parent->rightChild = xNode;

	return PERFORM_WELL;
}


/*
	InsertNode
	RedBlackTree�� ��带 �������ִ� �Լ�.
	���ڷ� int�� �����͸� ������, Node_t�� �Ҵ����ְ� �˸��� �ڸ��� insert�����ش�.
	
	1. insert�� �����͸� ���� Node_t �Ҵ�.
		left/rightChild = NULL, color = Red, Data = inputInt.

	2. BST Insert ����.
		��������� �־��� ���� ���ϸ� ���Ͽ� left, right���ϵ带 �ٽ� ȣ���ϴ� �Լ� ����.
		(�� �� �ߺ����� ���ٰ� ����)

	3. insert ��� ��带 ������ ������ ������ ����.
		3-1. insert ��� ����� parent�� Black�� ���.
			insert ��� ��尡 ��Ʈ���� Ȯ�� ��, Black���� �������� �� PERFORM_WELL�� ��ȯ.

		3-2. insert ��� ����� parent�� Red�� ���.
			������ case�з��� ����.

			case 1 : GrandParent->Uncle->color == Red
				GrandParent->color = Red,
				Parent, Uncle->color = Black

			case 2 : Parent == GrandParent->leftChild, this == Parent->LeftChild
				GrandParent->color = Red, Parent->color = Black.
				GrandParent->rightRotate.

			case 3 : Parent == GrandParent->leftChild, this == Parent->RightChild
				Parent->leftRotate.
				�� ���� case 2�� ����.

			case 4 : Parent == GrandParent->rightChild, this == Parent->rightChild
				GrandParent->color = Red, Parent->color = Black.
				GrandParent->leftRotate.

			case 5 : Parent == GrandParent->rightChild, this == Parent->leftChild
				Parent->rightRotate.
				�� ���� case 4�� ����.

	4. �� ������ ������ ���� GrandParent�� color�� Red�� �Ǵ� 3-2 case 1�� ���, ��������� GrandParent�� ���ڷ��ϴ� �Լ� ����.
	5. root����� ���, ������ Black�̾���ϹǷ� Black���� ����� �� ��, PERFORM_WELL ��ȯ.
			
*/

int RedBlackTree::InsertNode(int inputData)
{
	node_t* inputNode;
	inputNode->rightChild = NULL;
	inputNode->leftChild = NULL;
	inputNode->color = Red;
	inputNode->data = inputData;

	if (!BSTinsert(inputNode))
	{
		return ERROR_INNER_FUNCTION;
	}


	
};

int RedBlackTree::CheckCases(node_t* childNode)
{
	if (childNode->parent->color == Black) return PERFORM_WELL;
	


}

int RedBlackTree::BSTinsert(node_t* inputNode)
{
	if (!inputNode) return ERROR_INVALID_INPUT;

	node_t* currentNode = root;
	node_t* beforeNode;

	while (!currentNode)
	{
		beforeNode = currentNode;

		if (currentNode->data < inputNode->data) currentNode = currentNode->rightChild;
		else currentNode = currentNode->leftChild;
	}

	if (beforeNode->rightChild == currentNode)
	{
		beforeNode->rightChild = inputNode;
	}
	else
	{
		beforeNode->leftChild = inputNode;
	}
	inputNode->parent = beforeNode;

	return PERFORM_WELL;
}


int RedBlackTree::CalculateNodeAmount()
{
	if (!root) return 0;
	
	innerQueue->Push(root);
	int nodeAmountNumber = 0;
	node_t* receiveNodeWhichPoped;


	for (int i = 0; innerQueue->WatchWhatIsOnTop() != NULL; ++i)
	{
		receiveNodeWhichPoped = innerQueue->Pop();
		if (!receiveNodeWhichPoped->leftChild) innerQueue->Push(receiveNodeWhichPoped->leftChild);
		if (!receiveNodeWhichPoped->rightChild) innerQueue->Push(receiveNodeWhichPoped->rightChild); 
		++nodeAmountNumber;
	}

	return nodeAmountNumber;
}


Queue::Queue()
{
	(node_t*) memset(queueArray, 0, MAX_QUEUE_NUM);
}


void Queue::Push(node_t* inputNode)
{
	if (!inputNode)
	{
		printf("[Queue::Push] Input Node is NULL. \n");
		return;
	}
	if (top == MAX_QUEUE_NUM - 1)
	{
		printf("[Queue::Push] Queue is full. inputNode data was %d, color is %d. \n", inputNode->data, inputNode->color);
		return;
	}

	queueArray[++top] = inputNode;
	printf("[Queue::Push] Push complete. inputNode data was %d, color is %d. \n", inputNode->data, inputNode->color);
	printf("[Queue::Push] Now, top is on %d. \n", top);
	return;
}

node_t* Queue::Pop()
{
	if (top == -1)
	{
		printf("[Queue::Pop] Queue is empty. \n");
		return NULL;
	}

	node_t* returnNode = queueArray[top--];
	printf("[Queue::Pop] Pop complete. returnNode data is %d, color is %d. \n", returnNode->data, returnNode->color);
	printf("[Queue::Pop] Now, top is on %d. \n", top);
	return returnNode;
}

node_t* Queue::WatchWhatIsOnTop()
{
	if (top == -1)
	{
		printf("[Queue::Watch] Top is on -1. \n");
		return NULL;
	}

	else return queueArray[top];
}

bool Queue::IsQueueEmpty()
{
	if (top == -1) return true;
	else return false;
}




#endif