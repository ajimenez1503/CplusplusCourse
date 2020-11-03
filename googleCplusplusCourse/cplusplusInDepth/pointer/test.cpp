// Description: A simple book class.

#include <iostream>
using namespace std;

void Unknown(int *p, int num);
void HardToFollow(int *p, int q, int *num);

void Unknown(int *p, int num) {
  int *q;

  q = &num;
  *p = *q + 2;
  num = 7;
}

void HardToFollow(int *p, int q, int *num) { // *p = 2, q = 1, *m = 3
  *p = q + *num; // *p = 4, q = 1, *m = 3
  *num = q;  // *p = 4, q = 1, *m = 1
  num = p; // *p = 4, q = 1, *m = 4
  p = &q; // *p = 1, q = 1, *m = 4
  Unknown(num, *p); // *p = 3, q = 1, *m = 1
}

int main() {
  int *q;
  int trouble[3];

  trouble[0] = 1;
  q = &trouble[1];
  *q = 2;
  trouble[2] = 3; // *q = 2, {1, 2, 3}

  HardToFollow(q, trouble[0], &trouble[2]); // *q = 3, {1, 3, 1}
  Unknown(&trouble[0], *q); // *q = 3, {5, 3, 1}

  cout << *q << " " << trouble[0] << " " << trouble[2];
}