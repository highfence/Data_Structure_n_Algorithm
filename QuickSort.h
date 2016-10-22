#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_ARRAY_SIZE = 255;
const int RANDOM_VAL_RANGE = 100;
const int REPEAT_COUNT = 32;
const int RANDOM_PLUS_RANGE = 10;
const int MAKING_ELEMENT_COUNT = 10;

class testArr
{
public :
	testArr();

	int size;
	int arr[MAX_ARRAY_SIZE];

	int MakeRandomArray(int);
	void PrintArray();
	void Swap(int, int);
	int Partition(int, int);
	bool IsPartitionRight(int);
	void TestPartition(int);
	void MakeAscendingArr();
	void MakeDescendingArr();
};