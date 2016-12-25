#include <iostream>
#include <Windows.h>


enum COLOR
{
	Red = 0, Black = 1
};


/* Return State Variables */
enum STATE
{
	PERFORM_WELL = 0,
	ERROR_INVALID_INPUT = -1,
	ERROR_INNER_FUNCTION = -2
};


typedef struct node
{
	node_t* parent;
	node_t* leftChild;
	node_t* rightChild;

	int data;
	COLOR color;

} node_t;


class RedBlackTree
{
public :
	node_t* root;
	Queue* innerQueue;
	
	
	STATE RightRotate(node_t*);
	STATE LeftRotate(node_t*);
	bool IsRedBlackTreeCompleted();
	int InsertNode(int);
	int BSTinsert(node_t*);
	int CheckCases(node_t*);

	int CalculateNodeAmount();
	int CalculateChildAmount(node_t* root);


};


const int MAX_QUEUE_NUM = 256;

class Queue
{
public :
	Queue();
	node_t* queueArray[MAX_QUEUE_NUM];
	int top = -1;
	
	void Push(node_t*);
	node_t* Pop();
	node_t* WatchWhatIsOnTop();
	bool IsQueueEmpty();

};