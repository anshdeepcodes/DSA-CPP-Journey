/*
Problem: Linear Search
Link: https://takeuforward.org/plus/dsa/problems/linear-search?
Platform: TUF+
Approach: Linear Scan (One-pass traversal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {

        // Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {
            
            // Check the current element is target or not
            if (nums[i] == target) {
                return i;
            }
        }
        return -1; // If target is not in nums
    }
};

int main(){
    Solution sol;
    vector<int> arr = {-2,-1,0,0,1,1,2,3};
    int target = 1;

    int targetIndex = sol.linearSearch(arr, target);

    if (targetIndex != -1) {
        cout << "The first occurence of " << target << " in array is at index " << targetIndex << endl;
    } else {
        cout << "The value " << target << " does not occur in the array" << endl;
    }
    return 0;
}