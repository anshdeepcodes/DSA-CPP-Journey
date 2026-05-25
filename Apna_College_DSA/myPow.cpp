/* Problem: Pow(x, n) - Implement x raised to the power n
Course: Apna College DSA (Shradha Didi)
Approach: Binary Exponentiation (Optimal)
Time Complexity: O(log n) - Dividing power by 2 in each step
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            double ans = 1;
            
            // Base Edge Cases
            if (n == 0) return 1.0;
            if (x == 0) return 0.0;
            if (x == 1) return 1.0;
            if (x == -1 && n % 2 == 0) return 1.0;
            if (x == -1 && n % 2 != 0) return -1.0;
            
            // Using long to prevent integer overflow when n = INT_MIN
            long binForm = n;

            // Handling negative powers
            if (n < 0) {
                binForm = -binForm;
                x = 1.0 / x;
            }

            // Binary Exponentiation Loop
            while (binForm > 0) {
                if (binForm % 2 == 1) { // If bit is set (odd power)
                    ans *= x;
                }
                x *= x;        // Square the base
                binForm /= 2;  // Right shift the binary form (divide power by 2)
            }
            return ans;
        }
};

int main(){
    Solution s;
    cout << "5^3 = " << s.myPow(5, 3) << endl;    // Output: 125
    cout << "2^-2 = " << s.myPow(2, -2) << endl;  // Output: 0.25
    return 0;
}