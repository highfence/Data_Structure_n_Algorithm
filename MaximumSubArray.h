#include <iostream>
using namespace std;

typedef struct idxAndSum
{
	int startIdx;
	int endIdx;
	int sumVal;
};


// Funtions
idxAndSum* BruteWayFunc(int*, int);