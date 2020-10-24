// Description: An illustration of file processing
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string first_name, last_name;
  int age;
  string file_name;
  // Collect the data.
  cout << "Enter First Name: "; cin >> first_name;
  cout << "Enter Last Name: "; cin >> last_name;
  cout << "Enter Age: "; cin >> age;
  cout << endl << "Enter the name of the file: "; cin >> file_name;
  file_name = "tmp_" + file_name;

  // Create an ofstream called People, open the stream for output.
  ofstream file_out(file_name, ios::out);
  // Write the output to the stream.
  file_out << first_name << endl << last_name << endl << age << endl;
  file_out.close();

  // Create an ifstream called People, open the stream for output.
  ifstream file_in(file_name, ios::in);
  string data;
  // Reading the stream.
  while (file_in >> data) {
    cout << data << endl;
  }
  file_in.close();

  return 0;
}