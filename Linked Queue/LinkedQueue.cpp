
#ifndef LINKED_QUEUE_CPP
#define LINKED_QUEUE_CPP

#include "LinkedQueue.h"
#include <cassert>
#include <memory>


template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{     }  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{  // Implementation left as an exercise (Exercise 1).
   auto origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain

   // Using shared pointers initializes frontPtr/backPtr to nullPtr
   if (origChainPtr != nullptr)
   {
      // Copy first node
      frontPtr = std::make_shared<Node<ItemType>>();
      frontPtr->setItem(origChainPtr->getItem());

      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();

      // Copy remaining nodes
      auto newChainTailPtr = frontPtr;        // Points to last node in new chain
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem);

         // Link new node to end of new chain
         newChainTailPtr->setNext(newNodePtr);

         // Advance pointers
         newChainTailPtr = newChainTailPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainTailPtr->setNext(nullptr);               // Flag end of chain
      backPtr = newChainTailPtr;
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
   //smart pointers will clean-up
   backPtr == nullptr;
   frontPtr == nullptr;
}  // end destructor

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
   return backPtr == nullptr;
}  // end isEmpty

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

   // Insert the new node
   if (isEmpty())
      frontPtr = newNodePtr;        // Insertion into empty queue
   else
      backPtr->setNext(newNodePtr); // Insertion into nonempty queue

   backPtr = newNodePtr;            // New node is at back

	return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
      // Queue is not empty; delete front
	  auto nodeToDeletePtr = frontPtr;
      if (frontPtr == backPtr)
      {  // Special case: one node in queue
         backPtr = nullptr;
         frontPtr = nullptr;
      }
      else
      {
		frontPtr = frontPtr->getNext();
	  }

      result = true;
	}  // end if

	return result;
}  // end dequeue

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("getFront() called with empty queue.");

   // Queue is not empty; return front
   return frontPtr->getItem();
}  // end peekFront

template<class ItemType>
void LinkedQueue<ItemType>::LastFirst()
{
	string name;
	int length, x;
	auto curPtr = frontPtr;
	while (curPtr != nullptr)
	{
		while (curPtr != nullptr)
		{
			name = curPtr->getItem();
			x = name.find(' ');
			length = name.length();
			if (x > 0)
			{
				name = name.substr(x+1, length) + ", " + name.substr(0, x);
				curPtr->setItem(name);
			}
			curPtr = curPtr->getNext();
		}
	}
}

template<class ItemType>
int LinkedQueue<ItemType>::LineRemove(char letter)
{
	int count = 0;
	string name;
	shared_ptr<Node<ItemType>> prevPtr = nullptr;
	shared_ptr<Node<ItemType>> currPtr = frontPtr;
	shared_ptr<Node<ItemType>> deletePtr;
	while (currPtr != nullptr) {
		deletePtr = nullptr;
		name = currPtr->getItem();
		if (name[0] == letter) {
			count++;
			deletePtr = currPtr;
			currPtr = currPtr->getNext();
			if (prevPtr == nullptr)
				frontPtr = frontPtr->getNext();
			else {
				if (frontPtr == nullptr)
					backPtr = nullptr;
				else {
					prevPtr->setNext(currPtr);
					if (currPtr == nullptr)
						backPtr = prevPtr;
				}
			}
//			delete deletePtr;
		}
		else {
			prevPtr = currPtr;
			currPtr = currPtr->getNext();
		}
	}
	return count;
}


template<ItemType>
void LinkedQueue<ItemType>::display()
{
	while (!isEmpty())
	{
		cout << peekTop();

		dequeue();
	}
}
#endif
