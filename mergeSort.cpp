/*
	작성일자 : 16.10.05
	작성자 : 141060 이근원 (highfence@naver.com)
	내용 : Merge Sort 함수를 구현한다.
	Edited By MS Visual Studio 2015.
*/


#include "mergeSort.h"

int main(void)
{



	return 0;
}



/*
	Merge
	1. 배열을 받아 두 개로 나눈다.
	2. 나눈 배열들을 버퍼에 복사한다. ( 이 때, 나눈 배열들은 각각 정렬된 상태 )
	3. 나눈 배열들의 첫 번째 배열을 각각 인덱스의 인자로 지정한다.
	
	while ( 원래 배열이 꽉 찰때 까지 )
		4. 어떤 인덱스가 배열의 끝을 가리키고 있다면, 다른 인덱스를 원래 배열에 채워넣는다.
		5. 끝을 가리키고 있지 않다면, 인덱스를 비교하여 작은 쪽을 배열에 채워넣는다.
		6. 채워넣은 쪽의 인덱스를 1 증가한다.
*/


void Merge(int* inputArr, int* bufferArr, int firstBegin, int firstLast, int secondLast)
{
	


}

/*
	CopyBlock
	인자 : 원래 배열의 시작 주소, 원래 배열의 끝 주소 + 1, 버퍼의 시작 주소.
	원래 배열의 시작주소에서 끝 주소까지의 배열을 버퍼에 복사한다.
*/

void CopyBlock(int* arrStart, int* arrEnd, int* bufferStart)
{
	for (int i = 0; arrStart + i < arrEnd; ++i)
	{
		bufferStart
	}
}