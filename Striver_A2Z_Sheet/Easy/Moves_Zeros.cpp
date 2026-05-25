/*
Problem: Move Zeroes to End
Approach: Two-Pointer (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer to keep track of the next non-zero position

        // Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {
            
            // If we find a non-zero element
            if (nums[i] != 0) {
                // Swap it with the element at index j
                swap(nums[i], nums[j]);
                
                // Move the pointer for the next non-zero element
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> vec = {0, 1, 0, 3, 12};

    sol.moveZeroes(vec);

    cout << "Array after moving zeroes: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}