
/* A class of entry objects for an array-based implementation of the ADT dictionary.
 @file Entry.h */

#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry
{
private:
   ItemType item;
   KeyType searchKey;

protected:
   void setKey(const KeyType& searchKey);

public:
   Entry();
   Entry(ItemType newEntry, KeyType searchKey);
   ItemType getItem() const;
   KeyType getKey() const;
   void setItem(const ItemType& newEntry);
   bool operator==(const Entry<KeyType, ItemType>& rightHandItem) const;
   bool operator>(const Entry<KeyType, ItemType>& rightHandItem) const;
}; // end Entry

#include "Entry.cpp"
#endif
