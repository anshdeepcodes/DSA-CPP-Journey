#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // A number is power of 2 if it has only one set bit
    if (num > 0 && (num & (num - 1)) == 0) {
        cout << num << " is power of 2" << endl;
    } else {
        cout << "Not a power of 2";
    }

    return 0;
}