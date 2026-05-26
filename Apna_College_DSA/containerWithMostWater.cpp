/* Problem: Container With Most Water (LeetCode 11)
Course: Apna College DSA (Shradha Didi)
Approach: Two-Pointer Approach (Optimal)
Time Complexity: O(N) - Linear scan using left and right pointers
Space Complexity: O(1) - Constant auxiliary space
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0;                         // Left Pointer
        int rp = height.size() - 1;         // Right Pointer
        
        while (lp < rp) {
            int wdth = rp - lp;             // Width between two vertical lines
            int ht = min(height[lp], height[rp]); // Height is limited by the shorter line
            int currWater = ht * wdth;      // Area calculation
            
            maxWater = max(maxWater, currWater); // Update maximum water stored so far

            // Move the pointer pointing to the shorter line inward
            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << "Max Water Container Area: " << s.maxArea(height) << endl; // Output: 49
    return 0;
}