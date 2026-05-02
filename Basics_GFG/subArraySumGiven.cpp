/* 
Problem: Subarray with Given Sum
Platform: GeeksforGeeks (Medium/Basic logic)
Approach: Sliding Window / Two Pointers
Time Complexity: O(N)
Space Complexity: O(1).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0, right = 0;
        int n = arr.size();
        int current_sum = 0;
        
        while (right < n) {
            // Add current element to the sum
            current_sum += arr[right];
            
            // If current_sum exceeds the target, shrink the window from the left
            while (left <= right && current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            // Check if we found the target sum
            if (current_sum == target && left <= right) {
                // GFG expects 1-based indexing
                return {left + 1, right + 1};
            }
            
            right++;
        }
        
        // If no subarray is found, return -1
        return {-1};
    }
};

// Driver Code to test the logic
int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    
    vector<int> result = ob.subarraySum(arr, target);
    
    if (result[0] == -1) {
        cout << "No subarray found" << endl;
    } else {
        cout << "Subarray found between indexes: " << result[0] << " and " << result[1] << endl;
    }

    return 0;
}