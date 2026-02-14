#include <iostream>
using namespace std;

// Function to calculate factorial of a number
// Example: 5! = 5 * 4 * 3 * 2 * 1
int factorial (int n) {
    int facto = 1;
    for (int i = 2; i <= n; i++) {
        facto *= i;
    }
    return facto;
}

// Function to calculate nCr (Combinations)
// Formula: n! / (r! * (n-r)!)
int nCr (int n, int r) {
    // Calling the factorial function for each part of the formula
    return factorial (n) / (factorial (r) * factorial (n-r));
}

int main(){
    // Input values for n and r
    int n = 6;
    int r = 3;

    // Displaying the result
    cout << "nCr = " << nCr (n, r) << endl;
    
    return 0;
}