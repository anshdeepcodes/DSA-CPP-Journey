/* Problem: Longest Even Odd Subarray With Threshold
Platform: LeetCode 2760 / GFG Variant
Approach: Sliding Window + Two Pointers
Time Complexity: O(N) - Each element is visited at most once
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_len = 0;
        int i = 0;
        
        while (i < n) {
            // Subarray must start with an even number and be within the threshold
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int j = i + 1;
                
                // Expand the window as long as alternating parity and threshold constraints are met
                while (j < n && nums[j] <= threshold && (nums[j] % 2 != nums[j - 1] % 2)) {
                    j++;
                }
                
                max_len = max(max_len, j - i);
                
                // Continue from the end of the current valid subarray
                i = j;
            } else {
                i++;
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 5, 4};
    int threshold = 5;
    
    int result = s.longestAlternatingSubarray(nums, threshold);
    cout << "Length of longest alternating subarray: " << result << endl; // Output: 3 (Subarray: [2, 5, 4])
    
    return 0;
}