#ifndef RADIX_H
#define RADIX_H
#include <string>
#include "LinkedQueue.h"
#include "sortSupport.h"

using std::string;

const int MAX_QS = 95;
const int MAX_WORDS = 10000;
const int MAX_LENGTH = 15;

void radixSort(string theArray[], int n, int d, int &counter);
string randomWord();

#endif