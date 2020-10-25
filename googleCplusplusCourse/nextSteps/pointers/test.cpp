// Description: Pointers examples
#include <iostream>

using namespace std;

void example1() {
    int my_int = 46; // Declare a normal integer variable.
                 // Set it to equal 46.

    // Declare a pointer and make it point to the variable my_int
    // by using the address-of operator.
    int *my_pointer = &my_int;

    cout << my_int << endl; // Displays 46.

    *my_pointer = 107; // Derefence and modify the variable.

    cout << my_int << endl; // Displays 107.
    cout << *my_pointer << endl; // Also 107.
}

void example2() {
    int *ptr1; // Declare a pointer to int.
    ptr1 = new int; // Reserve storage and point to it.
    float *ptr2 = new float; // Do it all in one statement.

    delete ptr1; // Free the storage.
    delete ptr2;
}

void duplicate(int& a, int& b, int& c) {
  a *= 2;
  b *= 2;
  c *= 2;
}
void example3() {
  int x = 1, y = 3, z = 7;
  duplicate(x, y, z);
  // The following outputs: x=2, y=6, z=14.
  cout << "x="<< x << ", y="<< y << ", z="<< z << endl;
}

void DoIt(int &foo, int goo) {
    foo = goo + 3;
    goo = foo + 4;
    foo = goo + 3;
    goo = foo;
}

void example4() {
    int *foo = new int;
    *foo = 1;
    int *goo = new int;
    *goo = 3;

    *foo = *goo + 3; // *foo == 6
    foo = goo;
    *goo = 5; // *foo == 5 && *goo == 5
    *foo = *goo + *foo;  // *foo == 10 && *goo == 10
    DoIt(*foo, *goo); // *foo == 20 && *goo == 20
    cout << (*foo) << endl;
}

int main() {
    example1();
    example2();
    example3();
    example4();
}