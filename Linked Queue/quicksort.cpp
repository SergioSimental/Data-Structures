#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP
#include "Node.h"
#include "quicksort.h"
#include "sortSupport.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string randomWord1()
{//generate random words for the linked list using 80% letters 
	// and 10% digits and special characters
	int len = rand() % MAX_L + 1;
	string word;
	char ch;
	for (int x = 0; x < len; x++){
		switch (rand() % 10){
		case 0:
			ch = rand() % 10 + '0';
			break;
		case 1:
			do{
				ch = ' ' + rand() % MAX_Q;
			} while (!!ispunct(ch));
			break;
		default:
			if (rand() % 2 == 0)
				ch = 'A' + rand() % 26; // uppercase
			else
				ch = 'a' + rand() % 26; // lowercase
			break;
		}
		word += ch;
	}
	return word;
}

void quickSort(string theArray[], int left, int right) {
	int i = left;
	int j = right-1;
	int mid = (left + right) / 2;
	string pivot = theArray[mid];
	string temp;
	/* partition */
	while (i <= j) {
		while (theArray[i] < pivot)
			i++;
		while (theArray[j] > pivot)
			j--;
		if (i <= j) {
			temp = theArray[i];
			theArray[i] = theArray[j];
			theArray[j] = temp;
			i++;
			j--;
		}
	}
	/* recursion */
	if (left < j)
		quickSort(theArray, left, j);
	if (i < right)
		quickSort(theArray, i, right);
}
#endif