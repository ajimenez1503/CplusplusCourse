// Description: Euclidean algorithm

#include <iostream>
#include <algorithm>
using namespace std;

// A recursive version of Euclid's algorithm
int gcb_recursive(int a, int b) {

    if (b == 0) {
        return a;
    } else {
        return gcb_recursive(b, a % b);
    }
}

// A non-recursive version of Euclid's algorithm
int gcb_non_recursive (int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return(a);
}

int main() {
  cout << "gcb(12, 18) = " << gcb_non_recursive(12, 18) << " = " << gcb_recursive(12, 18) << endl;
  cout << "gcb(4, 14) = " << gcb_non_recursive(4, 14) << " = " << gcb_recursive(4, 14) << endl;

  return 0;
}