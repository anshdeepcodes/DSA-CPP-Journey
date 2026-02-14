#include <iostream>
using namespace std;

int main() {
    int n = 10;

    // --- Print the top half of the hollow diamond ---
    for (int i = 0; i < n; i++) {
        // Leading spaces for alignment
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        
        // Print the first star
        cout << "*";

        // Internal spaces between the two stars
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << " ";
        }

        // Print the second star (skip for the very first row)
        if (i > 0)
            cout << "*";

        cout << endl;
    }

    // --- Print the bottom half of the hollow diamond ---
    for (int i = 0; i < n - 1; i++) {
        // Leading spaces for inverted alignment
        for (int j = 0; j <= i; j++) {
            cout << " ";
        }

        // Print the first star
        cout << "*";

        // Internal spaces that decrease as we go down
        for (int j = 2 * (n - i) - 5; j > 0; j--) {
            cout << " ";
        }

        // Print the second star (skip for the very last row)
        if (i != n - 2) cout << "*";
        
        cout << endl;
    }

    return 0;
}