/*
Problem: Max Consecutive Ones
Link: https://takeuforward.org/plus/dsa/problems/maximum-consecutive-ones
Platform: TUF+ (Striver's A-Z Sheet)
Approach: Iterative Counting (Single Pass)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm> // for max function
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCount1s = 0;
        int tempCount1s = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                tempCount1s += 1;
                // Check maxCount1s is greater than tempCount1s
                maxCount1s = max(maxCount1s, tempCount1s);
            }
            else {
                tempCount1s = 0;
            }
        }
        return maxCount1s;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Max Consecutive Ones: " << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}