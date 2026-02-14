#include <iostream>
using namespace std;

int main(){
    int n = 4;

    // Outer loop to handle the number of rows
    for (int i = 0; i <= n; i++) {
        
        // Inner loop to print numbers in descending order
        // Starts from i+1 and goes down to 1
        for (int j = i+1; j > 0; j--) {
            cout << j << " ";
        }
        
        // Move to the next line after each row
        cout << endl;
    }
    return 0;
}