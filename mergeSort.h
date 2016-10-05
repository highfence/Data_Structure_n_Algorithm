#pragma once

#include <iostream>

using namespace std;

class testSet {
public :
	testSet();
	testSet(int*, int);
	~testSet();

	int* m_array;
	int* m_buffer;
	int* m_length;

	void test();
	void printArray();
};


void Merge(int*, int*, int, int, int);
void CopyBlock(int*, int*, int, int);

void MergeSort(int*, int*, int, int);
bool IsSorted(int*, int);


