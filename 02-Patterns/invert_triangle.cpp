#include <iostream>
using namespace std;

int main(){
    int n = 4;

    // Loop for each row
    for (int i = 0; i < n; i++) {
        
        // Print leading spaces to shift the numbers right
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }

        // Print the current row number 'n-i' times
        for (int k = 0; k < n-i; k++) {
            cout << i+1 << " ";
        }

        // Move to the next line
        cout << endl;
    }
    return 0;
}