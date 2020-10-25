// Description:
// Generate a random number between 0 and 100.
// The player must guess the secret number.
// The program provides hints like "that's too high" or "that's too low" until
// the player finally guesses the secret number.

#include <iostream>
#include <limits>
#include <random>
#include <ctime>
using namespace std;

int main() {
  int secret = 0;
  int input_var = 0;
  int number_of_tries = 0;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  secret = rand() % 100;

  do {
    number_of_tries++;
    cout << "Enter a number between 0-100 (-1 = quit): ";
    // The following line accepts input from the keyboard into
    // variable input_var.
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of input_var) is entered.
    if (!(cin >> input_var)) {
      cout << "You entered a non-numeric. Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(
          std::numeric_limits<std::streamsize>::max(),
          '\n');
    } else if (input_var == secret) {
      cout << "You entered the correct number " << input_var << endl;
      cout << "You needed "<< number_of_tries << " tries" << endl;
      break;
    } else if (input_var != -1) {
        cout << "You entered " << input_var;
        if (input_var > secret) {
            cout << ". That's too high" << endl;
        } else {
            cout << ". That's too low" << endl;
        }
    }
  } while (input_var != -1);

  return 0;
}