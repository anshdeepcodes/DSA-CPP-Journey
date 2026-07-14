/* Problem: Valid Palindrome
Platform: LeetCode 125 / GFG Variant
Approach: Two Pointers
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Ignore non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution s;

    string str = "A man, a plan, a canal: Panama";

    cout << boolalpha << s.isPalindrome(str);

    return 0;
}