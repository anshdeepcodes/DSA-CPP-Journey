/*
Problem: Longest Subarray with Sum K
Link: https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k-positives
Approach: Two Pointers / Sliding Window
Time Complexity: O(2N) ≈ O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        long long sum = 0; // To avoid sum overflow
        int maxLen = 0;
        int n = nums.size();

        while (right < n) {
            sum += nums[right];

            // If sum becomes greater than k, move left pointer to shrink window
            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }

            // If sum equals k, update length
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;
    cout << "Longest Subarray Length: " << sol.longestSubarray(nums, k) << endl;
    return 0;
}