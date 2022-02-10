#ifndef UNSORTED_LIST_H
#define UNSORTED_LIST_H

// An exception class for when a GetItem operation fails
class NotFoundException{};

template <class ItemType>
class SortedList {
    public:
        /*
         * PutItem(ItemType item)
         * Function: Puts item to list
         * Preconditions:
         *      List has been initialized
         *      List is not full
         *      Item is not in list
         *      List is in sorted order
         * Postconditions:
         *      Item is in list
         *      List is in sorted order
         */
        virtual void PutItem(ItemType item)=0;

        /*
         * DeleteItem(ItemType item)
         * Function: Deletes the element whose key matches item's key
         * Preconditions:
         *      List has been initialized
         *      Key member of item is initialized
         *      One and only one element in list has a key matching item's key
         *      List is in sorted order
         * Postconditions:
         *      No element in list has a key matching item's key
         *      List is in sorted order
         */
        virtual void RemoveItem(ItemType item)=0;

        /*
         * ItemType GetItem (ItemType item)
         * Function: Get list element whose key matches item's key, if present.
         * Preconditions:
         *      List has been initialized.
         *      Key member of item is initialized
         *      One and only one element in list has a key matching item's key
         *      List is in sorted order
         * Postconditions:
         *      Element in list whose key matches item's key is returned
         *      List is in sorted order
         */
        virtual ItemType GetItem(ItemType item)=0;
};

#endif