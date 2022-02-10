#ifndef ARRAY_UNSORTED_LIST_H
#define ARRAY_UNSORTED_LIST_H

#include "SortedList.h"

using namespace std;

// An array-based implementation of the unsorted list ADT
template <class ItemType>
class ArraySortedList: public SortedList<ItemType> {
    public:
        // Constructor: Initialize the list to a maximum size
        ArraySortedList(int maxSize) {
            this->maxSize = maxSize;
            this->size = 0;
            this->items = new ItemType[maxSize];
        }

        virtual void PutItem(ItemType item) {
            // Note: Per its specification, this function assumes there is
            // sufficient space in the list to store the new item.

            int location = 0;

            // Find the correct place to put the item
            for(location = 0; location < size; location++) {
                if (items[location] > item) {
                    break;
                }
            }

            // Set aside space for the new item
            for(int j = size; j > location; j--) {
                items[j] = items[j-1];
            }
            
            // Put the new item in its place
            items[location] = item;

            // Increment the size counter
            this->size++;
        }

        virtual ItemType GetItem(ItemType item) {
            // Look for the item
            for (int i = 0; i < this->size; i++) {
                if (this->items[i] == item) {
                    // If we found it, return the item
                    return this->items[i];
                }
            }

            // We didn't find it.
            throw NotFoundException();
        }

        virtual void RemoveItem(ItemType item) {
            // Note: Per its specification, this function assumes that
            // the item to be deleted is contained in the list.

            int location = 0;

            // Find the item to delete
            for(location = 0; location < size; location++) {
                if (items[location] == item) {
                    break;
                }
            }

            // Move over the remaining items to erase the element
            for(int j = location + 1; j < size; j++) {
                items[j-1] = items[j];
            }

            this->size--;
        }
        
    private:
        int maxSize;
        int size;
        ItemType *items;
};

#endif