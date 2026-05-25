/*
Problem: Left Rotate Array by One Position
Source: TUF+ / Striver Sheet
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void leftRotate(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return; // Case: Empty or single element array

        // Step 1: Store the first element in temporary variable
        int temp = nums[0];

        // Step 2: Shift all elements one position to the left
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }

        // Step 3: Put the first element at the last index
        nums[n - 1] = temp;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    Solution sol;

    sol.leftRotate(vec);

    // Print the rotated array
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}