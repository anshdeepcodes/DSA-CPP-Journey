/* Problem: Permutation in String
Platform: LeetCode 567 (Apna College)
Approach: Brute Force + Frequency Count
Time Complexity: O((N - M + 1) * (M + 26))
            ≈ O(N * M)
Space Complexity: O(1) - Fixed-size frequency arrays
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Compare the frequency of both strings
    bool isSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();
        int targetFreq[26] = {0};

        // Store the frequency of the pattern
        for (char ch : s1) {
            targetFreq[ch - 'a']++;
        }

        // Check every possible window
        for (int i = 0; i < s2.size(); i++) {
            int windowFreq[26] = {0};

            int windowLength = 0;
            int j = i;

            // Build the current window
            while (windowLength < windowSize && j < s2.size()) {
                windowFreq[s2[j] - 'a']++;
                windowLength++;
                j++;
            }

            // Match the current window with the pattern
            if (isSame(targetFreq, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << boolalpha << s.checkInclusion(s1, s2);

    return 0;
}