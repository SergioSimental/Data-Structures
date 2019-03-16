/*
Sergio Simental
CS 212
Lab 3
*/

#include "radix.h"
#include "quicksort.h"
#include "LinkedQueue.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	string arr[MAX_WORDS];
	string arr1[MAX_WORD];
	int count = 0;

	for (int x = 0; x < MAX_WORDS; x++){
		string in = randomWord();
		arr[x] = in;
	}
	
	for (int x = 0; x < MAX_WORD; x++){
		string in = randomWord1();
		arr1[x] = in;
	}
	cout << "Unsorted Radix" << endl;
	printFirstMidLast(arr, MAX_WORDS);
	radixSort(arr, MAX_WORDS, MAX_LENGTH, count);
	cout << "Sorted Radix" << endl;
	printFirstMidLast(arr, MAX_WORDS);

	cout << endl << "Unsort Quicksort" << endl;
	printFirstMidLast(arr1, MAX_WORD);
	quickSort(arr1, 0, MAX_WORD);
	cout << "Sorted Quicksort" << endl;
	printFirstMidLast(arr1, MAX_WORD);
	system("pause");
}
