
#include <iostream>
#include <limits>
#include <stdlib.h>

using namespace std;

const int HEAP_MAX_ELEMENT = 255;
const int FIRST_ARRAY_VAL = INT_MAX;
const int RANDOM_VAL_RANGE = 100;

class Heap
{
public:
	Heap();
	int size;
	int element[HEAP_MAX_ELEMENT];

	int MakeSampleHeap();
	void PrintHeap();

	void MaxHeapify();
	void MaxHeapify(int);
	void IsMaxHeap();
	void BuildMaxHeap();
};
