/*
Problem: Rotate Array by k (Left and Right)
Link: https://takeuforward.org/plus/dsa/problems/left-rotate-array
Platform: TUF+ / LeetCode
Approach: Reversal Algorithm (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm> // For swap
using namespace std;

class Solution {
public:
    // Helper function to reverse elements from start to end index
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Unified function to handle both Left and Right rotations
    void rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();
        if (n <= 1) return; // Edge case: array with 0 or 1 element
        
        k = k % n; // Handles cases where k > n
        if (k == 0) return;

        if (direction == "left") {
            // Left Rotation Logic:
            reverseArray(nums, 0, k - 1);    // Part 1
            reverseArray(nums, k, n - 1);    // Part 2
            reverseArray(nums, 0, n - 1);    // Whole Array
        } 
        else if (direction == "right") {
            // Right Rotation Logic:
            reverseArray(nums, 0, n - 1);    // Whole Array
            reverseArray(nums, 0, k - 1);    // Part 1
            reverseArray(nums, k, n - 1);    // Part 2
        }
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1, 2, 3, 4, 5};
    int k = 2;
    
    // Choose "left" or "right"
    string dir = "left"; 
    
    sol.rotateArray(vec, k, dir);

    // Output the result
    cout << "Array after " << dir << " rotation: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}