/* Problem: Squares of a Sorted Array
Platform: LeetCode 977
Approach: Two Pointers
Time Complexity: O(N) - Single pass from both ends
Space Complexity: O(N) - Output array
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        vector<int> ans(n);
        int index = n - 1;

        // Fill the result from the end with the larger square
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare >= rightSquare) {
                ans[index] = leftSquare;
                left++;
            } else {
                ans[index] = rightSquare;
                right--;
            }

            index--;
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-7, -3, 2, 3, 11};

    vector<int> ans = s.sortedSquares(nums);

    cout << "Sorted Squares: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}