/*
Problem: Find the Second Largest Element in an Array
Link: https://takeuforward.org/plus/dsa/problems/second-largest-element
Platform: TUF+
Approach: Single Pass (Keeping track of Largest and Second Largest)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int getSecondLargest(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return -1; // If only 1 element in array
    
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            // Case 1: If current element is greater than largest
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            }
            // Case 2: If current element is smaller than largest but greater than secondLargest
            else if (nums[i] < largest && nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};


int main(){
    Solution sol;
    vector<int> vec = {12, 35, 1, 10, 34, 1};
    int result = sol.getSecondLargest(vec);
    cout << "The 2nd Maximum Element of array is " << result << endl;
    return 0;
}