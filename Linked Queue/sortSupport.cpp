#include "sortSupport.h"
#ifndef SORTSUPPORT_CPP
#define SORTSUPPORT_CPP

template <class ItemType>
void generateArray(ItemType ary[], int size){
	bool doubleNum = sizeof(ItemType) > 4;
	for (int x = 0; x < size; x++)
	{
		if (doubleNum)
			ary[x] = double(rand()) / RAND_MAX * MAX_NUM;
		else
			ary[x] = rand() % MAX_NUM;
	}
}

template <class ItemType>
void printFirstMidLast(ItemType ary[], int size){
	int mid = size / 2;
	if (size < 30)
		cout << "Array to small to print first, mid and last\n";
	else{
		for (int x = 0; x < 10; x++)
			cout << ary[x] << " ";
		cout << " ... ";
		for (int x = mid - 5; x < mid + 5; x++)
			cout << ary[x] << " ";
		cout << " ... ";
		for (int x = size - 10; x < size; x++)
			cout << ary[x] << " ";
		cout << endl;
	}
}
#endif
