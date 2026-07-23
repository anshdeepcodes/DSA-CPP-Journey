/* Problem: String Compression
Platform: LeetCode 443 (Apna College)
Approach: Two Pointers
Time Complexity: O(N) - Traverse the array once
Space Complexity: O(1) - In-place compression (excluding temporary string for count)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while (i < n && chars[i] == currentChar) {
                count++;
                i++;
            }

            chars[write++] = currentChar;

            // Write the count only when needed
            if (count > 1) {
                string freq = to_string(count);
                for (char digit : freq) {
                    chars[write++] = digit;
                }
            }
        }

        chars.resize(write);
        return write;
    }
};

int main() {
    Solution s;

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int newLength = s.compress(chars);

    cout << "Compressed Length: " << newLength << "\n";
    cout << "Compressed Array: ";

    for (char ch : chars) {
        cout << ch << " ";
    }

    return 0;
}