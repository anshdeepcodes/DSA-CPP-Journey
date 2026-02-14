#include <iostream>
using namespace std;

int main() {
    int n = 10; // Number of rows for the pattern

    // --- Upper part of the butterfly pattern ---
    for (int i = 0; i < n; i++) {
        // Left side stars
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        // Middle spaces
        for (int j = 0; j < 2 * (n - 1 - i); j++) {
            cout << "  ";
        }

        // Right side stars
        for (int j = 0; j <= i; j++) {
            if (j != 0) cout << " ";
            cout << "*";
        }
        cout << endl;
    }

    // --- Lower part of the butterfly pattern (inverted) ---
    for (int i = n - 1; i >= 0; i--) {
        // Left side stars
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }

        // Middle spaces
        for (int j = 0; j < 2 * (n - 1 - i); j++) {
            cout << "  ";
        }

        // Right side stars
        for (int j = 0; j <= i; j++) {
            if (j != 0) cout << " ";
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}