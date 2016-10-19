#include <iostream>
#include <stdlib.h>

using namespace std;

const int RAND_RANGE = 100;
const int RAND_MINUS_VAL = 50;
const int MAX_ALLOCATE = 50;
const int INIT_MINUS_INFINIT = -999999;

typedef struct idxAndSum
{
	int startIdx;
	int endIdx;
	int sumVal;
}idxAndSum;


// Funtions
void printResult(idxAndSum*, idxAndSum*, int*, int);
int* makeRandArray(int);
idxAndSum* BruteWayFunc(int*, int);
void testInterface();
void FindMaxCrossingSubarray(int*, int, int, int, int*, int*, int*);
void FindMaximumSum(int*, int, int, int*, int*, int*);
void copyArray(int*, int*, int);