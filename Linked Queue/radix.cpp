#ifndef RADIX_CPP
#define RADIX_CPP
#include <cmath>
#include "Node.h"
#include "radix.h"
#include "sortSupport.h"
#include <string>
#include <iostream>

using namespace std;

string randomWord()
{//generate random words for the linked list using 80% letters
	// and 10% digits and special characters
	int len = rand() % MAX_LENGTH + 1;
	string word;
	char ch;
	for (int x = 0; x < len; x++){
		switch (rand() % 10){
		case 0:
			ch = rand() % 10 + '0';
			break;
		case 1:
			do{
				ch = ' ' + rand() % MAX_QS;
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


void radixSort(string theArray[], int n, int d, int &counter)
{// Sorts n d-digit integers in the array theArray
	LinkedQueue<string> bucket[MAX_QS];

	counter=0;
	int i;
	string temp;

	for (int j = d; j >= 1; j--)
	{
		//	Initialize a counter for each group to 0
		for (i = 0; i < n; i++)
		{
			int dDigit = d - j;
			int mDigit = dDigit + 1;
			int k;

			if (j > theArray[i].length())
				k = 0;
			else
			{
				temp = theArray[i];
				k = temp[j-1] - ' ';
			}

			bucket[k].enqueue(theArray[i]);

		/*Replace the items in theArray with all the items in group 0, followed
			by all the items in group 1, and so on*/
		counter = 0;
		for (int bIndex = 0; bIndex < MAX_QS; bIndex++)
		{

			while (!bucket[bIndex].isEmpty())
			{
				theArray[counter] = bucket[bIndex].peekFront();
				bucket[bIndex].dequeue();
				counter++;
			}
		}
	} // end for j

}
#endif
