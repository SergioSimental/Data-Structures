#ifndef SORTSUPPORT_H
#define SORTSUPPORT_H
#include <random>
const int MAX_NUM = 100000;

//const int SPACE = 32;

template <class ItemType>
void generateArray(ItemType [], int);

template <class ItemType>
void printFirstMidLast(ItemType[], int);


#include "sortSupport.cpp"
#endif