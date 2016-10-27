#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 255;
const int RANDOM_RANGE = 100;

class Test
{
public :
	Test();

	int size;
	int arr[MAX_ARRAY_SIZE];
	int outputArr[MAX_ARRAY_SIZE];
	int score[RANDOM_RANGE + 1];

	int MakeSampleArray();
	void CountScore();
	void AccumulateScore();
	void CountingSort();
	void PrintAll();

};