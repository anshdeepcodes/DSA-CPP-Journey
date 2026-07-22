/* Problem: Reverse Words in a String
Platform: LeetCode 151 (Apna College)
Approach: Reverse Entire String + Reverse Individual Words
Time Complexity: O(N) - Each character is processed a constant number of times
Space Complexity: O(N) - Result string
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        // Reverse the entire string first
        reverse(s.begin(), s.end());

        int i = 0;

        while (i < s.size()) {
            string word = "";

            // Collect the current word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Restore the original order of the current word
            reverse(word.begin(), word.end());

            // Skip extra spaces in the output
            if (!word.empty()) {
                ans += " " + word;
            }

            i++;
        }

        // Remove the leading space
        return ans.substr(1);
    }
};

int main() {
    Solution s;

    string str = "  the sky   is blue  ";

    cout << s.reverseWords(str);

    return 0;
}