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


RedBlackTree::RedBlackTree()
{
	root = nullptr;
	nilNode = new node_t;
	nilNode->color = Black;
	nilNode->data = INT_MIN;
}

STATE RedBlackTree::RightRotate(node_t* x)
{
	if (!x) return ERROR_INVALID_INPUT;
	if (!x->leftChild) return PERFORM_WELL;

	node_t* y = x->leftChild;

	y->parent = x->parent;
	if (x->parent->data == INT_MIN) root = y;
	else if (x->parent->rightChild = x) x->parent->rightChild = y;
	else x->parent->leftChild = y;
	
	x->leftChild = y->rightChild;
	if (y->rightChild) y->rightChild->parent = x;

	y->rightChild = x;
	x->parent = y;

	return PERFORM_WELL;

}

STATE RedBlackTree::LeftRotate(node_t* y)
{

	if (!y) return ERROR_INVALID_INPUT;
	if (!y->rightChild) return PERFORM_WELL;

	node_t* x = y->rightChild;
	
	x->parent = y->parent;
	if (x->parent->data == INT_MIN) root = x;
	else if (x->parent->rightChild == y) x->parent->rightChild = x;
	else x->parent->leftChild = x;

	y->rightChild = x->leftChild;
	if (x->leftChild) x->leftChild->parent = y;

	x->leftChild = y;
	y->parent = x;
	

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
	node_t* inputNode = new node_t;
	inputNode->rightChild = nilNode;
	inputNode->leftChild = nilNode;
	inputNode->parent = nilNode;
	inputNode->color = Red;
	inputNode->data = inputData;

	if (BSTinsert(inputNode))
	{
		return ERROR_INNER_FUNCTION;
	}

	int retval = CheckCases(inputNode);

	return PERFORM_WELL;
};

int RedBlackTree::CheckCases(node_t* childNode)
{
	// ChildNode�� root�� ���. ChildNode�� black���� ����� �� ��, ����.
	if (childNode == root)
	{
		childNode->color = Black;
		return PERFORM_WELL;
	}

	// ChildNode�� parent�� black�� ��� 
	if (childNode->parent->color == Black)
	{
		return PERFORM_WELL;
	}

	// ChildNode�� parent�� red�� ���, case�з��� ���� node�� ������ �ش�.
	node_t* parent = childNode->parent;
	node_t* grandParent = parent->parent;
	node_t* uncle;

	if (grandParent->leftChild == parent)
	{
		uncle = grandParent->rightChild;
	}
	else
	{
		uncle = grandParent->leftChild;
	}

	// Case 1 : Uncle�� ���� Red�� ���.
	if (uncle->color == Red)
	{
		grandParent->color = Red;
		parent->color = Black;
		uncle->color = Black;
	}

	// Case 2 : Parent�� GP�� left��, child�� Parent�� left�� ���.
	// Case 3 : Parent�� GP�� left��, child�� Parent�� right�� ���.
	else if (parent == grandParent->leftChild)
	{
		if (childNode == parent->rightChild)
		{
			LeftRotate(parent);
		}

		grandParent->color = Red;
		parent->color = Black;
		RightRotate(grandParent);

		// ��������� ȣ��.
		CheckCases(grandParent);
	}

	// Case 4 : Parent�� GP�� right��, child�� Parent�� right�� ���.
	// Case 5 : Parent�� GP�� right��, child�� Parent�� left�� ���.
	else
	{
		if (childNode == parent->leftChild)
		{
			RightRotate(parent);
		}

		grandParent->color = Red;
		parent->color = Black;
		LeftRotate(grandParent);
	}

	root->color = Black;
	return PERFORM_WELL;
}

int RedBlackTree::BSTinsert(node_t* inputNode)
{
	if (!inputNode) return ERROR_INVALID_INPUT;
	if (!root)
	{
		root = inputNode;
		return PERFORM_WELL;
	}

	node_t* currentNode = root;
	node_t* beforeNode = root;

	while (currentNode)
	{
		if (currentNode->data == INT_MIN)
		{
			break;
		}
		else
		{
			beforeNode = currentNode;
			if (currentNode->data < inputNode->data)
			{
				currentNode = currentNode->rightChild;
			}
			else
			{
				currentNode = currentNode->leftChild;
			}
		}
	}

	if (beforeNode->data < inputNode->data)
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

int RedBlackTree::DeleteNode(int deleteData)
{
	return 0;
}

int RedBlackTree::BSTdelete(int deleteData)
{
	if (!root) return 0;
	


	return 0;
}

void RedBlackTree::printInterface()
{
	int inputCommand = 1;

	while (inputCommand != 0)
	{
		system("cls");

		printMenu();
		cin >> inputCommand;
		
		if (inputCommand == 1)
		{
			insertInterface();
		}
		else if (inputCommand == 2)
		{
			searchInterface();
		}
	}

	return;
}

void RedBlackTree::printMenu()
{
	cout << "This is Red-Black Tree!" << endl;
	cout << "1. insert node" << endl;
	cout << "2. explore tree" << endl;
	cout << "0. exit" << endl;
	cout << "What do you want to do? : ";
	
	return;
}

void RedBlackTree::insertInterface()
{
	int inputData = 0;
	cout << "Write the data which you want to insert : ";
	cin >> inputData;

	int retval = InsertNode(inputData);
	if (retval == PERFORM_WELL)
	{
		cout << "Node Insert! (Press Enter)" << endl;
		getchar();
	}

	return;
}

void RedBlackTree::searchInterface()
{

	node_t* currentNode = root;
	node_t* beforeNode = root;
	int inputArrow = 0;

	while (inputArrow != DOWN)
	{
		system("cls");
		if (!currentNode || currentNode->data == INT_MIN)
		{
			cout << "Oh, We are in the NULL now." << endl;
			cout << "Press ARROW UP to go parent node." << endl;
			cout << "Press ARROW DOWN to end explore." << endl;
			inputArrow = _getch();

			if (inputArrow == DOWN)
			{
				break;
			}
			else if (inputArrow == UP && currentNode != beforeNode)
			{
				currentNode = beforeNode;
				beforeNode = currentNode->parent;
			}
		}
		else
		{
			cout << "We are in the ";
			if (currentNode->color == Red) cout << "Red";
			else cout << "Black";
			cout << "node." << endl;

			cout << "The data is : " << currentNode->data << endl;
			cout << endl;
			
			cout << "Wanna go to leftChild? Press ARROW LEFT." << endl;
			cout << "Wanna go to rightChild? Press ARROW RIGHT." << endl;
			cout << "Wanna go to parentChild? Press ARROW UP." << endl;
			cout << "Press ARROW DOWN to end this explore." << endl;

			inputArrow = _getch();
			beforeNode = currentNode;

			if (inputArrow == DOWN)
			{
				break;
			}
			else if (inputArrow == UP)
			{
				currentNode = currentNode->parent;
			}
			else if (inputArrow == LEFT)
			{
				currentNode = currentNode->leftChild;
			}
			else if (inputArrow == RIGHT)
			{
				currentNode = currentNode->rightChild;
			}
		}

	}

	return;
}


Queue::Queue()
{
	(node_t*)memset(queueArray, 0, MAX_QUEUE_NUM);
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