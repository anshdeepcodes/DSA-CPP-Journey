/*
Problem: Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated
Platform: LeetCode
Approach: Counting breaks in sorted order using modulo (Single Pass)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        int n = nums.size();
        int count = 0; // To store the number of breaks in sorting

        for (int i = 0; i < n; i++) {
            // Check if the current element is greater than the next element
            // (i + 1) % n helps to compare the last element with the first one
            if (nums[i] > nums[(i + 1) % n]) {
                count++; // Increase count if a break is found
            }
        }

        // For a sorted or rotated array, there should be at most 1 break
        return (count <= 1);
    }
};

int main() {
    Solution sol;
    vector<int> vec = {3, 4, 5, 1, 2};

    // Print true/false based on the result
    if (sol.check(vec)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}