#include <iostream>


using namespace std;

const int ARRAY_MAX_SIZE = 255;
const int DIGIT_RANGE = 10;
const int RANDOM_RANGE = 900;
const int BASIC_INT = 100;

class Radix
{
	Radix() : size(-1) {}

	int size;
	int arr[ARRAY_MAX_SIZE];
	int transArr[ARRAY_MAX_SIZE];
	int outPut[ARRAY_MAX_SIZE];
	int score[DIGIT_RANGE];

	int MakeSampleArray();
	void RadixSort();
	void TransUnits();
	void TransTens();
	void TransHundreds();
	
	void CountScore();
	void AccumulateScore();
	void CountingSort();

};