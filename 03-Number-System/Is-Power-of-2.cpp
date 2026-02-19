#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // A number is power of 2 if it has only one set bit
    if (n > 0 && (n & (n - 1)) == 0) {
        cout << n << " is power of 2" << endl;
    } else {
        cout << "Not a power of 2";
    }

    return 0;
}