#include <iostream>
using namespace std;

int main(){
    int n = 8;

    // Loop through each row
    for (int i = 0; i < n; i++) {
        
        // Print leading spaces for pyramid alignment
        for (int j = n-i-1; j >= 0; j--) {
            cout << "  ";
        }

        // Print numbers in increasing order
        for (int k = 0; k <= i; k++) {
            cout << k+1 << " ";
        }

        // Print numbers in decreasing order
        for (int l = i; l > 0; l--) {
            cout << l << " ";
        }

        // Move to the next row
        cout << endl;
     }
    return 0;
}