/*
Problem: Count digits in a number
Platform: GFG (Basic)
Time Complexity: O(log10(N))
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int main() {
    int num = 12345;
    cout << "Number of digits: " << countDigits(num) << endl;
    return 0;
}