/*
	Red-BlackTree
	작성자 : 141060 이근원
	최초작성일자 : 16.12.06
	최근수정일자 : 16.12.08
	내용 : Red-Black Tree와 그에 필요한 여러 함수를 구현.

		1. Red-Black Tree 기본 구조 구현.
		2. Right/Left Rotate 구현.
		3. InsertNode 구현.
*/

#define Red_BlackTree

#ifdef Red_BlackTree

#include "Red-BlackTree.h"

/*
	RightRotate / LeftRotate
	각각 어떤 노드의 포인터를 받아서 Rotate시켜주는 함수.

		입력노드가 없다면 에러값 INVALID_INPUT을 반환.
		각각 입력노드의 leftChild / RightChild가 없거나, 수행이 정상적으로 종료되면 PERFORM_WELL을 반환.

		RightRotate
		1. 입력 노드가 없다면, 에러값 반환.
		2. LeftChild가 존재하지 않는다면, 함수의 수행을 끝냄. (PERFORM_WELL)
		3. LeftChild를 yNode로 명명.
		4. yNode의 parent를 xNode의 parent로 지정 후, xNode의 parent를 yNode로 지정.
		5. yNode의 rightChild가 존재한다면, xNode의 leftChild로 지정.
		6. yNode의 rightChild를 xNode로 지정.
		7. xNode와 원래 parent사이에 따라 yNode와 원래 parent사이의 관계를 지정.
		end.

		LeftRotate
		1. RightRotate와 방향과 x / y 노드를 반대로 진행.
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
	RedBlackTree에 노드를 삽입해주는 함수.
	인자로 int값 데이터를 받으면, Node_t를 할당해주고 알맞은 자리에 insert시켜준다.

	1. insert값 데이터를 갖는 Node_t 할당.
		left/rightChild = NULL, color = Red, Data = inputInt.

	2. BST Insert 수행.
		재귀적으로 주어진 노드와 상하를 비교하여 left, right차일드를 다시 호출하는 함수 구현.
		(이 때 중복값은 없다고 가정)

	3. insert 결과 노드를 가지고 다음의 전략을 구현.
		3-1. insert 결과 노드의 parent가 Black일 경우.
			insert 결과 노드가 루트인지 확인 후, Black으로 설정해준 뒤 PERFORM_WELL을 반환.

		3-2. insert 결과 노드의 parent가 Red일 경우.
			다음의 case분류를 따름.

			case 1 : GrandParent->Uncle->color == Red
				GrandParent->color = Red,
				Parent, Uncle->color = Black

			case 2 : Parent == GrandParent->leftChild, this == Parent->LeftChild
				GrandParent->color = Red, Parent->color = Black.
				GrandParent->rightRotate.

			case 3 : Parent == GrandParent->leftChild, this == Parent->RightChild
				Parent->leftRotate.
				그 이후 case 2와 같음.

			case 4 : Parent == GrandParent->rightChild, this == Parent->rightChild
				GrandParent->color = Red, Parent->color = Black.
				GrandParent->leftRotate.

			case 5 : Parent == GrandParent->rightChild, this == Parent->leftChild
				Parent->rightRotate.
				그 이후 case 4와 같음.

	4. 이 전략을 가지고 최종 GrandParent의 color가 Red가 되는 3-2 case 1의 경우, 재귀적으로 GrandParent를 인자로하는 함수 실행.
	5. root노드인 경우, 무조건 Black이어야하므로 Black으로 만들어 준 뒤, PERFORM_WELL 반환.

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
	// ChildNode가 root인 경우. ChildNode를 black으로 만들어 준 뒤, 종료.
	if (childNode == root)
	{
		childNode->color = Black;
		return PERFORM_WELL;
	}

	// ChildNode의 parent가 black일 경우 
	if (childNode->parent->color == Black)
	{
		return PERFORM_WELL;
	}

	// ChildNode의 parent가 red일 경우, case분류를 위해 node를 지정해 준다.
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

	// Case 1 : Uncle의 색이 Red인 경우.
	if (uncle->color == Red)
	{
		grandParent->color = Red;
		parent->color = Black;
		uncle->color = Black;
	}

	// Case 2 : Parent가 GP의 left고, child가 Parent의 left인 경우.
	// Case 3 : Parent가 GP의 left고, child가 Parent의 right인 경우.
	else if (parent == grandParent->leftChild)
	{
		if (childNode == parent->rightChild)
		{
			LeftRotate(parent);
		}

		grandParent->color = Red;
		parent->color = Black;
		RightRotate(grandParent);

		// 재귀적으로 호출.
		CheckCases(grandParent);
	}

	// Case 4 : Parent가 GP의 right고, child가 Parent의 right인 경우.
	// Case 5 : Parent가 GP의 right고, child가 Parent의 left인 경우.
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