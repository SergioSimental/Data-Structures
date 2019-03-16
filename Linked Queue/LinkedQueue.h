//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT queue: Link-based implementation.
 Listing 14-3.
 @file LinkedQueue.h */
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include <memory>
#include <string>
#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
   std::shared_ptr<Node<ItemType>> backPtr;
   std::shared_ptr<Node<ItemType>> frontPtr;

public:
   LinkedQueue();
   LinkedQueue  (const LinkedQueue& aQueue);
   ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
   
   /** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcep);
	void LastFirst();
	int LineRemove(char letter);
	void display();
}; // end LinkedQueue

#include "LinkedQueue.cpp"
#endif
