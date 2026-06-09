/* Problem: Sort Colors (Dutch National Flag Algorithm) [Leetcode 75]
Course: Apna College DSA (Shradha Didi)
Approach: Three-Pointer In-Place Partitioning (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0;
        int mid = 0;
        int end = nums.size() - 1;

        while (mid <= end) {
            // If element is 0, swap it to the start pointer zone
            if (nums[mid] == 0) {
                swap(nums[mid], nums[st]);
                st++;
                mid++;
            }
            // If element is 2, swap it to the end pointer zone
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[end]);
                end--; // Do not increment mid here; need to check the swapped element
            }
            // If element is 1, it's already in the correct middle zone
            else {
                mid++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    s.sortColors(nums);
    
    cout << "Sorted Colors: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl; // Output: 0 0 1 1 2 2
    
    return 0;
}