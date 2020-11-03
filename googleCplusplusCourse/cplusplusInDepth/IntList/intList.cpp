// Description: A simple int list class implementation.

using namespace std;

#include "intList.h"

IntList::IntList(): Items(new int[SIZE]), numItems(0), arraySize(SIZE) {
}

IntList::IntList(int value, int copies): Items(new int[SIZE]), numItems(0), arraySize(SIZE) {
    for (int i = 0; i < copies; i++) {
        AddToEnd(value);
    }
}


IntList::~IntList() {
    delete [] Items;
    numItems = 0;
    arraySize = 0;
}

void IntList::AddToEnd(int k) {
    if (numItems + 1 >= arraySize) {
        arraySize *= 2;
        int *items_new = new int[arraySize];
        for ( int i = 0; i < numItems ; i++ ) {
            items_new[i] = Items[i];
        }
        delete [] Items;
        Items = items_new;
    }
    Items[numItems++] = k;

}

void IntList::Print(ostream &output) const {
    for ( int i = 0; i < numItems ; i++ ) {
        output << Items[i] << " ";
    }
    output << endl;
}

int IntList::Length() {
    return numItems;
}