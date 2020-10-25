// Description: This is a number analogy to a famous card trick

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int input_number_ABC = 0, input_number_CAB = 0, input_number_BCA = 0;
  string str_input_number;

  // Enter number
  cout << "Enter a number of 3 digits" << endl;
  cin >> str_input_number;

  // Convert string to int
  input_number_ABC = stoi(str_input_number);
  string tmp = str_input_number.substr(2,1) + str_input_number.substr(0,1) + str_input_number.substr(1,1);
  input_number_CAB = stoi(tmp);
  tmp = str_input_number.substr(1,1) + str_input_number.substr(2,1) + str_input_number.substr(0,1);
  input_number_BCA = stoi(tmp);

  // Check number between 100 and 999
  if (input_number_ABC < 100 || input_number_ABC > 999) {
    cout << "The number " << input_number_ABC << " should be between 100 and 999 " << endl;
    return 0;
  }

  // Calculate remainders
  vector<int> remainders(3);
  remainders[0] = input_number_ABC % 11;
  remainders[1] = input_number_CAB % 11;
  remainders[3] = input_number_BCA % 11;

  int A = 0,B = 0, C = 0;
  A = remainders[0] + remainders[1];
  if (A % 2 == 0) {
    if (A + 11 < 20) {
      A += 11;
    } else {
      A -= 11;
    }
  }
  B = remainders[1] + remainders[2];
  if (B % 2 == 0) {
    if (B + 11 < 20) {
      B += 11;
    } else {
      B -= 11;
    }
  }
  C = remainders[0] + remainders[2];
  if (C % 2 == 0) {
    if (C + 11 < 20) {
      C += 11;
    } else {
      C -= 11;
    }
  }

  cout << A / 2 << B / 2 << C / 2;
  return 0;
}