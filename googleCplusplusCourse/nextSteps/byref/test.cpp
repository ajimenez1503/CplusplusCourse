// Description: A program to illustrate passing parameters
// by value and by reference.
#include <iostream>
using namespace std;

// Speed is passed by reference, and amount by value
void accelerate(int& speed, int amount) {
  speed = speed + amount;
}

int main(void) {
  int current_speed = 30;
  int accel_amount;

  cout << "current speed: " << current_speed << endl;
  cout << "Accelerate by how much?" << endl;
  cin >> accel_amount;

  accelerate(current_speed, accel_amount);
  cout << "accelerated speed: " << current_speed << endl;
}