#pragma once

#include <iostream>

using namespace std; 

// int값 배열과 배열 길이 length를 받아 정렬하는 함수.
void InsertionSort(int*, int);

// int값 배열과 배열 길이를 받아 정렬이 잘 되어있는지 확인하는 함수.
bool IsSorted(int*, int);

// test를 깔끔하게 실행하기 위한 함수.
void TestSorting(int*, int);