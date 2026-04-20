/*
Problem: Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array
Platform: LeetCode
Approach: Two-pointer technique
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Handle empty array case

        int k = 1; // Index to place next unique element

        // Start loop from second element
        for (int i = 1; i < n; i++) {

            // If current element is different from previous one, it's unique
            if (nums[i] != nums[i-1]) {

                // Place the unique element at index k
                nums[k] = nums[i];

                // Move k to next position
                k++;
            }
        }

        return k;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {-2,-1,0,0,1,1,2,3};

    int uniqueCount = sol.removeDuplicates(vec);

    cout << "Number of unique elements" << uniqueCount << endl;

    //Print only unique elements up to index k
    for (int i = 0; i < uniqueCount; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}