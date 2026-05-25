/*
Problem: Find the number that appears once, and others twice
Link: https://takeuforward.org/plus/dsa/problems/find-the-number-that-appears-once-and-the-other-numbers-twice
Platform: TUF+ (Striver's A-Z Sheet)
Approach: XOR Operator (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniqueInt = 0;

        // XOR of all numbers of array
        for (int val : nums) {
            uniqueInt ^= val;
        }
        
        return uniqueInt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The number that appears once is: " << sol.singleNumber(nums) << endl;
    return 0;
}