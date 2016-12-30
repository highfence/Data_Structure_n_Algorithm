#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

const int MAX_QUEUE_NUM = 256;

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
	struct node* parent;
	struct node* leftChild;
	struct node* rightChild;

	int data;
	COLOR color;

} node_t;

class Queue
{
public:
	Queue();
	node_t* queueArray[MAX_QUEUE_NUM];
	int top = -1;

	void Push(node_t*);
	node_t* Pop();
	node_t* WatchWhatIsOnTop();
	bool IsQueueEmpty();

};

class RedBlackTree
{
public :
	node_t* root;
	Queue* innerQueue;
	node_t* nilNode;

	RedBlackTree();
	
	
	STATE RightRotate(node_t*);
	STATE LeftRotate(node_t*);
	bool IsRedBlackTreeCompleted();
	int InsertNode(int);
	int BSTinsert(node_t*);
	int CheckCases(node_t*);
	int DeleteNode(int);
	int BSTdelete(int);

	int CalculateNodeAmount();
	int CalculateChildAmount(node_t* root);

	void printInterface();
	void printMenu();
	void insertInterface();
	void searchInterface();
};



