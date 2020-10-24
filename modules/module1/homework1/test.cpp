#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

template <class T>
inline void sum(T &p, vector<T> &d)
{
    p = T(); // Reset value
    for (unsigned int i = 0; i < d.size(); ++i)
        p += d[i];
}

int main(void)
{
    int accum = 0;
    vector<int> data(N);

    for (unsigned int i = 0; i < data.size(); ++i)
        data[i] = i;
    sum(accum, data);
    cout << "sum is " << accum << endl;

    return 0;
}
