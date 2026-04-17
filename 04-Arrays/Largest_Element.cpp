/*
Problem: Find the Largest Element in an Array
Link: https://takeuforward.org/plus/dsa/problems/largest-element
Platform: TUF+ (Striver's A-Z Sheet)
Approach: Linear Scan (One-pass traversal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize max with the first element
        int maxElement = nums[0]; 
        
        // Traverse the array from the second element
        for (int i = 1; i < n; i++) {
            // Update maxElement if current element is larger
            if (nums[i] > maxElement) {
                maxElement = nums[i];
            }
        }
        
        return maxElement;
    }
};
