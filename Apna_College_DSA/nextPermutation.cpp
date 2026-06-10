/* Problem: Next Permutation (LeetCode 31)
Course: Apna College DSA (Shradha Didi)
Approach: Lexicographical Next Permutation (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        // Step 1: Find the first decreasing element from the back
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Edge Case: If no pivot found, array is reverse-sorted. Reset to first permutation.
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the largest rightmost element from pivot
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 3: Reverse the sequence after the pivot to get the smallest possible order
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3}; // Next permutation should be 1, 3, 2

    s.nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl; // Output: 1 3 2

    return 0;
}