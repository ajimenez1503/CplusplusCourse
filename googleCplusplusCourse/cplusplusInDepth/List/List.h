// Description: A simple int list class

#include <iostream>
using namespace std;

template <class T>
class List {
  public:
    List();                         // constructor; initialize the list to be empty
    List(T value, int copies);
    ~List();                        // desconstructor
    void AddToEnd(T k);              // add k to the end of the list
    void Print(ostream &output) const; // print the list to output
    int Length();

  private:
    static const int SIZE = 10;      // initial size of the array
    T *Items;                      // Items will point to the dynamically allocated array
    int numItems;                    // number of items currently in the list
    int arraySize;                   // the current size of the array
};


template <class T>
List<T>::List(): Items(new T[SIZE]), numItems(0), arraySize(SIZE) {
}

template <class T>
List<T>::List(T value, int copies): Items(new T[SIZE]), numItems(0), arraySize(SIZE) {
    for (int i = 0; i < copies; i++) {
        AddToEnd(value);
    }
}

template <class T>
List<T>::~List() {
    delete [] Items;
    numItems = 0;
    arraySize = 0;
}

template <class T>
void List<T>::AddToEnd(T k) {
    if (numItems + 1 >= arraySize) {
        arraySize *= 2;
        T *items_new = new T[arraySize];
        for (int i = 0; i < numItems ; i++ ) {
            items_new[i] = Items[i];
        }
        delete [] Items;
        Items = items_new;
    }
    Items[numItems++] = k;
}

template <class T>
void List<T>::Print(ostream &output) const {
    for (int i = 0; i < numItems ; i++ ) {
        output << Items[i] << " ";
    }
    output << endl;
}

template <class T>
int List<T>::Length() {
    return numItems;
}