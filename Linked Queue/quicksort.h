#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <string>
#include "LinkedQueue.h"
#include "sortSupport.h"

using std::string;

const int MAX_Q = 95;
const int MAX_WORD = 10000;
const int MAX_L = 15;

string randomWord1();
void quickSort(string theArray[], int left, int right);

#endif