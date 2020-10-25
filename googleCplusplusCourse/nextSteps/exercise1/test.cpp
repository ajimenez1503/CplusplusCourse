// Description: A simple time class.

#include <iostream>
#include <math.h>

using namespace std;


bool isSumOfInteger(int x)
{
    int sum = 0;
    for (int i = 1; sum < x; i++) {
        sum += i;
    }
    return sum == x;
}


bool isPerfectSquare(int x)
{
  // Find floating point value of
  // square root of x.
  long double sr = sqrt(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

int main()
{
    int i = 0;
    while(true) {
        if (isPerfectSquare(i) && isSumOfInteger(i)) {
            cout << i << " is perfect square" << endl;
        }
        i++;
    }
}