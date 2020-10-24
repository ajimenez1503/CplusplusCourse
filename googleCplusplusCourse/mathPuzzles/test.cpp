// Description: Computes combinations of animals under constraints
// Horses cost $10, pigs cost $3, and rabbits are only $0.50. A farmer buys 100
// animals for $100, How many of each animal did he buy?
// 10X + 3Y + 0.5 Z = 100
// X + Y + Z = 100

#include <iostream>

using namespace std;

int main() {
    for (int x = 0;x <= 11; x++) {
        for (int y = 0; y <= 33; y++) {
            for (int z = 0; z <= 100; z++) {
                if (x + y + z == 100 && 10 * x + 3 * y + 0.5 * z == 100) {
                    cout << x << " X, "<< y << " Y, " << z << " Z" << endl;
                }
            }
        }
    }

}