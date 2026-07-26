/* Problem: Reverse Integer
Platform: LeetCode 7
Approach: Reverse Digits
Time Complexity: O(log10(N)) - Process each digit once 
Space Complexity: O(1) - Constant auxiliary space
*/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversedNum = 0;

        while (x != 0) {
            int digit = x % 10;

            // Prevent 32-bit integer overflow
            if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && digit > 7))
                return 0;

            if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && digit < -8))
                return 0;

            reversedNum = reversedNum * 10 + digit;
            x /= 10;
        }

        return reversedNum;
    }
};

int main() {
    Solution s;

    int num = 214786;

    cout << "The reverse of " << num << " is " << s.reverse(num) << endl;

    return 0;
}