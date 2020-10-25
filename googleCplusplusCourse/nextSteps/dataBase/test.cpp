// Description: The class for a Composer record.
// The default ranking is 10 which is the lowest possible.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Notice we use const in C++ instead of #define.
const int kDefaultRanking = 10;

class Composer
{
public:
    // Constructor
    Composer();
    // Here is the destructor which has the same name as the class
    // and is preceded by ~. It is called when an object is destroyed
    // either by deletion, or when the object is on the stack and
    // the method ends.
    ~Composer();

    // Accessors and Mutators
    void set_first_name(string in_first_name);
    string first_name() const;
    void set_last_name(string in_last_name);
    string last_name() const;
    int ranking() const;

    // Methods
    // This method increases a composer's rank by increment.
    void Promote(int increment);
    // This method decreases a composer's rank by decrement.
    void Demote(int decrement);
    // This method displays all the attributes of a composer.
    void Display() const;

    bool operator < (const Composer& composer) const;

private:
    string first_name_;
    string last_name_;
    int ranking_;
};

Composer::Composer()
{
    first_name_ = "";
    last_name_ = "";
    ranking_ = 0;
}

Composer::~Composer()
{
    first_name_.clear();
    last_name_.clear();
    ranking_ = 0;
}

void Composer::set_first_name(string in_first_name)
{
    first_name_ = in_first_name;
}

string Composer::first_name() const
{
    return first_name_;
}

void Composer::set_last_name(string in_last_name)
{
    last_name_ = in_last_name;
}

string Composer::last_name() const
{
    return last_name_;
}

int Composer::ranking() const
{
    return ranking_;
}

void Composer::Promote(int increment)
{
    ranking_ += increment;
}

void Composer::Demote(int decrement)
{
    ranking_ -= decrement;
}

void Composer::Display() const
{
    cout << "***************************************************" << endl
         << "\t first_name: " << first_name_ << endl
         << "\t last_name: " << last_name_ << endl
         << "\t ranking: " << ranking_ << endl;
}

bool Composer::operator < (const Composer& composer) const
{
    return (ranking_ < composer.ranking());
}

// Our database holds 3 composers, and no more.
const int kMaxComposers = 3;

// Description: Class for a database of Composer records.
class Database
{
public:
    Database();
    ~Database();

    // Add a new composer using operations in the Composer class.
    // For convenience, we return a reference (pointer) to the new record.
    Composer &AddComposer(string in_first_name, string in_last_name);
    // Search for a composer based on last name. Return a reference to the
    // found record.
    Composer &GetComposer(string in_last_name);
    // Display all composers in the database.
    void DisplayAll() const;
    // Sort database records by rank and then display all.
    void DisplayByRank();

private:
    // Store the individual records in an array.
    vector<Composer> composers_;
};

Database::Database()
{
}

Database::~Database()
{
    composers_.clear();
}

Composer &Database::AddComposer(string in_first_name, string in_last_name)
{
    if (composers_.size() >= kMaxComposers) {
        cout << "Reach the maximum number of composers: " << kMaxComposers << endl;
        throw "Reach the maximum number ";
    }
    Composer composer;
    composer.set_first_name(in_first_name);
    composer.set_last_name(in_last_name);
    composers_.push_back(composer);
    return composers_.back();
}

Composer &Database::GetComposer(string in_last_name) {
    for (unsigned int i = 0; i < composers_.size(); i++) {
        if (composers_[i].last_name() == in_last_name) {
            return composers_[i];
        }
    }
    throw "Composer with that name does not exists";
}

void Database::DisplayAll() const
{
    for (const auto &value : composers_)
    {
        value.Display();
    }
}

void Database::DisplayByRank()
{
    sort(composers_.begin(), composers_.end());
    for (const auto &value : composers_)
    {
        value.Display();
    }
}

int main()
{
    Database myDB;

    // Remember that AddComposer returns a reference to the new record.
    try {
        Composer &comp1 = myDB.AddComposer("Ludwig van", "Beethoven");
        comp1.Promote(7);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        Composer &comp2 = myDB.AddComposer("Johann Sebastian", "Bach");
        comp2.Promote(11);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        Composer &comp3 = myDB.AddComposer("Wolfgang Amadeus", "Mozart");
        comp3.Promote(2);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        Composer &comp4 = myDB.AddComposer("Wolfgang Amadeus2", "Mozart2");
        comp4.Promote(2);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    cout << "All Composers: " << endl << endl;
    myDB.DisplayAll();
    cout << "All Composers sorted by ranking: " << endl << endl;
    myDB.DisplayByRank();

    try {
        cout << "Display Composer (Mozart): " << endl;
        Composer &comp5 = myDB.GetComposer("Mozart");
        comp5.Display();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        cout << "Display Composer (Mozart4): " << endl;
        Composer &comp6 = myDB.GetComposer("Mozart4");
        comp6.Display();
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}