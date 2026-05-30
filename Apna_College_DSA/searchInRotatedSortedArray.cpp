/* Problem: Search in Rotated Sorted Array (LeetCode 33)
Course: Apna College DSA (Shradha Didi)
Approach: Modified Binary Search (Identify Sorted Half)
Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Case 1: Target found at mid
            if (target == nums[mid]) {
                return mid;
            } 
            
            // Case 2: Check if Left Half is sorted
            if (nums[st] <= nums[mid]) {
                // Check if target lies within the sorted left half range
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1; // Narrow down search to left half
                } else {
                    st = mid + 1;  // Explore right half
                }
            }
            // Case 3: Right Half must be sorted
            else {
                // Check if target lies within the sorted right half range
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;  // Narrow down search to right half
                } else {
                    end = mid - 1; // Explore left half
                }
            }            
        }
        
        // Target not found in the array
        return -1;
    }
};

int main() {
    Solution s;
    // Rotated sorted array example
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; 
    int target = 0;
    
    int result = s.search(nums, target);
    
    if (result != -1) {
        cout << "Target element " << target << " found at index: " << result << endl; // Output: 4
    } 
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}