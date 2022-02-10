#include "SortedList.h"
#include "ArraySortedList.h"
#include "LinkedSortedList.h"

#include <iostream>

using namespace std;

void testList(SortedList<int> &l) {
    l.PutItem(20);
    l.PutItem(19);
    l.PutItem(21);
    l.PutItem(100);
    l.PutItem(-100);
    l.RemoveItem(19);

    int found = l.GetItem(21);
    cout << "Found 21" << endl;

    try {
        found = l.GetItem(19);
    } catch(NotFoundException e) {
        cout << "19 not found - OK" << endl;
    }

    try {
        found = l.GetItem(200);
    } catch(NotFoundException e) {
        cout << "200 not found - OK" << endl;
    }
}

int main() {
    ArraySortedList<int> arrayList = ArraySortedList<int>(100);
    testList(arrayList);

    LinkedSortedList<int> linkedList = LinkedSortedList<int>();
    testList(linkedList);
}