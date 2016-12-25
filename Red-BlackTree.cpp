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