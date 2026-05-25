/*
Problem: Sum of All Subset XOR Totals
Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
Approach: Bit Masking (Generating all 2^n subsets)
Time Complexity: O(n * 2^n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Total subsets are 2^n. We use bitwise shift (1 << n) for this.
        int totalSubsets = 1 << n;

        // Iterate from 0 to 2^n - 1 to represent each subset
        for(int i = 0; i < totalSubsets; i++) {
            int currentXOR = 0;

            for(int j = 0; j < n; j++) {
                // If the j-th bit of i is set, include nums[j] in current XOR
                if(i & (1 << j)) {
                    currentXOR ^= nums[j];
                }
            }
            totalSum += currentXOR;
        }
        return totalSum;
    }
};

// ---------------- Driver Code ----------------
int main(){
    Solution sol;
    vector<int> vec = {85, 5, 1, 10, 34, 57};
    int sum = sol.subsetXORSum(vec);
    cout << "The total sum of XOR of subsets of an array is " << sum << endl;
    return 0;
}
