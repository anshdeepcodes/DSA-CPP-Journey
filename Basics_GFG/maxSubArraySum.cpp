/* 
Problem: Kadane's Algorithm (Max Subarray Sum)
Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
Approach: Iterative (Kadane's)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            maxSum = max(currSum, maxSum);
            
            // If current sum becomes -ve, reset it to 0
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

// Driver Code
int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, -2, 5};
    cout << "Maximum Subarray Sum: " << ob.maxSubarraySum(arr) << endl;
    return 0;
}