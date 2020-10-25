// Description: A simple book class.

#include <iostream>
using namespace std;

class Book
{
private:
    string code_;
    double cost_;
    int inventory_;
    bool required_;
    void set(string code, double cost, int inventory, bool required);

public:

    void fill();
    void display();
};

void Book::set(string code, double cost, int inventory, bool required)
{
    code_ = code;
    cost_ = cost;
    inventory_ = inventory;
    required_ = required;
}

void Book::fill()
{
    string code;
    double cost;
    int inventory;
    char required;

    cout << "***************************************************" << endl;
    cout << "\t Enter the code: ";
    cin >> code;
    cout << "\t Enter the cost: ";
    cin >> cost;
    cout << "\t Enter the inventory: ";
    cin >> inventory;
    cout << "\t Is it required ('Y' for YES, 'N' for NO: ";
    cin >> required;
    set(code, cost, inventory, required == 'Y' || required == 'y');
    cout << endl;
}

void Book::display()
{
    cout << "***************************************************" << endl
         << "\t code: " << code_ << endl
         << "\t cost: " << cost_ << "$" << endl
         << "\t inventory: " << inventory_ << endl
         << "\t required: " << (required_ ? "YES" : "NO") << endl;
}

int main()
{
    Book book;
    book.fill();
    book.display();
}