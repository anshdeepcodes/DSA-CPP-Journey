/*
Problem: Find the Missing Number in an Array
Link: https://takeuforward.org/plus/dsa/problems/find-the-missing-number-in-an-array
Platform: TUF+ (Striver's A-Z Sheet)
Approach: Sum Formula (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Formula to find sum of first N natural numbers
        int totalSum = n * (n + 1) / 2;
        int numsSum = 0;

        // Calculating the sum of elements present in the array
        for (int i = 0; i < n; i++) {
            numsSum = numsSum + nums[i];
        }

        // The difference is the missing number
        return (totalSum - numsSum);
    }
};

int main() {
    Solution sol;
    // Example: n=5, so numbers should be 0 to 5. Sum should be 15.
    vector<int> vec = {0, 2, 5, 1, 4}; 
    int missingNum = sol.missingNumber(vec);
    cout << "The Missing Element of array is " << missingNum << endl;
    return 0;
}