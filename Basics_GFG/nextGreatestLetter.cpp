/* Problem: Find Smallest Letter Greater Than Target
Platform: LeetCode 744
Approach: Binary Search
Time Complexity: O(log N) - Binary search on the sorted array
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;

        // Default to the first letter to handle the wrap-around case
        char ans = letters[0];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Found a valid letter; search left for a better candidate
            if (letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<char> letters = {'c', 'f', 'j'};
    char target = 'd';

    cout << "Next greatest letter: "
         << s.nextGreatestLetter(letters, target);

    return 0;
}