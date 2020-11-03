// Description: A simple book class.

#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List<int> L1;  // L's no-arg constructor function is called
    for (int i = 0; i< 20; i++) {
        L1.AddToEnd(i);
        L1.Print(cout);
    }
    cout << " Length" << L1.Length() << endl;

    List<double> L2(5.5, 25);
    L2.Print(cout);
    cout << " Length" << L2.Length() << endl;
}