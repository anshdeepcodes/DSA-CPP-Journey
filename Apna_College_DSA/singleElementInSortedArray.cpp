/* Problem: Single Element in a Sorted Array (LeetCode 540)
Course: Apna College DSA (Shradha Didi)
Approach: Binary Search using Even-Odd Index Properties (Optimal)
Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases where the single element is at the beginning or end
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // st=1 and end=n-2 ensure mid-1 and mid+1 stay within valid bounds
        int st = 1;
        int end = n - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If mid is not equal to its left and right, it is the single element
            if ((nums[mid - 1] != nums[mid]) && (nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            // If mid is at an EVEN index
            if (mid % 2 == 0) {
                // Even index paired with previous element -> search left
                if (nums[mid - 1] == nums[mid]) {
                    end = mid - 1;
                } 
                // Even index paired with next element -> search right
                else {
                    st = mid + 1;
                }
            } 
            // If mid is at an ODD index
            else {
                // Odd index paired with previous element -> search right
                if (nums[mid - 1] == nums[mid]) {
                    st = mid + 1;
                } 
                // Odd index paired with next element -> search left
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8}; 
    
    cout << "The single non-duplicate element is: " << s.singleNonDuplicate(nums) << endl; // Output: 2
    return 0;
}