//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file  HashedDictionary.cpp */

// Separate chaining resolves collisions

// PARTIALLY COMPLETE
#include "HashedDictionary.h"
#include <string>
#include <fstream>
#ifndef HASHED_DICTIONARY_CPP
#define HASHED_DICTIONARY_CPP

using namespace std;

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	for (int index = 0; index < TABLE_SIZE; index++)
		hashTable[index] = nullptr;
}

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
	clear();
}

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &sKey) const
{
    int seed = 131; 
    unsigned long hash = 0;
    for(int i = 0; i < sKey.length(); i++)
    {
        hash = (hash * seed) + sKey[i];
    }
    return hash % TABLE_SIZE;

}

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   // Create entry to add to dictionary
   HashedEntry<KeyType, ItemType>* entryToAddPtr =
                  new HashedEntry<KeyType, ItemType>(newItem, searchKey);
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   
   // Add the entry to the chain at itemHashIndex
   if (hashTable[itemHashIndex] == nullptr)
   {
      hashTable[itemHashIndex] = entryToAddPtr;
   }
   else
   {
      entryToAddPtr->setNext(hashTable[itemHashIndex]);
      hashTable[itemHashIndex] = entryToAddPtr;
   } // end if
   
   return true;
} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
   bool itemFound = false;
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   if (hashTable[itemHashIndex] != nullptr)
   {
      // Special case - first node has target
      if (searchKey == hashTable[itemHashIndex]->getKey())
      {
         HashedEntry<KeyType, ItemType>* entryToRemovePtr = hashTable[itemHashIndex];
         hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
         delete entryToRemovePtr;
         entryToRemovePtr = nullptr; // For safety
         itemFound = true;
      }
      else // Search the rest of the chain
      {
         HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
         HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
         while ((curPtr != nullptr) && !itemFound )
         {
            // Found item in chain so remove that node
            if (searchKey == curPtr->getKey())
            {
               prevPtr->setNext(curPtr->getNext());
               delete curPtr;
               curPtr = nullptr; // For safety
               itemFound = true;
            }
            else // Look at next entry in chain
            {
               prevPtr = curPtr;
               curPtr = curPtr->getNext();
            } // end if
         } // end while
      } // end if
   } // end if
   
   return itemFound;
} // end remove

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
    for (int index = 0; index < TABLE_SIZE; index++){
	    if(hashTable[index] != nullptr)
            return false;
    }
    return true;
}

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
	int numOfItems = 0;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		HashedEntry<KeyType, ItemType>* ptr = hashTable[i];
		if (ptr != nullptr){
			ptr = ptr->getNext();
			numOfItems++;
			while (ptr != nullptr)
			{
				ptr = ptr->getNext();
				numOfItems++;
			}
		}
	}
	return numOfItems;
}

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
	for (int x = 0; x < TABLE_SIZE; x++)
	{
		HashedEntry<KeyType, ItemType>* ptr = hashTable[x];
		while (ptr != nullptr)
		{
			hashTable[x] = ptr->getNext();
			ptr->setNext(nullptr);
			delete ptr;
			ptr = hashTable[x];
		}
	}
}

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{
   bool itemFound = false;
   int age = 0;
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   HashedEntry<KeyType, ItemType>* entryToLookPtr = hashTable[itemHashIndex];
   if (hashTable[itemHashIndex] != nullptr)
   {
      // Special case - first node has target
      if (searchKey == hashTable[itemHashIndex]->getKey())
      {
        age = entryToLookPtr->getItem();
        itemFound = true;
      }
      else // Search the rest of the chain
      {
         entryToLookPtr = entryToLookPtr->getNext();
         while ((entryToLookPtr != nullptr) && !itemFound )
         {
            // Found item in chain so remove that node
            if (searchKey == entryToLookPtr->getKey())
            {
               age = entryToLookPtr->getItem();
               itemFound = true;
            }
            else // Look at next entry in chain
            {
               entryToLookPtr = entryToLookPtr->getNext();
            } // end if
         } // end while
      } // end if
   } // end if
   
   return age;
}

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	bool found = false;
	int index = 0;
	int itemCount = getNumberOfItems();
	while (!found && index < itemCount)
	{
        HashedEntry<KeyType, ItemType>* entryToLookPtr = hashTable[index];
		if (hashTable[index]->getKey() == searchKey)
		{
			found = true;
		}
        else // Search the rest of the chain
        {
            entryToLookPtr = entryToLookPtr->getNext();
            while ((entryToLookPtr != nullptr) && !found )
            {
                // Found item in chain so remove that node
                if (searchKey == entryToLookPtr->getKey())
                {
                    found = true;
                }
                else // Look at next entry in chain
                {
                    entryToLookPtr = entryToLookPtr->getNext();
                } // end if
            }
	}   
    }
    return found;
}

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
	KeyType name;
	ItemType age;
	int total = 0;
	double avgAge = 0;
	double alpha = 0;
	for (int index = 0; index < TABLE_SIZE; index++)
	{
		HashedEntry<KeyType, ItemType>* ptr = hashTable[index];
		if (ptr != nullptr){
			name = ptr->getKey();
			age = ptr->getItem();
			cout << "Slot #" << index << ", " << name << " ";
			visit(age);
			total += age;
			ptr = ptr->getNext();
			while (ptr != nullptr)
			{
				name = ptr->getKey();
				age = ptr->getItem();
				cout << ", " << name << " ";
				visit(age);
				total += age;
				ptr = ptr->getNext();
			}
			cout << endl;
		}
	}
	cout << getNumberOfItems() << endl;
	avgAge = (double)total / getNumberOfItems();
	alpha = (double)getNumberOfItems() / TABLE_SIZE;
	
	cout << "Average age is " << avgAge << endl;
	cout << "Alpha = " << alpha <<endl;
}
template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::writeFile(string file)
{
	ofstream outFile(file); 
	KeyType name;
	ItemType age;
	for (int index = 0; index < TABLE_SIZE; index++)
	{

		HashedEntry<KeyType, ItemType>* ptr = hashTable[index];
		if (ptr != nullptr){
			name = ptr->getKey();
			age = ptr->getItem();
			ptr = ptr->getNext();
			outFile << name << " " <<age << endl;
			while (ptr != nullptr)
			{
				name = ptr->getKey();
				age = ptr->getItem();
				ptr = ptr->getNext();
				outFile << name << " " << age << endl;
			}
		}
	}
	outFile.close();
}
//HashedDictionary<std::string, int> xyz;


#endif